/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:43:29 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/06/03 10:43:31 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	struct timeval	current;
	long long		time;

	gettimeofday(&current, NULL);
	time = current.tv_sec * 1000;
	time += current.tv_usec / 1000;
	return (time);
}

long long	gettimestamp(t_data *data)
{
	struct timeval	current;
	long long		time;

	gettimeofday(&current, NULL);
	time = timestamp() - data->timestamp;
	return (time);
}

void	ft_sleep(int n)
{
	long long	k;

	k = timestamp() + n;
	while (timestamp() < k)
		usleep(30);
}
