/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# define NUM_PHILO 5
# define INIT_MUTEXES_ERROR_MSG "Something unexpected \
happened while initializing mutexes, exiting.\n"
# define INCORRECT_INPUT_MSG "Incorrect input, exiting.\n"
# define INIT_PHILO_ERROR_MSG "Something unexpected \
happened while initializing philos, exiting\n"
# define INIT_THREAD_ERROR_MSG "Something unexpected \
 while initializing threads, exiting\n"
# define DESTROY_MUTEX_ERROR_MSG "Something unexpected \
happened while destroying mutexes, exiting\n"

#endif