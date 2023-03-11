/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2021/12/20 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"
#include "inc/structs.h"
#include "inc/parse.h"
#include "inc/print.h"
#include "inc/init_philos.h"
#include "inc/init_mutexes.h"
#include "inc/destroy.h"
#include "inc/init_threads.h"

static t_bool	initializations_succeeded(t_data *data)
{
	if (init_philos_succeeded(data) == false)
	{
		ft_putstr(INIT_PHILO_ERROR_MSG);
		return (false);
	}
	if (init_mutexes_succeeded(data) == false)
	{
		destroy_forks(data);
		destroy_philos(data);
		ft_putstr(INIT_MUTEXES_ERROR_MSG);
		return (false);
	}
	if (init_threads_succeeded(data) == false)
	{
		destroy_forks(data);
		destroy_philos(data);
		ft_putstr(INIT_THREAD_ERROR_MSG);
		return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{	
	t_data	data;

	if (parse_succeeded(argc, argv, &data) == false)
	{
		ft_putstr(INCORRECT_INPUT_MSG);
		return (1);
	}
	if (initializations_succeeded(&data) == false)
	{
		return (1);
	}
	if (destroy_mutexes_succeeded(&data) == false)
	{
		ft_putstr(DESTROY_MUTEX_ERROR_MSG);
		return (1);
	}
	destroy_philos(&data);
	return (0);
}
