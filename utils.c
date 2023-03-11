/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/structs.h"
#include "inc/utils.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		return (0);
	}
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

t_bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

int	get_max(int x, int y)
{
	if (x > y)
	{
		return (x);
	}
	else
	{
		return (y);
	}
}

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	get_elapsed_time(t_philosopher *philo)
{
	int	current_time;

	current_time = get_time() - philo->data_ptr->start_time;
	return (current_time);
}
