/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_links.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:56:15 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/19 11:10:48 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				initialize_table_lks(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (NLINKS > MAX_MALLOC_SIZE)
		return (ERROR_LOG(FAIL));
	if (FLAGS & LINKS_O)
		ALL_LINKS = ft_malloc_hash_table(NLINKS * 2, "Links", FORMAT_LEFT);
	else
		ALL_LINKS = ft_malloc_hash_table(NLINKS * 2, "Links", NULL);
	if (ALL_LINKS)
		return (SUCCESS);
	return (ERROR_LOG(FAIL));
}

t_bool				save_roomnames(t_project *lem_in)
{
	size_t	len;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	INDEX = 0;
	len = ft_nchar(INPUT_CPY, '\n') - 1;
	if (!len)
		len = ft_strlen(INPUT_CPY);
	ROOM_POINTERS = (void **)ft_strnsplit(INPUT_CPY, '-', len);
	if (!ROOM_POINTERS)
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

t_bool				find_first_room(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	STRING = ROOM_POINTER(first_room);
	ROOM_POINTER(first_room) = (void *)ft_hash_table_get(ALL_ROOMS, STRING);
	free(STRING);
	if (!ROOM_POINTER(first_room))
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

t_bool				find_second_room(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	STRING = ROOM_POINTER(second_room);
	ROOM_POINTER(second_room) = (void *)ft_hash_table_get(ALL_ROOMS, STRING);
	free(STRING);
	if (!ROOM_POINTER(second_room))
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

t_bool				store_link(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	LINK_POINTER = (void *)ft_strjoin(ROOM_ELEM(first_room)->name, "-");
	LINK_POINTER = (void *)ft_append((char **)&LINK_POINTER, \
		ROOM_ELEM(second_room)->name);
	LINK_POINTER = (void *)ft_hash_table_add(ALL_LINKS, (char *)LINK_POINTER, \
		get_edge());
	if (LINK_POINTER)
	{
		LINK_CONTENT->id = LINK_ELEM;
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				add_room_to_link(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!LINK_CONTENT || !ROOM_CONTENT(first_room) || \
		!ROOM_CONTENT(second_room))
		return (ERROR_LOG(FAIL));
	LINK_CONTENT->next = ROOM_CONTENT(second_room);
	return (SUCCESS);
}

t_bool				add_link_to_room(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ROOM_CONTENT(first_room)->links)
		ft_addr_lstadd(&ROOM_CONTENT(first_room)->links, \
			ft_addr_lstnew(LINK_CONTENT));
	else
		ROOM_CONTENT(first_room)->links = ft_addr_lstnew(LINK_CONTENT);
	return (SUCCESS);
}

t_bool				swap_rooms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (INDEX)
		return (FAIL);
	ft_swap(&ROOM_POINTER(first_room), &ROOM_POINTER(second_room));
	++INDEX;
	return (SUCCESS);
}

t_bool				set_line(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	free(ROOM_POINTERS);
	ROOM_POINTERS = NULL;
	LINK_POINTER = NULL;
	ft_skip_line(&INPUT_CPY);
	while (*INPUT_CPY == '#')
		ft_skip_line(&INPUT_CPY);
	if (*INPUT_CPY == 0)
		return (FAIL);
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_lks][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_install_machine_lks][SUCCESS] = s_initialize_table_lks;
	TRANSITIONS[s_initialize_table_lks][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_initialize_table_lks][SUCCESS] = s_save_roomnames;
	TRANSITIONS[s_save_roomnames][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_save_roomnames][SUCCESS] = s_find_first_room;
	TRANSITIONS[s_find_first_room][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_find_first_room][SUCCESS] = s_find_second_room;
	TRANSITIONS[s_find_second_room][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_find_second_room][SUCCESS] = s_store_link;
	TRANSITIONS[s_store_link][FAIL] = s_set_line;
	TRANSITIONS[s_store_link][SUCCESS] = s_add_room_to_link;
	TRANSITIONS[s_add_room_to_link][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_add_room_to_link][SUCCESS] = s_add_link_to_room;
	TRANSITIONS[s_add_link_to_room][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_add_link_to_room][SUCCESS] = s_swap_rooms;
	TRANSITIONS[s_swap_rooms][FAIL] = s_set_line;
	TRANSITIONS[s_swap_rooms][SUCCESS] = s_store_link;
	TRANSITIONS[s_set_line][FAIL] = s_print_tables_lks;
	TRANSITIONS[s_set_line][SUCCESS] = s_save_roomnames;
	TRANSITIONS[s_print_tables_lks][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_print_tables_lks][SUCCESS] = s_uninstall_machine_lks;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_lks] = NULL;
	EVENTS[s_initialize_table_lks] = initialize_table_lks;
	EVENTS[s_save_roomnames] = save_roomnames;
	EVENTS[s_find_first_room] = find_first_room;
	EVENTS[s_find_second_room] = find_second_room;
	EVENTS[s_store_link] = store_link;
	EVENTS[s_add_room_to_link] = add_room_to_link;
	EVENTS[s_add_link_to_room] = add_link_to_room;
	EVENTS[s_swap_rooms] = swap_rooms;
	EVENTS[s_set_line] = set_line;
	EVENTS[s_print_tables_lks] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_lks);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								store_links(t_project *lem_in)
{
	t_machine	*machine;

	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (ERROR)
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}
