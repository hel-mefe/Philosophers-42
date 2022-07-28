/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:59:04 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/28 14:59:04 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

struct	s_all_data;

typedef struct philos
{
	int					id;
	int					eat;
	int					allowed;
	int					state;
	int					nb_meals;
	long long			last;
	pid_t				pid;
	long long			l;
	sem_t				*last_sem;
	pthread_mutex_t		c;
	struct s_all_data	*data;
}	t_philos;

typedef struct s_all_data
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				dead;
	int				eat_at_least;
	int				last_argument;
	long long		timestamp;
	t_philos		*philos;
	sem_t			*pen;
	sem_t			*last;
	sem_t			*forks;
}	t_data;

#endif
