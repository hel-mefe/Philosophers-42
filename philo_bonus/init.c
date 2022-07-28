/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:42:50 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/06/03 10:42:51 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*get_philos(t_data *data)
{
	t_philos	*philos;
	int			i;

	philos = alloc_mem(data->n_philos, sizeof(t_philos));
	i = 0;
	while (i < data->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].eat = 0;
		philos[i].data = data;
		philos[i].state = THINKING;
		philos[i].nb_meals = 0;
		i++;
	}
	return (philos);
}

int	get_all_semaphores(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("pen");
	sem_unlink("b_sema");
	data->forks = sem_open("forks", O_CREAT, 0777, data->n_philos);
	if (data->forks == SEM_FAILED)
		return (0);
	data->last = (sem_t *) sem_open("b_sema", O_CREAT, 0777, 1);
	if (!data->last)
		return (0);
	data->pen = sem_open("pen", O_CREAT, 0777, 1);
	if (data->pen == SEM_FAILED)
		return (0);
	return (1);
}

t_data	*get_data(int ac, char **av)
{
	t_data	*data;

	data = (t_data *) alloc_mem(1, sizeof(t_data));
	data->n_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (data->n_philos <= 0 || data->t_die <= 0 \
		|| data->t_eat <= 0 || data->t_sleep <= 0)
		get_err(ARGS_ERR);
	data->eat_at_least = 0;
	data->last_argument = (ac == 6);
	if (ac == 6)
		data->eat_at_least = ft_atoi(av[5]);
	if (data->last_argument && data->eat_at_least <= 0)
		get_err(EAT_ZERO_ERR);
	data->dead = 0;
	if (!get_all_semaphores(data))
		return (NULL);
	data->philos = get_philos(data);
	data->timestamp = 0;
	return (data);
}
