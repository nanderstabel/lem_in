/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_graph_cg.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:43:20 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/17 17:52:23 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				set_global_vars(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->all_paths)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	lem_in->index = 0;
	lem_in->temp_que_list = lem_in->all_paths;
	lem_in->nturns = __INT_MAX__;
	lem_in->index = 0;
	return (SUCCESS);
}

t_bool				set_graph_vars(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->graph_vars.source_ants = lem_in->nants;
	lem_in->graph_vars.sink_ants = 0;
	lem_in->graph_vars.turns = 0;
	return (SUCCESS);
}

t_bool				get_graph(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->que_list = lem_in->temp_que_list;
	while (lem_in->que_list)
	{
		if ((size_t)((t_adlist *)((t_adlist *)\
			lem_in->que_list->address))->address != lem_in->index)
		{
			lem_in->temp_que_list = lem_in->que_list;
			lem_in->index = (size_t)((t_adlist *)((t_adlist *)\
				lem_in->que_list->address))->address;
			return (SUCCESS);
		}
		lem_in->que_list = lem_in->que_list->next;
	}
	return (FAIL);
}
