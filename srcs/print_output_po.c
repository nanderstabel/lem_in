/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_output_po.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:36:08 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 19:36:08 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				print_input(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & BLANK_O)
		return (FAIL);
	ft_printf("%s\n", lem_in->input_string);
	return (SUCCESS);
}

t_bool				sort_paths(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->index = 1;
	ft_addr_lstsrt(&lem_in->all_paths, sort_by_length);
	return (SUCCESS);
}

t_bool				spawn_ants(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->que_list = lem_in->all_paths;
	while (lem_in->que_list && lem_in->index <= lem_in->nants)
	{
		if ((size_t)((t_adlist *)((t_adlist *)\
			lem_in->que_list->address))->next->address <= lem_in->nturns)
		{
			lem_in->current_ant = get_ant(lem_in->index);
			lem_in->current_ant->location = ((t_adlist *)((t_adlist *)\
				lem_in->que_list->address))->next->next;
			if (lem_in->all_ants)
				ft_addr_lstapp(&lem_in->all_ants, \
					ft_addr_lstnew((void *)lem_in->current_ant));
			else
				lem_in->all_ants = ft_addr_lstnew((void *)lem_in->current_ant);
			++lem_in->index;
		}
		lem_in->que_list = lem_in->que_list->next;
	}
	return (SUCCESS);
}

static void			loop_paths(t_project *lem_in)
{
	lem_in->que_list = lem_in->all_ants;
	while (lem_in->que_list)
	{
		((t_ant *)lem_in->que_list->address)->location = \
			((t_ant *)lem_in->que_list->address)->location->next;
		ft_printf("%s-%s", ((t_ant *)lem_in->que_list->address)->name, \
			((t_vertex *)((t_ant *)lem_in->que_list->address)\
			->location->address)->id->name);
		if (lem_in->que_list->next)
			ft_putchar(' ');
		if ((t_vertex *)((t_ant *)\
			lem_in->que_list->address)->location->address == lem_in->sink)
		{
			free(((t_ant *)lem_in->que_list->address));
			if (lem_in->que_list == lem_in->all_ants)
				lem_in->all_ants = lem_in->que_list->next;
			else
				lem_in->temp_que_list->next = lem_in->que_list->next;
		}
		else
			lem_in->temp_que_list = lem_in->que_list;
		lem_in->que_list = lem_in->que_list->next;
	}
}

t_bool				move_all_ants(t_project *lem_in)
{
	static int count;

	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->all_ants)
		return (FAIL);
	if (lem_in->flags & COUNT_O)
		ft_printf("Turn %-5i:\t", 1 + count);
	++count;
	loop_paths(lem_in);
	--lem_in->nturns;
	ft_putchar(10);
	return (SUCCESS);
}
