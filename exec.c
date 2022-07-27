#include "philo.h"

void	philo_took_fork(t_philos *philo)
{
	int			id;
	long long	t;

	id = philo->id;
	pthread_mutex_lock(&philo->data->pen);
	t = gettimestamp(philo->data);
	printf("\033[1;36m%lldms ", t);
	printf("\033[0;37mphilo id %d ", id);
	printf("\033[1;34mhas taken a fork\n");
	pthread_mutex_unlock(&philo->data->pen);
}

void	take_pen_write(t_philos *philo, int taken_fork)
{
	char		*s;
	int			id;
	long long	t;

	if (taken_fork)
	{
		philo_took_fork(philo);
		return ;
	}
	if (philo->state == THINKING)
		s = "\033[1;35mthinking";
	else if (philo->state == EATING)
		s = "\033[1;32meating";
	else if (philo->state == SLEEPING)
		s = "\033[0;33msleeping";
	pthread_mutex_lock(&philo->data->pen);
	id = philo->id;
	t = gettimestamp(philo->data);
	printf("\033[1;36m%lldms ", t);
	printf("\033[0;37mphilo id %d is ", id);
	printf("%s\n", s);
	pthread_mutex_unlock(&philo->data->pen);
}

void	launch_philos(t_philos *philo, int r, int l)
{
	pthread_mutex_lock(&philo->data->forks[r]);
	take_pen_write(philo, 1);
	pthread_mutex_lock(&philo->data->forks[l]);
	take_pen_write(philo, 1);
	pthread_mutex_lock(philo->last_mutex);
	philo->state = EATING;
	philo->last = timestamp();
	philo->nb_meals += 1;
	pthread_mutex_unlock(philo->last_mutex);
	take_pen_write(philo, 0);
	ft_sleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->data->forks[r]);
	pthread_mutex_unlock(&philo->data->forks[l]);
	philo->state = SLEEPING;
	take_pen_write(philo, 0);
	ft_sleep(philo->data->t_sleep);
	philo->state = THINKING;
	take_pen_write(philo, 0);
}

void	*philo_start(void *arg)
{
	t_philos	*philo;
	int			r;
	int			l;

	philo = (t_philos *) arg;
	r = philo->r_fork;
	l = philo->l_fork;
	if (philo->id % 2 == 0)
		usleep(BREAK_TO_PREVENT_DEADLOCK);
	while (1)
		launch_philos(philo, philo->r_fork, philo->l_fork);
	return (NULL);
}
