#include "philo.h"

int	all_one(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	do_philos_ate_enough(t_data *data, int i, int *k)
{
	pthread_mutex_lock(data->philos[i].last_mutex);
	if (data->philos[i].nb_meals >= data->eat_at_least)
		k[i] = 1;
	if (all_one(k, data->n_philos))
	{
		pthread_mutex_lock(&data->pen);
		printf("\033[2;32m\nHEEEY! LUCKY OUR PHILOS THEY SURVIVED!");
		return (1);
	}
	pthread_mutex_unlock(data->philos[i].last_mutex);
	return (0);
}

int	wait_threads_check_death(t_data *data)
{
	int			i;
	int			*k;

	k = get_init_arr(data->n_philos, sizeof(int), 0);
	while (1)
	{
		i = 0;
		while (i < data->n_philos)
		{
			pthread_mutex_lock(data->philos[i].last_mutex);
			if (timestamp() - data->philos[i].last >= data->t_die)
			{
				pthread_mutex_lock(&data->pen);
				printf("\033[4;31m%lldms philo id %d has died :(\n", \
				gettimestamp(data), i + 1);
				return (1);
			}
			pthread_mutex_unlock(data->philos[i].last_mutex);
			if (data->eat_at_least && do_philos_ate_enough(data, i, k))
				return (1);
			i++;
		}
	}
	return (1);
}

int	exec_philos(t_data *data)
{
	int	i;

	i = 0;
	data->timestamp = timestamp();
	while (i < data->n_philos)
	{
		data->philos[i].last = timestamp();
		if (pthread_create(&data->philos[i].thread_id, NULL, \
		philo_start, (void *) &data->philos[i]))
			get_err(THREAD_ERR);
		i++;
	}
	if (wait_threads_check_death(data))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		get_err(ARGS_ERR);
	data = get_data(ac, av);
	if (!data)
		return (EXIT_FAILURE);
	exec_philos(data);
	return (EXIT_SUCCESS);
}
