/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_overflow.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOI_OVERFLOW_H
# define FT_ATOI_OVERFLOW_H
# include "utils.h"
# include <limits.h>

int	ft_atoi_overflow(const char *str, int *flag);

#endif