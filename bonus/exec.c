/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:42:05 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/06/03 10:42:06 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_took_fork(t_philos *philo)
{
	int			id;
	long long	t;

	id = philo->id;
	sem_wait(philo->data->pen);
	t = gettimestamp(philo->data);
	printf("\033[1;36m%lldms ", t);
	printf("\033[0;37mphilo id %d ", id);
	printf("\033[1;34mhas taken a fork\n");
	sem_post(philo->data->pen);
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
	sem_wait(philo->data->pen);
	id = philo->id;
	t = gettimestamp(philo->data);
	printf("\033[1;36m%lldms ", t);
	printf("\033[0;37mphilo id %d is ", id);
	printf("%s\n", s);
	sem_post(philo->data->pen);
}

void	*death_watcher(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *) arg;
	while (1)
	{
		sem_wait(philo->last_sem);
		if (timestamp() - philo->last >= philo->data->t_die)
		{
			sem_wait(philo->data->pen);
			printf("\033[4;31m%lldms philo id %d has died :(\n", \
			gettimestamp(philo->data), philo->id);
			exit(EXIT_FAILURE);
		}
		sem_post(philo->last_sem);
		usleep(500);
	}
	return (NULL);
}

void	even_philo(t_philos *philo)
{
	sem_wait(philo->data->forks);
	take_pen_write(philo, 1);
	sem_wait(philo->data->forks);
	take_pen_write(philo, 1);
	sem_wait(philo->last_sem);
	philo->last = timestamp();
	philo->nb_meals += 1;
	sem_post(philo->last_sem);
	philo->state = EATING;
	take_pen_write(philo, 0);
	ft_sleep(philo->data->t_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	if (philo->data->eat_at_least \
		&& philo->nb_meals >= philo->data->eat_at_least)
	{
		sem_post(philo->data->last);
		exit(EXIT_SUCCESS);
	}
	philo->state = SLEEPING;
	take_pen_write(philo, 0);
	ft_sleep(philo->data->t_sleep);
	philo->state = THINKING;
	take_pen_write(philo, 0);
}

void	philo_start(t_philos *philo)
{
	pthread_t	watcher;
	pthread_t	free_thread;
	char		*name;

	name = ft_itoa(philo->id + 1000);
	sem_unlink(name);
	philo->last_sem = sem_open(name, O_CREAT, 0777, 1);
	sem_wait(philo->last_sem);
	philo->last = timestamp();
	sem_post(philo->last_sem);
	pthread_mutex_init(&philo->c, NULL);
	if (pthread_create(&watcher, NULL, death_watcher, philo))
		get_err(THREAD_ERR);
	if (philo->last_sem == SEM_FAILED)
		get_err(SEM_ERR);
	while (1)
		even_philo(philo);
	sem_close(philo->last_sem);
}
