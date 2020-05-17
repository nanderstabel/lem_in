/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_rooms_links_augp.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 15:18:25 by mgross        #+#    #+#                 */
/*   Updated: 2020/05/17 23:33:28 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				clear_rooms_on_graph_augp(t_project *lem_in)
{
	size_t		index;

	index = 0;
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->level)
	{
		while (index < lem_in->all_rooms->size)
		{
			((t_vertex*)(lem_in->all_rooms->elem[index]->content))->level = 0;
			if (lem_in->round_temp)
			{
				((t_vertex*)(lem_in->all_rooms->elem[index]->content))\
				->visited = 0;
			}
			index++;
		}
	}
	return (SUCCESS);
}

t_bool				clear_links_on_graph_augp(t_project *lem_in)
{
	size_t		index;
	t_list	*temp;

	temp = lem_in->aug_path_links;
	index = 0;
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->level)
	{
		while (index < lem_in->all_links->size)
		{
			((t_edge*)(lem_in->all_links->elem[index]->content))->capacity = 1;
			((t_edge*)(lem_in->all_links->elem[index]->content))->visited = 0;
			index++;
		}
		while (temp)
		{
			((t_edge*)(lem_in->all_links->elem[((long long)(temp->content))]\
			->content))->capacity = 0;
			temp = temp->next;
		}
	}
	return (SUCCESS);
}
