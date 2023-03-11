/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitoring_threads.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2021/12/20 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/monitoring_threads.h"
#include <stdio.h>

static void	exec_death_print_sequence(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data_ptr->can_write_m);
	pthread_mutex_lock(&philo->data_ptr->which_died_m);
	pthread_mutex_lock(&philo->data_ptr->time_of_death_m);
	printf("%d %d died\n", philo->data_ptr->time_of_death,
		philo->data_ptr->which_died);
	pthread_mutex_unlock(&philo->data_ptr->which_died_m);
	pthread_mutex_unlock(&philo->data_ptr->time_of_death_m);
	usleep((philo->data_ptr->time_to_wait * 1000) / 4);
}

void	*check_if_this_philo_is_dead(void *arg)
{
	t_philosopher	*philo;
	int				elapsed_time;
	int				time_available;

	philo = (t_philosopher *)arg;
	while (did_anyone_die(philo) == false && philo->must_eat != 0)
	{
		pthread_mutex_lock(&philo->last_meal_m);
		time_available = philo->last_meal + philo->data_ptr->time_to_die;
		pthread_mutex_unlock(&philo->last_meal_m);
		elapsed_time = get_elapsed_time(philo);
		if (elapsed_time > time_available)
		{
			set_to_dead(philo, time_available);
			break ;
		}
	}
	usleep((philo->data_ptr->time_to_wait * 1000) / 4);
	return (NULL);
}

void	*check_if_any_philo_is_dead(void *arg)
{
	int					i;
	int					finished_philos;
	t_philosopher		*philo;

	philo = (t_philosopher *)arg;
	finished_philos = 0;
	while (philo != NULL && finished_philos < philo->data_ptr->num_philo)
	{
		i = 0;
		finished_philos = 0;
		while (i < philo->data_ptr->num_philo)
		{
			if (did_anyone_die(philo) == true)
			{
				exec_death_print_sequence(philo);
				return (NULL);
			}
			if (is_finished(&philo[i]) == true)
				finished_philos++;
			i++;
		}
	}
	return (NULL);
}
