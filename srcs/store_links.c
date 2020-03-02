/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_links.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:56:15 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/02 20:16:19 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				*get_edge(void)
{
	t_edge		*edge;

	edge = (t_edge *)malloc(sizeof(t_edge));
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
	return (FAIL);
}

t_bool				save_roomnames(t_project *lem_in)
{
	size_t	len;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	len = ft_nchar(INPUT_CPY, '\n') - 1;
	if (!len)
		len = ft_strlen(INPUT_CPY);
	LINKED_ROOMS = (void **)ft_strnsplit(INPUT_CPY, '-', len);
	if (!LINKED_ROOMS)
		return (FAIL);
	if (ft_strcmp(LINKED_ROOMS[0], LINKED_ROOMS[1]) > 0)
		ft_swap(&LINKED_ROOMS[0], &LINKED_ROOMS[1]);
	return (SUCCESS);
}

t_bool				check_first_room(t_project *lem_in)
{
	char	*name;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	name = LINKED_ROOMS[0];
	LINKED_ROOMS[0] = (void *)ft_hash_table_get(ALL_ROOMS, name);
	free(name);
	if (!LINKED_ROOMS[0])
		return (FAIL);
	return (SUCCESS);
}

t_bool				check_second_room(t_project *lem_in)
{
	char	*name;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	name = LINKED_ROOMS[1];
	LINKED_ROOMS[1] = (void *)ft_hash_table_get(ALL_ROOMS, name);
	free(name);
	if (!LINKED_ROOMS[1])
		return (FAIL);
	return (SUCCESS);
}

t_bool				store_link(t_project *lem_in)
{
	char	*link_name;
	t_elem	*new_link;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	link_name = ft_strjoin(((t_elem *)LINKED_ROOMS[0])->name, "-");
	link_name = ft_strjoin(link_name, ((t_elem *)LINKED_ROOMS[1])->name);
	new_link = ft_hash_table_add(ALL_LINKS, link_name, (void *)get_edge());
	if (new_link)
		return (SUCCESS);
	ft_printf("link_name: %s, hash: %i\n", link_name, ft_hash(link_name));
	return (FAIL);
}

t_bool				add_link_to_rooms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
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
	TRANSITIONS[s_save_roomnames][SUCCESS] = s_check_first_room;
	TRANSITIONS[s_check_first_room][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_check_first_room][SUCCESS] = s_check_second_room;
	TRANSITIONS[s_check_second_room][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_check_second_room][SUCCESS] = s_store_link;
	TRANSITIONS[s_store_link][FAIL] = s_set_line;
	TRANSITIONS[s_store_link][SUCCESS] = s_add_link_to_rooms;
	TRANSITIONS[s_add_link_to_rooms][FAIL] = s_uninstall_machine_lks;
	TRANSITIONS[s_add_link_to_rooms][SUCCESS] = s_set_line;
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
	EVENTS[s_check_first_room] = check_first_room;
	EVENTS[s_check_second_room] = check_second_room;
	EVENTS[s_store_link] = store_link;
	EVENTS[s_add_link_to_rooms] = add_link_to_rooms;
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
		return (FAIL);
	return (SUCCESS);
}
