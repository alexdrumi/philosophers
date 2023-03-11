/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat_sleep_think_cycle.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2021/12/20 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/eat_sleep_think_cycle.h"

static void	small_sleep(t_philosopher *philo, int philo_time)
{
	int	current_time;
	int	time_to_sleep;

	current_time = get_elapsed_time(philo);
	if (philo_time < 125)
	{
		time_to_sleep = philo_time;
	}
	else
	{
		time_to_sleep = 125;
	}
	while (get_elapsed_time(philo) - current_time < philo_time)
	{
		usleep(time_to_sleep);
	}
}

static void	eating(t_philosopher *philo)
{
	int	current_time;

	pthread_mutex_lock(&philo->data_ptr->forks[philo->second_fork]);
	philo_display_msg(philo, "has taken a fork\n", get_elapsed_time(philo));
	pthread_mutex_lock(&philo->data_ptr->forks[philo->first_fork]);
	philo_display_msg(philo, "has taken a fork\n", get_elapsed_time(philo));
	current_time = get_elapsed_time(philo);
	philo_display_msg(philo, "is eating\n", current_time);
	pthread_mutex_lock(&philo->last_meal_m);
	philo->last_meal = current_time;
	pthread_mutex_unlock(&philo->last_meal_m);
	if (philo->data_ptr->must_eat_specified == true)
	{
		philo->must_eat = philo->must_eat - 1;
	}
	small_sleep(philo, philo->time_to_eat);
	pthread_mutex_unlock(&philo->data_ptr->forks[philo->first_fork]);
	pthread_mutex_unlock(&philo->data_ptr->forks[philo->second_fork]);
}

static void	sleeping(t_philosopher	*philo)
{
	int	current_time;
	int	available_time;
	int	last_meal_plus_sleep;

	current_time = get_elapsed_time(philo);
	pthread_mutex_lock(&philo->last_meal_m);
	available_time = philo->last_meal + philo->data_ptr->time_to_die;
	last_meal_plus_sleep = philo->last_meal + philo->time_to_sleep;
	pthread_mutex_unlock(&philo->last_meal_m);
	if (available_time < last_meal_plus_sleep || available_time < get_elapsed_time(philo))
	{
		set_to_dead(philo, available_time);
	}
	else
	{
		philo_display_msg(philo, "is sleeping\n", get_elapsed_time(philo));
		small_sleep(philo, philo->time_to_sleep);
	}	
}

static void	thinking(t_philosopher	*philo)
{
	philo_display_msg(philo, "is thinking\n", get_elapsed_time(philo));
	small_sleep(philo, 3);
}

void	*eat_sleep_think_cycle(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->n % 2 == 1)
	{
		usleep(50);
	}
	while (philo->must_eat)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	set_finished(philo);
	return (NULL);
}
