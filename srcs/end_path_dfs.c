/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_path_dfs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:29:06 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 19:29:06 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				delete_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	ft_addr_lstdel(&lem_in->current_path);
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tDeleted path\n");
	return (FAIL);
}

t_bool				remove_room(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->current_room || !lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	lem_in->temp = lem_in->current_room->selected;
	((t_edge*)(lem_in->temp->address))->capacity = 1;
	((t_edge*)(lem_in->temp->address))->visited = 0;
	lem_in->que_list = lem_in->current_path;
	lem_in->current_path = lem_in->current_path->next;
	ft_addr_lstdelone(&lem_in->que_list);
	--lem_in->index;
	lem_in->current_room->selected = lem_in->current_room->selected->next;
	return (SUCCESS);
}

t_bool				traverse_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tTravelled from %s, to ", lem_in->current_room->id->name);
	if (!((t_edge*)(lem_in->temp->address))->next || !lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	lem_in->current_room = ((t_edge*)(lem_in->temp->address))->next;
	if (lem_in->flags & DFS_O)
		ft_printf("%s\n", lem_in->current_room->id->name);
	((t_edge*)(lem_in->temp->address))->capacity = 0;
	((t_edge*)(lem_in->temp->address))->visited = 1;
	ft_addr_lstadd(&lem_in->current_path, \
		ft_addr_lstnew((void *)lem_in->current_room));
	++lem_in->index;
	return (SUCCESS);
}

t_bool				check_sink(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->current_room != lem_in->sink)
	{
		lem_in->current_room->visited = 1;
		return (FAIL);
	}
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tFound sink\n");
	return (SUCCESS);
}

t_bool				store_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	lem_in->current_path = ft_addr_lstrev(lem_in->current_path);
	ft_addr_lstadd(&lem_in->current_path, \
		ft_addr_lstnew((void *)lem_in->index));
	ft_addr_lstadd(&lem_in->current_path, \
		ft_addr_lstnew((void *)lem_in->round_nr));
	if (lem_in->all_paths)
		ft_addr_lstadd(&lem_in->all_paths, \
			ft_addr_lstnew(lem_in->current_path));
	else
		lem_in->all_paths = ft_addr_lstnew(lem_in->current_path);
	return (SUCCESS);
}
