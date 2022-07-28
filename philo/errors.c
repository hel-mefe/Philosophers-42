/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:57:44 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/28 14:57:45 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_err(char *err)
{
	int	i;

	i = 0;
	while (err[i])
	{
		write(STD_ERR, &err[i], 1);
		i++;
	}
}

void	*alloc_mem(int bytes, int size)
{
	void	*mem;

	mem = malloc (bytes * size);
	if (!mem)
	{
		get_err(ALLOC_ERR);
		return (NULL);
	}
	return (mem);
}
