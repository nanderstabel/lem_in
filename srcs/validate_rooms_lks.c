/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_rooms_lks.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:02:14 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 19:02:14 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				initialize_table_lks(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->nlinks > MAX_MALLOC_SIZE)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	if (lem_in->flags & LINKS_O)
		lem_in->all_links = ft_malloc_hash_table(lem_in->nlinks * 2, "Links", \
			FORMAT_LEFT);
	else
		lem_in->all_links = ft_malloc_hash_table(lem_in->nlinks * 2, "Links", \
			NULL);
	if (lem_in->all_links)
		return (SUCCESS);
	return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
}

t_bool				save_roomnames(t_project *lem_in)
{
	size_t	len;

	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->index = 0;
	len = ft_nchar(lem_in->input_string_copy, '\n') - 1;
	if (!len)
		len = ft_strlen(lem_in->input_string_copy);
	lem_in->room_pointers = (void **)ft_strnsplit(lem_in->input_string_copy, \
		'-', len);
	if (!lem_in->room_pointers)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

t_bool				find_first_room(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->string = lem_in->room_pointers[first_room];
	lem_in->room_pointers[first_room] = \
		(void *)ft_hash_table_get(lem_in->all_rooms, lem_in->string);
	free(lem_in->string);
	if (!lem_in->room_pointers[first_room])
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

t_bool				find_second_room(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->string = lem_in->room_pointers[second_room];
	lem_in->room_pointers[second_room] = \
		(void *)ft_hash_table_get(lem_in->all_rooms, lem_in->string);
	free(lem_in->string);
	if (!lem_in->room_pointers[second_room])
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}
