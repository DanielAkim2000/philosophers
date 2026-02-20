#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

/* ===================== UTILS ===================== */

static int	ft_atoi(const char *s)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i] >= '0' && s[i] <= '9')
		r = r * 10 + (s[i++] - '0');
	return (r);
}

static long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static void	ft_sleep(long ms)
{
	long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(500);
}

static void	fatal(char *msg)
{
	write(2, msg, 1);
	write(2, "\n", 1);
	exit(1);
}

/* ===================== STRUCTS ===================== */

typedef struct s_rules
{
	int			n;
	long		td;
	long		te;
	long		ts;
	int			must_eat;

	long		start;
	pid_t		*pids;

	sem_t		*forks;
	sem_t		*print;
}				t_rules;

typedef struct s_philo
{
	int			id;
	int			eaten;
	long		last_meal;

	char		meal_name[32];
	sem_t		*meal_sem;

	pthread_t	routine;
	pthread_t	monitor;

	t_rules		*r;
}				t_philo;

/* ===================== PRINT ===================== */

static void	print_action(t_philo *p, char *msg)
{
	sem_wait(p->r->print);
	printf("%ld %d %s\n", get_time() - p->r->start, p->id, msg);
	fflush(stdout);
	sem_post(p->r->print);
}

/* ===================== MONITOR ===================== */

static void	*monitor(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		sem_wait(p->meal_sem);
		if (get_time() - p->last_meal > p->r->td)
		{
			sem_wait(p->r->print);
			printf("%ld %d died\n", get_time() - p->r->start, p->id);
			exit(1);
		}
		sem_post(p->meal_sem);
		usleep(500);
	}
	return (NULL);
}

/* ===================== THINK TIME ===================== */

static long	get_think_time(t_philo *p)
{
	long	t;

	if (p->r->n % 2 == 1)
		t = p->r->te * 2 - p->r->ts;
	else
		t = p->r->te - p->r->ts;
	if (t < 0)
		t = 0;
	return (t);
}

/* ===================== ROUTINE ===================== */

static void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		ft_sleep(p->r->te);
	while (1)
	{
		sem_wait(p->r->forks);
		print_action(p, "has taken a fork");
		sem_wait(p->r->forks);
		print_action(p, "has taken a fork");
		print_action(p, "is eating");
		sem_wait(p->meal_sem);
		p->last_meal = get_time();
		p->eaten++;
		sem_post(p->meal_sem);
		ft_sleep(p->r->te);
		sem_post(p->r->forks);
		sem_post(p->r->forks);
		if (p->r->must_eat != -1 && p->eaten >= p->r->must_eat)
			exit(0);
		print_action(p, "is sleeping");
		ft_sleep(p->r->ts);
		print_action(p, "is thinking");
		ft_sleep(get_think_time(p));
	}
	return (NULL);
}

/* ===================== CHILD ===================== */

static void	child_process(t_rules *r, int i)
{
	t_philo	p;

	p.id = i + 1;
	p.eaten = 0;
	p.r = r;
	p.last_meal = get_time();
	p.meal_name[0] = '/';
	p.meal_name[1] = 'm';
	p.meal_name[2] = 'e';
	p.meal_name[3] = 'a';
	p.meal_name[4] = 'l';
	p.meal_name[5] = '_';
	p.meal_name[6] = '0' + (p.id / 10);
	p.meal_name[7] = '0' + (p.id % 10);
	p.meal_name[8] = '\0';
	sem_unlink(p.meal_name);
	p.meal_sem = sem_open(p.meal_name, O_CREAT, 0644, 1);
	if (p.meal_sem == SEM_FAILED)
		exit(1);
	pthread_create(&p.monitor, NULL, monitor, &p);
	pthread_create(&p.routine, NULL, routine, &p);
	pthread_join(p.routine, NULL);
	pthread_join(p.monitor, NULL);
	sem_close(p.meal_sem);
	sem_unlink(p.meal_name);
	sem_close(r->forks);
	sem_close(r->print);
	exit(0);
}

/* ===================== INIT ===================== */

static int	init_rules(t_rules *r, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (0);
	r->n = ft_atoi(av[1]);
	r->td = ft_atoi(av[2]);
	r->te = ft_atoi(av[3]);
	r->ts = ft_atoi(av[4]);
	r->must_eat = -1;
	if (ac == 6)
		r->must_eat = ft_atoi(av[5]);
	return (r->n > 0);
}

static void	init_sems(t_rules *r)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	r->forks = sem_open("/forks", O_CREAT, 0644, r->n);
	r->print = sem_open("/print", O_CREAT, 0644, 1);
	if (r->forks == SEM_FAILED || r->print == SEM_FAILED)
		fatal("sem_open failed");
}

/* ===================== MAIN ===================== */

int	main(int ac, char **av)
{
	t_rules	r;
	int		i;
	int		status;

	if (!init_rules(&r, ac, av))
		fatal("bad args");
	init_sems(&r);
	r.start = get_time();
	r.pids = malloc(sizeof(pid_t) * r.n);
	if (!r.pids)
		fatal("malloc failed");
	i = 0;
	while (i < r.n)
	{
		r.pids[i] = fork();
		if (r.pids[i] == 0)
			child_process(&r, i);
		i++;
		usleep(1000);
	}
	i = 0;
	while (i < r.n)
	{
		if (waitpid(-1, &status, 0) <= 0)
			break ;
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
			break ;
		i++;
	}
	i = 0;
	while (i < r.n)
	{
		kill(r.pids[i], SIGKILL);
		i++;
	}
	i = 0;
	while (i < r.n)
	{
		waitpid(r.pids[i], NULL, 0);
		i++;
	}
	free(r.pids);
	sem_close(r.forks);
	sem_close(r.print);
	sem_unlink("/forks");
	sem_unlink("/print");
	return (0);
}
