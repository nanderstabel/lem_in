/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_main.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:57:25 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/17 11:30:30 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				que_list_remain_bfs(t_project *lem_in)
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
