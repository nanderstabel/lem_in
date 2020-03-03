/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_rooms.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 17:21:47 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/03 17:37:26 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex			*get_vertex(void)
{
	t_vertex		*vertex;

	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	vertex->id = NULL;
	vertex->type = standard;
	vertex->links = NULL;
	return (vertex);
}

t_bool				initialize_table_rms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	ALL_ROOMS = ft_malloc_hash_table(NROOMS, ft_strdup("Rooms"));
	ROOM_POINTERS = (void **)malloc(sizeof(void *));
	if (ALL_ROOMS)
		return (SUCCESS);
	return (ERROR_LOG(FAIL));
}

t_bool				set_line_rms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	INPUT_CPY = INPUT;
	if (INPUT_CPY == NULL)
		return (ERROR_LOG(FAIL));
	ft_skip_line(&INPUT_CPY);
	return (SUCCESS);
}

t_bool				get_type(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_nchar(INPUT_CPY, '-') < ft_nchar(INPUT_CPY, 10))
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
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	ROOM_POINTER(0) = ft_hash_table_add(ALL_ROOMS, \
	ft_strsub(INPUT_CPY, 0, ft_nchar(INPUT_CPY, ' ') - 1), (void *)get_vertex());
	if (ROOM_POINTER(0))
	{
		ROOM_CONTENT(0)->id = ROOM_ELEM(0);
		ROOM_CONTENT(0)->type = ROOM_TYPE;
		ft_skip_line(&INPUT_CPY);
		return (SUCCESS);
	}
	ft_printf("%s\n", ft_strsub(INPUT_CPY, 0, 10));
	return (ERROR_LOG(FAIL));
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
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}
