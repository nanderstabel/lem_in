/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_update_bfs.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: zitzak <zitzak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:53:19 by zitzak        #+#    #+#                 */
/*   Updated: 2020/04/16 14:05:50 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				update_level_and_que_bfs(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_edge*)(lem_in->temp->address))->next != lem_in->sink)
	{
		((t_edge*)(lem_in->temp->address))->next->level =
		lem_in->current_room->level + 1;
	}
	if (((t_edge*)(lem_in->temp->address))->next != lem_in->source)
		ft_addr_lstapp(&lem_in->que_list,
		ft_addr_lstnew((void*)((t_edge*)(lem_in->temp->address))->next));
	lem_in->temp = lem_in->temp->next;
	return (SUCCESS);
}

t_bool				vertex_has_level_bfs(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_edge*)(lem_in->temp->address))->next->level == 0)
		return (FAIL);
	lem_in->temp = lem_in->temp->next;
	return (SUCCESS);
}

t_bool				capacity_available_bfs(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_edge*)(lem_in->temp->address))->capacity == 1 &&
	!((t_edge*)(lem_in->temp->address))->next->visited)
	{
		lem_in->level++;
		return (SUCCESS);
	}
	lem_in->temp = lem_in->temp->next;
	return (FAIL);
}

t_bool				edge_list_remain_bfs(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->temp)
		return (SUCCESS);
	lem_in->temp_que_list = lem_in->temp_que_list->next;
	return (FAIL);
}
