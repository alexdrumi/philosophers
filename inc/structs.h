/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <pthread.h>
# include <sys/time.h>

typedef enum iiinum
{
	true,
	false
}	t_bool;

typedef struct philosopher
{
	int					n;
	int					second_fork;
	int					first_fork;
	int					must_eat;
	int					time_to_eat;
	int					time_to_sleep;
	int					last_meal;
	t_bool				is_finished;
	pthread_mutex_t		last_meal_m;
	pthread_mutex_t		is_finished_m;
	struct data			*data_ptr;
}				t_philosopher;

typedef struct data
{
	int					num_philo;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					which_died;
	int					time_of_death;
	int					start_time;
	int					must_eat;
	int					time_to_wait;
	pthread_mutex_t		time_of_death_m;
	pthread_mutex_t		which_died_m;
	pthread_mutex_t		can_write_m;
	pthread_mutex_t		*forks;
	t_philosopher		*philos;
	t_bool				someone_died;
	t_bool				must_eat_specified;
}				t_data;

#endif