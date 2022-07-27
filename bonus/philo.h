/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:43:15 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/06/03 10:43:17 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <pthread.h>

/* ERRORS */

# define ARGS_ERR "\033[4;33mPHILOSOPHERS_1337 -> \t\033[4;31m \
PLEASE ENTER A VALID ARGUMENTS AS FOLLOWS: \n\n\
\033[4;36m./program [number_of_philosophers] \
[time_to_die] [time_to_eat] [time_to_sleep]"
# define ALLOC_ERR "\033[4;31mPHILOSOPHERS_1337: \
THERE WAS AN UNEXPECTED ERROR IN MALLOC :("
# define THREAD_ERR "\033[4;31mPHILOSOPHERS_1337: \
THERE WAS AN ERROR IN CREATING THE THREAD!"
# define NUM_PHILOS "\033[4;31mPHILOSOPHERS_1337: \
PLEASE ENTER A VALID NUMBER OF PHILOS (1 OR ABOVE)"
# define FORK_ERR "\033[4;33m PHLOSOPHERS_1337 -> \
THERE WAS AN ERROR IN FORKING THE PROCESSES!"
# define SEM_ERR "ERROR IN OPENING THE SEMAPHORE!"
/* Philosophers moods */
# define SLEEPING 0
# define THINKING 1
# define EATING 2
# define BREAK_TO_PREVENT_DEADLOCK 30
# define EXIT_DEATH 1999

struct	s_all_data;

typedef struct philos
{
	int					id;
	int					eat;
	int					allowed;
	int					state;
	int					nb_meals;
	long long			last;
	pid_t				pid;
	long long			l;
	sem_t				*last_sem;
	pthread_mutex_t		c;
	struct s_all_data	*data;
}	t_philos;

typedef struct s_all_data
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				dead;
	int				eat_at_least;
	long long		timestamp;
	t_philos		*philos;
	sem_t			*pen;
	sem_t			*last;
	sem_t			*forks;
}	t_data;

// Error functions
void		get_err(char *s);
void		*alloc_mem(int bytes, int size);

// Init functions
t_philos	*get_philos(t_data *data);
t_data		*get_data(int ac, char **av);

// Getting time functions
long long	timestamp(void);
long long	gettimestamp(t_data *data);

// Semaphore functions
int			get_all_semaphores(t_data *data);
int			init_binary_sem(sem_t **semaphores, int size);

// Philosopher functions
int			exec_philos(t_data *data);
void		check_processes(t_data *data);
void		kill_all_processes(t_data *data);
void		philo_start(t_philos *philo);
void		even_philo(t_philos *philo);
void		odd_philo(t_philos *philo);
void		take_pen_write(t_philos *philo, int taken_fork);
void		philo_took_fork(t_philos *philo);
void		ft_sleep(int n);
char		*ft_itoa(int n);
int			ft_atoi(const char *s);
// Free memory
void		free_mem(t_data *data);
void		free_all(t_data *data);
#endif
