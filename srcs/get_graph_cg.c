/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_graph_cg.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:45:27 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 19:45:27 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				delete_excess_paths(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->que_list = lem_in->all_paths;
	while (lem_in->que_list)
	{
		if ((size_t)((t_adlist *)((t_adlist *)\
			lem_in->que_list->address))->address != lem_in->round_nr)
			ft_addr_lstdel((t_adlist **)&lem_in->que_list->address);
		lem_in->que_list = lem_in->que_list->next;
	}
	return (SUCCESS);
}

t_bool				clean_pathslist(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (!lem_in->all_paths->address)
	{
		lem_in->que_list = lem_in->all_paths;
		lem_in->all_paths = lem_in->all_paths->next;
		ft_addr_lstdelone(&lem_in->que_list);
	}
	lem_in->que_list = lem_in->all_paths;
	while (lem_in->que_list->next)
	{
		if (!lem_in->que_list->next->address)
		{
			ft_addr_lstdel(&lem_in->que_list->next);
			break ;
		}
		lem_in->que_list = lem_in->que_list->next;
	}
	return (SUCCESS);
}

t_bool				finish_graph_calculation(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->graph_vars.sink_ants < lem_in->nants)
		return (FAIL);
	return (SUCCESS);
}

t_bool				calculate_turn(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->que_list = lem_in->temp_que_list;
	while (lem_in->que_list)
	{
		if ((size_t)((t_adlist *)((t_adlist *)\
			lem_in->que_list->address))->address != lem_in->index)
			break ;
		if (lem_in->graph_vars.turns + 1 < (size_t)((t_adlist *)((t_adlist *)\
			lem_in->que_list->address))->next->address)
			--(lem_in->graph_vars.source_ants);
		else
			++(lem_in->graph_vars.sink_ants);
		lem_in->que_list = lem_in->que_list->next;
	}
	++(lem_in->graph_vars.turns);
	return (SUCCESS);
}

t_bool				update_stored_graph(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->nturns > lem_in->graph_vars.turns)
	{
		lem_in->nturns = lem_in->graph_vars.turns;
		lem_in->round_nr = lem_in->index;
	}
	return (SUCCESS);
}
