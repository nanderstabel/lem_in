/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ant.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:33:36 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 19:33:36 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant			*get_ant(size_t nbr)
{
	t_ant		*ant;

	ant = (t_ant *)ft_memalloc(sizeof(t_ant));
	ant->name = ft_itoa((int)nbr);
	ant->name = ft_insert(&ant->name, "L", 0);
	return (ant);
}
