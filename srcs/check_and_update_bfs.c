/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_update_bfs.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:53:19 by mgross        #+#    #+#                 */
/*   Updated: 2020/05/17 23:44:12 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				update_level_que_bfs(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_edge*)(lem_in->temp->content))->next != lem_in->sink)
	{
		((t_edge*)(lem_in->temp->content))->next->level =
		lem_in->current_room->level + 1;
	}
	if (((t_edge*)(lem_in->temp->content))->next != lem_in->source)
		ft_lstapp(&lem_in->que_list,
		ft_lstnew_ptr((void*)((t_edge*)(lem_in->temp->content))->next, 0));
	lem_in->temp = lem_in->temp->next;
	return (SUCCESS);
}

t_bool				vertex_has_level_bfs(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_edge*)(lem_in->temp->content))->next->level == 0)
		return (FAIL);
	lem_in->temp = lem_in->temp->next;
	return (SUCCESS);
}

t_bool				capacity_available_bfs(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_edge*)(lem_in->temp->content))->capacity == 1 &&
	!((t_edge*)(lem_in->temp->content))->next->visited)
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
