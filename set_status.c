/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_status.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/set_status.h"

t_bool	did_anyone_die(t_philosopher *philo)
{
	t_bool	answer;

	pthread_mutex_lock(&philo->data_ptr->which_died_m);
	if (philo->data_ptr->which_died != -1)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	pthread_mutex_unlock(&philo->data_ptr->which_died_m);
	return (answer);
}

t_bool	is_finished(t_philosopher *philo)
{
	t_bool	is_finished;

	pthread_mutex_lock(&philo->is_finished_m);
	is_finished = philo->is_finished;
	pthread_mutex_unlock(&philo->is_finished_m);
	return (is_finished);
}

void	set_finished(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->is_finished_m);
	philo->is_finished = true;
	pthread_mutex_unlock(&philo->is_finished_m);
}

void	set_to_dead(t_philosopher *philo, int time)
{
	if (did_anyone_die(philo) == false)
	{
		pthread_mutex_lock(&philo->data_ptr->which_died_m);
		pthread_mutex_lock(&philo->data_ptr->time_of_death_m);
		philo->data_ptr->time_of_death = time;
		philo->data_ptr->which_died = philo->n;
		pthread_mutex_unlock(&philo->data_ptr->time_of_death_m);
		pthread_mutex_unlock(&philo->data_ptr->which_died_m);
	}
}
