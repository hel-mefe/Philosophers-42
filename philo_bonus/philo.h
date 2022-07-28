/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:43:15 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/06/03 10:43:17 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <pthread.h>
# include "structures.h"
# include "macros.h"

// Error functions
void		get_err(char *s);
void		*alloc_mem(int bytes, int size);

// Init functions
t_philos	*get_philos(t_data *data);
t_data		*get_data(int ac, char **av);

// Getting time functions
long long	timestamp(void);
long long	gettimestamp(t_data *data);

// Semaphore functions
int			get_all_semaphores(t_data *data);
int			init_binary_sem(sem_t **semaphores, int size);

// Philosopher functions
int			exec_philos(t_data *data);
void		check_processes(t_data *data);
void		kill_all_processes(t_data *data);
void		philo_start(t_philos *philo);
void		launch_routine(t_philos *philo);
void		odd_philo(t_philos *philo);
void		take_pen_write(t_philos *philo, int taken_fork);
void		philo_took_fork(t_philos *philo);
void		ft_sleep(int n);
char		*ft_itoa(int n);
int			ft_atoi(const char *s);
// Free memory
void		free_mem(t_data *data);
void		free_all(t_data *data);
#endif
