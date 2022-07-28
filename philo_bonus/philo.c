/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:42:54 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/06/03 10:42:56 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_all_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		kill(data->philos[i].pid, SIGKILL);
		i++;
	}
	free_all(data);
}

void	check_processes(t_data *data)
{
	int	i;
	int	pid;

	i = -1;
	while (++i < data->n_philos)
	{
		waitpid(-1, &pid, 0);
		if (pid != EXIT_SUCCESS)
			break ;
		if (i == data->n_philos - 1)
		{
			if (data->eat_at_least > 0)
			{
				kill_all_processes(data);
				sem_wait(data->pen);
				printf(SUCCESS_MSG);
			}
			return ;
		}
	}
	kill_all_processes(data);
}

void	exec_prog(t_data *data)
{
	int	i;
	int	pid;

	i = 0;
	pid = -1;
	data->timestamp = timestamp();
	while (i < data->n_philos)
	{
		data->philos[i].pid = fork();
		if (!data->philos[i].pid)
			philo_start(data->philos + i);
		else if (data->philos[i].pid < 0)
		{
			kill_all_processes(data);
			get_err(FORK_ERR);
		}
		else
		{
			usleep(BREAK_TO_PREVENT_DEADLOCK);
			i++;
		}
	}
	check_processes(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		get_err(ARGS_ERR);
	sem_unlink("forks");
	sem_unlink("pen");
	sem_unlink("b_sema");
	data = get_data(ac, av);
	if (!data)
		return (EXIT_FAILURE);
	exec_prog(data);
	sem_close(data->forks);
	sem_close(data->pen);
	sem_close(data->last);
	return (EXIT_SUCCESS);
	return (0);
}
