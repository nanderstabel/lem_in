/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_update_bfs_st.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 14:17:02 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/17 15:06:50 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				edge_list_remain_bfs_st(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->temp)
		return (SUCCESS);
	lem_in->temp_que_list = lem_in->temp_que_list->next;
	return (FAIL);
}

t_bool				update_level_que_bfs_st(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_edge*)(lem_in->temp->address))->next != lem_in->source)
	{
		((t_edge*)(lem_in->temp->address))->next->level =
		lem_in->current_room->level + 1;
	}
	if (((t_edge*)(lem_in->temp->address))->next != lem_in->sink)
		ft_addr_lstapp(&lem_in->que_list,
		ft_addr_lstnew((void*)((t_edge*)(lem_in->temp->address))->next));
	lem_in->temp = lem_in->temp->next;
	return (SUCCESS);
}

t_bool				vertex_has_level_bfs_st(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_edge*)(lem_in->temp->address))->next->level == 0)
		return (FAIL);
	lem_in->temp = lem_in->temp->next;
	return (SUCCESS);
}

t_bool				capacity_available_bfs_st(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((((t_edge*)(lem_in->temp->address))->capacity == 1) ||
	(((t_edge*)(lem_in->temp->address))->capacity == 0 &&
	((t_edge*)(lem_in->temp->address))->visited == 1))
	{
		lem_in->level++;
		return (SUCCESS);
	}
	lem_in->temp = lem_in->temp->next;
	return (FAIL);
}
