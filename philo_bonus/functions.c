/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:42:35 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/06/03 10:42:39 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	allocate_indexes(int n)
{
	int	i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static unsigned int	check_number(char *str, int n)
{
	if (n < 0)
	{
		str[0] = '-';
		return (n * -1);
	}
	return (n);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *) malloc (ft_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				indexes;
	unsigned int	number;

	if (n == 0)
		return (ft_strdup("0"));
	indexes = allocate_indexes(n);
	str = (char *) malloc (indexes + 1);
	if (!str)
		return (NULL);
	number = check_number(str, n);
	str[indexes] = 0;
	indexes--;
	while (number != 0)
	{
		if (number > 9)
			str[indexes] = number % 10 + '0';
		else
			str[indexes] = number + '0';
		number = number / 10;
		indexes--;
	}
	return (str);
}
