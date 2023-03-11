/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitoring_threads.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORING_THREADS_H
# define MONITORING_THREADS_H
# include "structs.h"
# include "set_status.h"
# include "utils.h"

void	*check_if_this_philo_is_dead(void *arg);
void	*check_if_any_philo_is_dead(void *arg);

#endif