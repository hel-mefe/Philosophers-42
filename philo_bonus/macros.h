/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:58:59 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/28 14:59:00 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/* Error Macros */

# define EAT_ZERO_ERR "\033[4;33mPHILOSOPHERS_1337 -> \t\033[4;31m\
The eat_at_least argument cannot be 0 or less\n"
# define ARGS_ERR "\033[4;33mPHILOSOPHERS_1337 -> \t\033[4;31m \
PLEASE ENTER A VALID ARGUMENTS AS FOLLOWS: \n\
\033[4;36m./program [number_of_philosophers] \
[time_to_die] [time_to_eat] [time_to_sleep]"
# define ALLOC_ERR "\033[4;31mPHILOSOPHERS_1337: \
THERE WAS AN UNEXPECTED ERROR IN MALLOC :("
# define THREAD_ERR "\033[4;31mPHILOSOPHERS_1337: \
THERE WAS AN ERROR IN CREATING THE THREAD!"
# define NUM_PHILOS "\033[4;31mPHILOSOPHERS_1337: \
PLEASE ENTER A VALID NUMBER OF PHILOS (1 OR ABOVE)"
# define FORK_ERR "\033[4;33m PHLOSOPHERS_1337 -> \
THERE WAS AN ERROR IN FORKING THE PROCESSES!"
# define SEM_ERR "ERROR IN OPENING THE SEMAPHORE!"
# define SUCCESS_MSG "\033[1;32m\nš½ HEEEY! LUCKY OUR PHILOS \
THEY SURVIVED! š½\n"

/* Philosophers Modes */
# define SLEEPING 0
# define THINKING 1
# define EATING 2

/* Helpful Macros */
# define STD_ERR 2
# define WAIT_A_LITTLE_BIT 500
# define BREAK_TO_PREVENT_DEADLOCK 30
# define EXIT_DEATH 1999
#endif
