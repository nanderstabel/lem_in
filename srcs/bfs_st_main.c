/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_st_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 14:16:39 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/19 09:44:29 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				que_remain_bfs_st(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->temp_que_list)
	{
		lem_in->current_room = ((t_vertex *)(lem_in->temp_que_list->address));
		lem_in->temp = lem_in->current_room->links;
		return (SUCCESS);
	}
	ft_addr_lstdel(&lem_in->que_list);
	return (FAIL);
}
