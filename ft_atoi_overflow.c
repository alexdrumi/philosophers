/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_overflow.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2021/12/20 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_atoi_overflow.h"

static int	ft_is_whitespace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

static int	is_all_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static void	loop_over_space_and_sign(const char *str, long int *neg, int *i)
{
	while (str[*i] != '\0' && ft_is_whitespace(str[*i]))
		(*i)++;
	if (str[*i] != '\0' && (str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			*neg = -(*neg);
		(*i)++;
	}
}

static void	set_values(long int *neg, long int *result,
	long int *check, int *correct)
{
	*result = 0;
	*neg = 1;
	*check = 0;
	*correct = 0;
}

int	ft_atoi_overflow(const char *str, int *flag)
{
	int				i;
	int				correct;
	long int		neg;
	long int		result;
	long int		check;

	i = 0;
	set_values(&neg, &result, &check, &correct);
	loop_over_space_and_sign(str, &neg, &i);
	if (is_all_digit(&str[i]) == 0)
		*flag = 1;
	while (str[i] != '\0' && ft_isdigit(str[i]) == true && *flag == 0)
	{
		correct = 1;
		check = result * 10 + (str[i] - '0');
		if ((check * neg) > INT_MAX || (check * neg) < INT_MIN)
			*flag = 1;
		result = check;
		i++;
	}
	if (correct == 0)
		*flag = 1;
	return (result * neg);
}
