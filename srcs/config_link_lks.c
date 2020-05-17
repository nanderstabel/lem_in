/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config_link_lks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:02:46 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/17 23:38:26 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				store_link(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->link_pointer = (void *)ft_strjoin(((t_elem *)\
		(lem_in->room_pointers[first_room]))->name, "-");
	lem_in->link_pointer = (void *)ft_append((char **)&lem_in->link_pointer, \
		((t_elem *)(lem_in->room_pointers[second_room]))->name);
	lem_in->link_pointer = (void *)ft_hash_table_add(lem_in->all_links, \
		(char *)lem_in->link_pointer, \
		get_edge());
	if (lem_in->link_pointer)
	{
		((t_edge *)((t_elem *)lem_in->link_pointer)->content)->id = \
			((t_elem *)lem_in->link_pointer);
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				add_room_to_link(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!((t_edge *)((t_elem *)lem_in->link_pointer)->content) || \
		!((t_vertex *)((t_elem *)(lem_in->room_pointers[first_room]))->content)\
		|| !((t_vertex *)((t_elem *)\
		(lem_in->room_pointers[second_room]))->content))
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	((t_edge *)((t_elem *)lem_in->link_pointer)->content)->next = \
		((t_vertex *)((t_elem *)(lem_in->room_pointers[second_room]))->content);
	return (SUCCESS);
}

t_bool				add_link_to_room(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_vertex *)((t_elem *)(lem_in->room_pointers[first_room]))->content)\
		->links)
		ft_lstadd(&((t_vertex *)((t_elem *)\
			(lem_in->room_pointers[first_room]))->content)->links, \
			ft_lstnew_ptr(((t_edge *)((t_elem *)lem_in->link_pointer)\
			->content), 0));
	else
		((t_vertex *)((t_elem *)(lem_in->room_pointers[first_room]))->content)\
			->links = ft_lstnew_ptr(((t_edge *)((t_elem *)\
			lem_in->link_pointer)->content), 0);
	return (SUCCESS);
}

t_bool				swap_rooms(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->index)
		return (FAIL);
	ft_swap(&lem_in->room_pointers[first_room], \
		&lem_in->room_pointers[second_room]);
	++lem_in->index;
	return (SUCCESS);
}

t_bool				set_line(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	free(lem_in->room_pointers);
	lem_in->room_pointers = NULL;
	lem_in->link_pointer = NULL;
	ft_skip_line(&lem_in->input_string_copy);
	while (*lem_in->input_string_copy == '#')
		ft_skip_line(&lem_in->input_string_copy);
	if (*lem_in->input_string_copy == 0)
		return (FAIL);
	return (SUCCESS);
}
