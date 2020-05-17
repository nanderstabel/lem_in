/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_rooms_rms.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 18:54:45 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/17 21:37:17 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				initialize_table_rms(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->nrooms > MAX_MALLOC_SIZE)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	if (lem_in->flags & ROOMS_O)
		lem_in->all_rooms = ft_malloc_hash_table(lem_in->nrooms,\
			"Rooms", FORMAT_LEFT);
	else
		lem_in->all_rooms = ft_malloc_hash_table(lem_in->nrooms, "Rooms", NULL);
	lem_in->room_pointers = (void **)ft_memalloc(sizeof(void *));
	if (lem_in->all_rooms && lem_in->room_pointers)
		return (SUCCESS);
	return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
}

t_bool				set_line_rms(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->input_string_copy = lem_in->input_string;
	if (lem_in->input_string_copy == NULL)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	ft_skip_line(&lem_in->input_string_copy);
	return (SUCCESS);
}

t_bool				get_type(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_isprior(lem_in->input_string_copy, '-', '\n'))
	{
		free(lem_in->room_pointers);
		lem_in->room_pointers = NULL;
		return (FAIL);
	}
	lem_in->room_type = standard;
	while (*lem_in->input_string_copy == '#')
	{
		if (ft_strnstr(lem_in->input_string_copy, "##start\n", 9))
			lem_in->room_type = source;
		else if (ft_strnstr(lem_in->input_string_copy, "##end\n", 7))
			lem_in->room_type = sink;
		ft_skip_line(&lem_in->input_string_copy);
	}
	return (SUCCESS);
}

t_bool				store_room(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->room_pointers[first_room] = ft_hash_table_add(lem_in->all_rooms, \
		ft_strsub(lem_in->input_string_copy, 0, \
		ft_nchar(lem_in->input_string_copy, ' ') - 1), get_vertex());
	if (lem_in->room_pointers[first_room])
	{
		((t_vertex *)((t_elem *)(lem_in->room_pointers[first_room]))\
			->content)->id = ((t_elem *)(lem_in->room_pointers[first_room]));
		if (lem_in->room_type == source)
			lem_in->source = ((t_vertex *)((t_elem *)\
				(lem_in->room_pointers[first_room]))->content);
		else if (lem_in->room_type == sink)
			lem_in->sink = ((t_vertex *)((t_elem *)\
				(lem_in->room_pointers[first_room]))->content);
		((t_vertex *)((t_elem *)(lem_in->room_pointers[first_room]))\
			->content)->type = lem_in->room_type;
		ft_skip_line(&lem_in->input_string_copy);
		return (SUCCESS);
	}
	return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
}
