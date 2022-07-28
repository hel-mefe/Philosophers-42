/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:57:23 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/28 14:57:24 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*get_philos(t_data *data)
{
	t_philos	*philos;
	int			i;

	philos = (t_philos *) malloc (data->n_philos * sizeof(t_philos));
	i = 0;
	while (i < data->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].eat = 0;
		philos[i].r_fork = (i + 1) % data->n_philos;
		philos[i].l_fork = i;
		philos[i].data = data;
		philos[i].state = THINKING;
		philos[i].nb_meals = 0;
		philos[i].last_mutex = &data->lasts[i];
		i++;
	}
	return (philos);
}

void	init_mutexes(pthread_mutex_t *forks, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

int	get_crucial_data(t_data *data, char **av, int ac)
{
	data->n_philos = ft_atoi(av[1]);
	if (data->n_philos <= 0)
		return (0);
	data->t_die = ft_atoi(av[2]);
	if (data->t_die <= 0)
		return (0);
	data->t_eat = ft_atoi(av[3]);
	if (data->t_eat <= 0)
		return (0);
	data->t_sleep = ft_atoi(av[4]);
	if (data->t_sleep <= 0)
		return (0);
	data->eat_at_least = -1;
	data->last_arg = (ac == 6);
	if (ac == 6)
		data->eat_at_least = ft_atoi(av[5]);
	if (data->last_arg && data->eat_at_least <= 0)
		return (0);
	return (1);
}

t_data	*get_data(int ac, char **av)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!get_crucial_data(data, av, ac))
	{
		get_err(ARGS_ERR);
		return (NULL);
	}
	data->lasts = (pthread_mutex_t *) \
	malloc (data->n_philos * sizeof(pthread_mutex_t));
	init_mutexes(data->lasts, data->n_philos);
	data->dead = 0;
	data->forks = (pthread_mutex_t *) \
	malloc(data->n_philos * sizeof(pthread_mutex_t));
	init_mutexes(data->forks, data->n_philos);
	pthread_mutex_init(&data->pen, NULL);
	data->philos = get_philos(data);
	data->timestamp = 0;
	return (data);
}
