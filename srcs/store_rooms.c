/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_rooms.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 17:21:47 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/29 18:09:34 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				*get_vertex(char *name, size_t index, size_t hash)
{
	t_vertex		*vertex;

	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	vertex->type = standard;
	vertex->index = index;
	vertex->hash = hash;
	vertex->name = name;
	return ((void *)vertex);
}

int					check_room(void *elem, size_t hash)
{
	t_vertex	*room;

	room = (t_vertex *)elem;
	if (room->hash == hash)
		return (1);
	return (0);
}

t_bool				initialize_table(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	ROOMS = ft_malloc_hash_table(NROOMS);
	if (ROOMS)
		return (SUCCESS);
	return (FAIL);
}

t_bool				set_line(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	INPUT_CPY = INPUT;
	if (INPUT_CPY == NULL)
		return (FAIL);
	ft_skip_line(&INPUT_CPY);
	return (SUCCESS);
}

t_bool				get_type(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	if (INPUT_CPY[1] == '-')
		return (FAIL);
	lem_in->room_type = standard;
	while (*INPUT_CPY == '#')
	{
		if (ft_strnstr(INPUT_CPY, "##start", 8))
			lem_in->room_type = start;
		else if (ft_strnstr(INPUT_CPY, "##end", 5))
			lem_in->room_type = end;
		ft_skip_line(&INPUT_CPY);
	}
	return (SUCCESS);
}

t_bool				store_room(t_project *lem_in)
{
	t_vertex	*new_room;

	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	new_room = (t_vertex *)ft_hash_table_add(ROOMS, \
		ft_strsub(INPUT_CPY, 0, ft_nchar(INPUT_CPY, ' ')), check_room, get_vertex);
	if (new_room)
	{
		new_room->type = lem_in->room_type;
		ft_skip_line(&INPUT_CPY);
		return (SUCCESS);
	}
	return (FAIL);
}

void				print_hash_table(t_hash_table *table)
{
	size_t		i;
	t_vertex	*tmp;

	i = 0;
	ft_printf("____________________________________________________________________________\n");
	ft_printf("\x1B[4mindex\taddress\t\tname\t\t\thash\t\ti\ttype\e[0m\n\n");
	while (i < table->size)
	{
		tmp = (t_vertex *)table->elem[i];
		ft_printf("[%i] -->	%p", i, table->elem[i]);
		if (tmp)
			ft_printf("\t%-24s#%u\t\t%u\t%i", tmp->name, tmp->hash, tmp->index, tmp->type);
		ft_putchar(10);
		++i;
	}
	ft_printf("____________________________________________________________________________\n\n");
}

t_bool				print_rooms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	if (FLAGS & ROOMS_O)
	{
		ft_putendl("\nRooms:");
		print_hash_table(ROOMS);
		return (SUCCESS);
	}
	return (FAIL);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_initialize_table_rms;
	TRANSITIONS[s_initialize_table_rms][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_initialize_table_rms][SUCCESS] = s_set_line;
	TRANSITIONS[s_set_line][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_set_line][SUCCESS] = s_get_type;
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
	EVENTS[s_initialize_table_rms] = initialize_table;
	EVENTS[s_set_line] = set_line;
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

	NROOMS = 7;// delete this
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (ERROR)
		return (FAIL);
	return (SUCCESS);
}
