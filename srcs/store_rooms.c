/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_rooms.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 17:21:47 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/02 20:16:10 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex			*get_vertex(void)
{
	t_vertex		*vertex;

	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	vertex->type = standard;
	vertex->links = NULL;
	return (vertex);
}

t_bool				initialize_table_rms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	ALL_ROOMS = ft_malloc_hash_table(NROOMS, ft_strdup("Rooms"));
	if (ALL_ROOMS)
		return (SUCCESS);
	return (FAIL);
}

t_bool				set_line_rms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	INPUT_CPY = INPUT;
	if (INPUT_CPY == NULL)
		return (FAIL);
	ft_skip_line(&INPUT_CPY);
	return (SUCCESS);
}

t_bool				get_type(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (INPUT_CPY[1] == '-')
		return (FAIL);
	ROOM_TYPE = standard;
	while (*INPUT_CPY == '#')
	{
		if (ft_strnstr(INPUT_CPY, "##start", 8))
			ROOM_TYPE = start;
		else if (ft_strnstr(INPUT_CPY, "##end", 5))
			ROOM_TYPE = end;
		ft_skip_line(&INPUT_CPY);
	}
	return (SUCCESS);
}

t_bool				store_room(t_project *lem_in)
{
	t_elem	*new_room;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	new_room = ft_hash_table_add(ALL_ROOMS, \
	ft_strsub(INPUT_CPY, 0, ft_nchar(INPUT_CPY, ' ') - 1), (void *)get_vertex());
	if (new_room)
	{
		((t_vertex *)new_room->content)->type = ROOM_TYPE;
		ft_skip_line(&INPUT_CPY);
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				print_rooms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (FLAGS & ROOMS_O)
	{
		ft_puttbl(ALL_ROOMS);
		return (SUCCESS);
	}
	return (FAIL);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_initialize_table_rms;
	TRANSITIONS[s_initialize_table_rms][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_initialize_table_rms][SUCCESS] = s_set_line_rms;
	TRANSITIONS[s_set_line_rms][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_set_line_rms][SUCCESS] = s_get_type;
	TRANSITIONS[s_get_type][FAIL] = s_print_rooms;
	TRANSITIONS[s_get_type][SUCCESS] = s_store_room;
	TRANSITIONS[s_store_room][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_store_room][SUCCESS] = s_get_type;
	TRANSITIONS[s_print_rooms][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_print_rooms][SUCCESS] = s_uninstall_machine_rms;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_rms] = NULL;
	EVENTS[s_initialize_table_rms] = initialize_table_rms;
	EVENTS[s_set_line_rms] = set_line_rms;
	EVENTS[s_get_type] = get_type;
	EVENTS[s_store_room] = store_room;
	EVENTS[s_print_rooms] = print_rooms;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_rms);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								store_rooms(t_project *lem_in)
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
