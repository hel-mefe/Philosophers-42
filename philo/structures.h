/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:58:03 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/28 14:58:04 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

struct	s_all_data;

typedef struct philos
{
	pthread_mutex_t		state_mutex;
	pthread_mutex_t		*last_mutex;
	int					id;
	int					eat;
	int					allowed;
	int					state;
	int					r_fork;
	int					l_fork;
	int					nb_meals;
	long long			last;
	pthread_t			thread_id;
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
	int				last_arg;
	long long		timestamp;
	t_philos		*philos;
	pthread_mutex_t	pen;
	pthread_mutex_t	*lasts;
	pthread_mutex_t	*state_mutexes;
	pthread_mutex_t	*forks;
}			t_data;

#endif
