/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2021/12/20 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "inc/ft_atoi_overflow.h"

static t_bool	is_input_correct(t_data *data, int *overflow_flag)
{
	if (data->num_philo <= 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0
		|| data->must_eat <= 0)
	{
		return (false);
	}
	else if (*overflow_flag == 1)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

t_bool	parse_succeeded(int argc, char *argv[], t_data *data)
{
	int	overflow_flag;

	if (argc < 5 || argc > 6)
	{
		return (false);
	}
	overflow_flag = 0;
	data->num_philo = ft_atoi_overflow(argv[1], &overflow_flag);
	data->time_to_die = ft_atoi_overflow(argv[2], &overflow_flag);
	data->time_to_eat = ft_atoi_overflow(argv[3], &overflow_flag);
	data->time_to_sleep = ft_atoi_overflow(argv[4], &overflow_flag);
	if (argc == 6)
	{
		data->must_eat = ft_atoi_overflow(argv[5], &overflow_flag);
		data->must_eat_specified = true;
	}
	else
	{
		data->must_eat_specified = false;
		data->must_eat = 1;
	}
	return (is_input_correct(data, &overflow_flag));
}
