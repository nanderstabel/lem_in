/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_links.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:56:15 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/03 18:41:02 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				*get_edge(void)
{
	t_edge		*edge;

	edge = (t_edge *)malloc(sizeof(t_edge));
	edge->id = NULL;
	edge->capacity = 0;
	edge->back = NULL;
	edge->forward = NULL;
	return (edge);
}

t_bool				initialize_table_lks(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	ALL_LINKS = ft_malloc_hash_table(NLINKS, ft_strdup("Links"));
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
	if (ft_strcmp(ROOM_POINTER(0), ROOM_POINTER(1)) > 0)
		ft_swap(&ROOM_POINTER(0), &ROOM_POINTER(1));
	return (SUCCESS);
}

t_bool				find_first_room(t_project *lem_in)
{
	char	*name;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	name = ROOM_POINTER(0);
	ROOM_POINTER(0) = (void *)ft_hash_table_get(ALL_ROOMS, name);
	free(name);
	if (!ROOM_POINTER(0))
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

t_bool				find_second_room(t_project *lem_in)
{
	char	*name;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	name = ROOM_POINTER(1);
	ROOM_POINTER(1) = (void *)ft_hash_table_get(ALL_ROOMS, name);
	free(name);
	if (!ROOM_POINTER(1))
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

t_bool				store_link(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	LINK_POINTER = (void *)ft_strjoin(ROOM_ELEM(0)->name, "-");
	LINK_POINTER = (void *)ft_append((char **)&LINK_POINTER, ROOM_ELEM(1)->name);
	LINK_POINTER = (void *)ft_hash_table_add(ALL_LINKS, (char *)LINK_POINTER, (void *)get_edge());
	if (LINK_POINTER)
	{
		LINK_CONTENT->id = LINK_ELEM;
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				add_rooms_to_link(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!LINK_CONTENT || !ROOM_CONTENT(0) || !ROOM_CONTENT(1))
		return (ERROR_LOG(FAIL));
	LINK_CONTENT->back = ROOM_CONTENT(0);
	LINK_CONTENT->forward = ROOM_CONTENT(1);
	return (SUCCESS);
}

t_bool				add_link_to_room(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (INDEX > 1)
		return (FAIL);
	if (ROOM_CONTENT(INDEX)->links)
		ft_addr_lstadd(&ROOM_CONTENT(INDEX)->links, ft_addr_lstnew(LINK_CONTENT));
	else
		ROOM_CONTENT(INDEX)->links = ft_addr_lstnew(LINK_CONTENT);
	++INDEX;
	return (SUCCESS);
}

t_bool				set_line(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	ft_skip_line(&INPUT_CPY);
	while (*INPUT_CPY == '#')
		ft_skip_line(&INPUT_CPY);
	if (*INPUT_CPY == 0)
		return (FAIL);
	return (SUCCESS);
}

t_bool				print_links(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (FLAGS & LINKS_O)
	{
		ft_puttbl(ALL_LINKS);
		return (SUCCESS);
	}
	return (FAIL);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_initialize_table_lks;
	TRANSITIONS[s_initialize_table_lks][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_initialize_table_lks][SUCCESS] = s_save_roomnames;
	TRANSITIONS[s_save_roomnames][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_save_roomnames][SUCCESS] = s_find_first_room;
	TRANSITIONS[s_find_first_room][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_find_first_room][SUCCESS] = s_find_second_room;
	TRANSITIONS[s_find_second_room][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_find_second_room][SUCCESS] = s_store_link;
	TRANSITIONS[s_store_link][FAIL] = s_set_line;
	TRANSITIONS[s_store_link][SUCCESS] = s_add_link_to_room;
	TRANSITIONS[s_add_rooms_to_link][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_add_rooms_to_link][SUCCESS] = s_add_rooms_to_link;
	TRANSITIONS[s_add_link_to_room][FAIL] = s_set_line;
	TRANSITIONS[s_add_link_to_room][SUCCESS] = s_add_link_to_room;
	TRANSITIONS[s_set_line][FAIL] = s_print_links;
	TRANSITIONS[s_set_line][SUCCESS] = s_save_roomnames;
	TRANSITIONS[s_print_links][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_print_links][SUCCESS] = s_uninstall_machine_lks;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_lks] = NULL;
	EVENTS[s_initialize_table_lks] = initialize_table_lks;
	EVENTS[s_save_roomnames] = save_roomnames;
	EVENTS[s_find_first_room] = find_first_room;
	EVENTS[s_find_second_room] = find_second_room;
	EVENTS[s_store_link] = store_link;
	EVENTS[s_add_rooms_to_link] = add_rooms_to_link;
	EVENTS[s_add_link_to_room] = add_link_to_room;
	EVENTS[s_set_line] = set_line;
	EVENTS[s_print_links] = print_links;
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
	// CURRENT_ROOM = (t_vertex *)(ft_hash_table_get(ALL_ROOMS, "Kls2")->content);
	// while (CURRENT_ROOM->links)
	// {
	// 	ft_printf("linkname: %s\n", ((t_edge *)(CURRENT_ROOM->links->address))->id->name);
	// 	CURRENT_ROOM->links = CURRENT_ROOM->links->next;
	// }
	return (SUCCESS);
}
