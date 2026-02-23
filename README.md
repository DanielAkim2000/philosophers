*This project has been created as part of the 42 curriculum by demane.*

---

# Philosophers

## Description

The **Philosophers** project is an implementation of the classic
[Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem),
a well-known concurrency challenge in computer science.

The goal is to simulate a number of philosophers sitting at a round table,
alternating between **eating**, **sleeping**, and **thinking**. Each philosopher
needs two forks (shared with their neighbors) to eat. The simulation must avoid
**deadlocks** and **data races** while ensuring no philosopher starves
unnecessarily.

Two versions are provided:

| Version | Directory | Synchronization |
|---------|-----------|-----------------|
| Mandatory | `philo/` | Threads + Mutexes |
| Bonus | `philo_bonus/` | Processes + Semaphores |

### Arguments

```
./philo <nb_philo> <time_to_die> <time_to_eat> <time_to_sleep> [nb_meals]
```

| Argument | Description |
|----------|-------------|
| `nb_philo` | Number of philosophers (and forks) |
| `time_to_die` | Time (ms) before a philosopher dies without eating |
| `time_to_eat` | Time (ms) a philosopher takes to eat |
| `time_to_sleep` | Time (ms) a philosopher sleeps |
| `nb_meals` | *(optional)* Simulation stops after every philosopher has eaten this many times |

## Instructions

### Prerequisites

- GCC or Clang
- Make
- POSIX-compliant system (Linux / macOS)

### Build

```bash
# Mandatory part
cd philo && make

# Bonus part
cd philo_bonus && make
```

### Run

```bash
# Example: 5 philosophers, 800ms die, 200ms eat, 200ms sleep
./philo 5 800 200 200

# With optional meal count (stop after 7 meals each)
./philo 5 800 200 200 7

# Bonus version
./philo_bonus 5 800 200 200 7
```

### Clean

```bash
make clean   # Remove object files
make fclean  # Remove object files and binary
make re      # Full rebuild
```

## Resources

- [Dining Philosophers Problem – Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Programming – LLNL](https://hpc-tutorials.llnl.gov/posix/)
- [sem_overview – Linux man page](https://man7.org/linux/man-pages/man7/sem_overview.7.html)
- [Philosophers – 42 subject PDF](https://projects.intra.42.fr/projects/philosophers)

### AI Disclaimer

Parts of this project were developed with the assistance of **GitHub Copilot**
(Claude), notably for debugging memory leaks (valgrind/helgrind), code
refactoring, and norminette compliance. All generated code was reviewed,
understood, and validated by the author.
