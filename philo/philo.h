/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:57:33 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/28 14:57:34 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "structures.h"
# include "macros.h"

void		get_err(char *s);
void		*alloc_mem(int bytes, int size);
t_philos	*get_philos(t_data *data);
t_data		*get_data(int ac, char **av);

long long	timestamp(void);
long long	gettimestamp(t_data *data);
int			all_one(int *k, int size);
void		init_k(int *k, t_data *data);
int			*get_init_arr(int size, int size_of, int val);
int			ft_atoi(const char *s);

int			exec_philos(t_data *data);
int			wait_threads_check_death(t_data *data);
void		*philo_start(void *arg);
void		launch_philos(t_philos *philo, int r, int l);
void		odd_philo(t_philos *philo);
void		take_pen_write(t_philos *philo, int taken_fork);
void		philo_took_fork(t_philos *philo);
void		ft_sleep(int n);

#endif
