/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/destroy.h"
#include <stdlib.h>

void	destroy_forks(t_data *data)
{
	free(data->forks);
}

void	destroy_philos(t_data *data)
{
	free(data->philos);
}

t_bool	destroy_mutexes_succeeded(t_data	*data)
{
	int		i;

	i = 0;
	while (i < data->num_philo)
	{
		if ((pthread_mutex_destroy(&data->philos[i].last_meal_m) != 0)
			|| (pthread_mutex_destroy(&data->philos[i].is_finished_m)
				!= 0))
		{
			return (false);
		}
		i++;
	}
	if ((pthread_mutex_destroy(&data->time_of_death_m) != 0)
		|| (pthread_mutex_destroy(&data->which_died_m) != 0))
	{
		return (false);
	}
	destroy_forks(data);
	return (true);
}
