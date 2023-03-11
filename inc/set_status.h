/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_status.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_STATUS_H
# define SET_STATUS_H
# include "structs.h"
# include "print.h"

t_bool	did_anyone_die(t_philosopher *philo);
t_bool	is_finished(t_philosopher *philo);
void	set_finished(t_philosopher *philo);
void	set_to_dead(t_philosopher *philo, int time);

#endif