/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:41:53 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/06/03 10:41:54 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_err(char *err)
{
	int	i;

	i = 0;
	while (err[i])
	{
		write(1, &err[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	*alloc_mem(int bytes, int size)
{
	void	*mem;

	mem = malloc (bytes * size);
	if (!mem)
		get_err(ALLOC_ERR);
	return (mem);
}
