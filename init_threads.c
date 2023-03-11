/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_threads.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2021/12/20 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/init_threads.h"
#include <stdlib.h>

static t_bool	init_eatsleepthink_succeeded(t_data *data,
			pthread_t *detach_thread_for_philos)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(detach_thread_for_philos, NULL,
				eat_sleep_think_cycle, (void *)&data->philos[i]) != 0)
		{
			return (false);
		}
		pthread_mutex_lock(&data->philos[i].last_meal_m);
		data->philos[i].last_meal = get_elapsed_time(&data->philos[i]);
		pthread_mutex_unlock(&data->philos[i].last_meal_m);
		pthread_detach(*detach_thread_for_philos);
		i++;
	}
	return (true);
}

static t_bool	init_small_monitoring_thread(t_data *data,
		pthread_t *small_death_check_threads)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&small_death_check_threads[i], NULL,
				check_if_this_philo_is_dead,
				(void *)&data->philos[i]) != 0)
		{
			return (false);
		}
		pthread_join(small_death_check_threads[i], NULL);
		i++;
	}
	return (true);
}

t_bool	init_threads_succeeded(t_data *data)
{
	int			i;
	pthread_t	detach_thread_for_philos;
	pthread_t	main_death_check_thread;
	pthread_t	*small_death_check_threads;

	i = 0;
	if (init_eatsleepthink_succeeded(data, &detach_thread_for_philos) == false)
		return (false);
	if (pthread_create(&main_death_check_thread, NULL,
			check_if_any_philo_is_dead, (void *)&data->philos[0]) != 0)
		return (false);
	small_death_check_threads = (pthread_t *)malloc(data->num_philo
			* sizeof(pthread_t));
	if (!small_death_check_threads)
		return (false);
	if (init_small_monitoring_thread(data, small_death_check_threads) == false)
	{
		free(small_death_check_threads);
		return (false);
	}
	pthread_join(main_death_check_thread, NULL);
	free(small_death_check_threads);
	return (true);
}
