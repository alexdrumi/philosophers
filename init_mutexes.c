/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mutexes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2021/12/20 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/init_mutexes.h"

t_bool	init_mutexes_succeeded(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(data->num_philo
			* sizeof(pthread_mutex_t));
	if (!data->forks)
		return (false);
	if ((pthread_mutex_init(&data->time_of_death_m, NULL) != 0)
		|| (pthread_mutex_init(&data->which_died_m, NULL) != 0)
		|| (pthread_mutex_init(&data->can_write_m, NULL) != 0))
	{	
		return (false);
	}
	while (i < data->num_philo)
	{
		if ((pthread_mutex_init(&data->philos[i].last_meal_m, NULL) != 0)
			|| (pthread_mutex_init(&data->forks[i], NULL) != 0)
			|| (pthread_mutex_init(&data->philos[i].is_finished_m, NULL))
			!= 0)
		{
			return (false);
		}
		i++;
	}
	return (true);
}
