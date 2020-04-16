/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_links.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:56:15 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 15:59:41 by nstabel       ########   odam.nl         */
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
		ft_addr_lstadd(&((t_vertex *)((t_elem *)\
			(lem_in->room_pointers[first_room]))->content)->links, \
			ft_addr_lstnew(((t_edge *)((t_elem *)lem_in->link_pointer)\
			->content)));
	else
		((t_vertex *)((t_elem *)(lem_in->room_pointers[first_room]))->content)\
			->links = ft_addr_lstnew(((t_edge *)((t_elem *)\
			lem_in->link_pointer)->content));
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

static void			get_transitions(t_mconfig **mconfig)
{
	t_state		**transitions;

	transitions = (*mconfig)->transitions;
	transitions[s_install_machine_lks][FAIL] = s_uninstall_machine_lks;
	transitions[s_install_machine_lks][SUCCESS] = s_initialize_table_lks;
	transitions[s_initialize_table_lks][FAIL] = s_uninstall_machine_lks;
	transitions[s_initialize_table_lks][SUCCESS] = s_save_roomnames;
	transitions[s_save_roomnames][FAIL] = s_uninstall_machine_lks;
	transitions[s_save_roomnames][SUCCESS] = s_find_first_room;
	transitions[s_find_first_room][FAIL] = s_uninstall_machine_lks;
	transitions[s_find_first_room][SUCCESS] = s_find_second_room;
	transitions[s_find_second_room][FAIL] = s_uninstall_machine_lks;
	transitions[s_find_second_room][SUCCESS] = s_store_link;
	transitions[s_store_link][FAIL] = s_set_line;
	transitions[s_store_link][SUCCESS] = s_add_room_to_link;
	transitions[s_add_room_to_link][FAIL] = s_uninstall_machine_lks;
	transitions[s_add_room_to_link][SUCCESS] = s_add_link_to_room;
	transitions[s_add_link_to_room][FAIL] = s_uninstall_machine_lks;
	transitions[s_add_link_to_room][SUCCESS] = s_swap_rooms;
	transitions[s_swap_rooms][FAIL] = s_set_line;
	transitions[s_swap_rooms][SUCCESS] = s_store_link;
	transitions[s_set_line][FAIL] = s_print_tables_lks;
	transitions[s_set_line][SUCCESS] = s_save_roomnames;
	transitions[s_print_tables_lks][FAIL] = s_uninstall_machine_lks;
	transitions[s_print_tables_lks][SUCCESS] = s_uninstall_machine_lks;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_lks] = NULL;
	(*mconfig)->events[s_initialize_table_lks] = initialize_table_lks;
	(*mconfig)->events[s_save_roomnames] = save_roomnames;
	(*mconfig)->events[s_find_first_room] = find_first_room;
	(*mconfig)->events[s_find_second_room] = find_second_room;
	(*mconfig)->events[s_store_link] = store_link;
	(*mconfig)->events[s_add_room_to_link] = add_room_to_link;
	(*mconfig)->events[s_add_link_to_room] = add_link_to_room;
	(*mconfig)->events[s_swap_rooms] = swap_rooms;
	(*mconfig)->events[s_set_line] = set_line;
	(*mconfig)->events[s_print_tables_lks] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_lks);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				store_links(t_project *lem_in)
{
	t_machine	*machine;

	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (lem_in->error)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}
