#include <sys/time.h>
#include <stdio.h>

typedef struct timeval	t_timeval;


long	ft_gettime(void)
{
	t_timeval	tv;
	long		time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int	main(void)
{
	long time = ft_gettime();
	printf("%ld", time);
}