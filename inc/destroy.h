/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY_H
# define DESTROY_H
# include "structs.h"

t_bool	destroy_mutexes_succeeded(t_data	*data);
void	destroy_philos(t_data *data);
void	destroy_forks(t_data *data);

#endif