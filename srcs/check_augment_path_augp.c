/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_augment_path_augp.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 15:25:00 by mgross        #+#    #+#                 */
/*   Updated: 2020/05/17 23:33:28 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list			*check(t_project *lem_in, size_t index)
{
	t_list		*temp;

	temp = lem_in->aug_path_links;
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (temp)
	{
		if ((size_t)temp->content == index)
			break ;
		temp = temp->next;
	}
	return (temp);
}

static void				print_debug(t_project *lem_in)
{
	ft_printf("\t\t--Potential next room %s level %d visited %d - link \
visited %d capacity %d\n", ((t_edge*)(lem_in->temp->content))
	->next->id->name, ((t_edge*)(lem_in->temp->content))->next->level,
	((t_edge*)(lem_in->temp->content))->next->visited,
	((t_edge*)(lem_in->temp->content))->visited,
	((t_edge*)(lem_in->temp->content))->capacity);
}

t_bool					check_augment_path_augp(t_project *lem_in)
{
	t_list		*temp;

	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->temp = lem_in->current_room->links;
	while (lem_in->temp)
	{
		temp = check(lem_in, ((t_edge*)(lem_in->temp->content))->id->index);
		if (lem_in->flags & AUGMENT_O)
			print_debug(lem_in);
		if (((((t_edge*)(lem_in->temp->content))->capacity == 0 &&
		((t_edge*)(lem_in->temp->content))->next->visited == 1) ||
		(((t_edge*)(lem_in->temp->content))->capacity == 0 &&
		((t_edge*)(lem_in->temp->content))->next == lem_in->sink)) && (!temp))
		{
			lem_in->current_link = ((t_edge*)(lem_in->temp->content));
			lem_in->round_temp++;
			lem_in->round_nr++;
			return (SUCCESS);
		}
		lem_in->temp = lem_in->temp->next;
	}
	if (lem_in->flags & AUGMENT_O)
		ft_printf("ERROR - Failed to augment\n");
	return (FAIL);
}
