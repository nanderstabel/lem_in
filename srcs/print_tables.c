/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tables.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 11:08:09 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/19 11:08:09 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				print_tables(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (FLAGS & ROOMS_O)
	{
		if (!ALL_ROOMS)
			return (FAIL);
		ft_hash_table_update(ALL_ROOMS, vertex_columns);
		ft_puttbl(ALL_ROOMS);
	}
	if (FLAGS & LINKS_O)
	{
		if (!ALL_LINKS)
			return (FAIL);
		ft_hash_table_update(ALL_LINKS, edge_columns);
		ft_puttbl(ALL_LINKS);
	}
	return (SUCCESS);
}
