/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2021/12/20 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "inc/print.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

static void	recursive(long int num)
{
	char	digit;

	if (num < 10)
	{
		digit = num + '0';
		ft_putchar_fd(digit, 1);
	}
	else
	{
		recursive(num / 10);
		digit = (num % 10) + '0';
		ft_putchar_fd(digit, 1);
	}
}

static void	ft_putnbr_fd(long long int n)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = num * (-1);
	}
	recursive(num);
}

void	ft_putstr(char *str)
{
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
}

void	philo_display_msg(t_philosopher *philo, char *s, int time)
{
	pthread_mutex_lock(&philo->data_ptr->can_write_m);
	ft_putnbr_fd((long long)time);
	write(1, " ", 1);
	ft_putnbr_fd(philo->n);
	write(1, " ", 1);
	write(1, s, ft_strlen(s));
	pthread_mutex_unlock(&philo->data_ptr->can_write_m);
}
