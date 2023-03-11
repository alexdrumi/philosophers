/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_philos.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2021/12/20 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/init_philos.h"

static void	assign_forks(t_data *data, int n)
{
	if (n < data->num_philo - 1)
	{
		data->philos[n].first_fork = n;
		data->philos[n].second_fork = (n + 1) % data->num_philo;
	}
	else
	{
		data->philos[n].first_fork = (n + 1) % data->num_philo;
		data->philos[n].second_fork = n;
	}
}

static void	set_philos_attributes(t_data *data, int i)
{
	data->philos[i].is_finished = false;
	data->philos[i].n = i + 1;
	data->philos[i].data_ptr = data;
	data->philos[i].must_eat = data->must_eat;
	data->philos[i].time_to_eat = data->time_to_eat;
	data->philos[i].time_to_sleep = data->time_to_sleep;
}

t_bool	init_philos_succeeded(t_data *data)
{
	int	i;

	i = 0;
	data->philos = (t_philosopher *)malloc(data->num_philo
			* sizeof(t_philosopher));
	if (data->philos == NULL)
	{
		return (false);
	}
	data->time_to_wait = get_max(data->time_to_eat, data->time_to_sleep);
	data->start_time = get_time();
	data->which_died = -1;
	while (i < data->num_philo)
	{
		set_philos_attributes(data, i);
		assign_forks(data, i);
		i++;
	}
	return (true);
}
