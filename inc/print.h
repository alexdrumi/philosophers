/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include "structs.h"
# include <unistd.h>
# include "utils.h"

void	philo_display_msg(t_philosopher *philo, char *s, int time);
void	ft_putstr(char *str);

#endif