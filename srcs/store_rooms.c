/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_rooms.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 17:21:47 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/29 13:39:47 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				skip_line(char **str)
{
	while (**str != '\n' && **str != 0)
		++(*str);
	if (**str == 0)
		return ;
	++(*str);
}
void				*get_vertex(char *name, size_t index, size_t hash)
{
	t_vertex		*test;

	test = (t_vertex *)malloc(sizeof(t_vertex));
	test->index = index;
	test->hash = hash;
	test->name = name;
	return ((void *)test);
}

int					check_room(void *elem, size_t hash)
{
	t_vertex	*room;

	room = (t_vertex *)elem;
	if (room->hash == hash)
		return (1);
	return (0);
}

int		hash_table_add(t_hash_table *hash_table, char *key, t_hashequ hashequ, t_get_elem get_elem)
{
	size_t	index;
	size_t	probe;
	size_t	hash;

	hash = ft_hash(key);
	index = hash % hash_table->size;
	probe = 0;
	while (hash_table->elem[(index + probe) % hash_table->size])
	{
		if (hashequ(hash_table->elem[(index + probe) % hash_table->size], hash))
			return (0);
		++probe;
	}
	index = (index + probe) % hash_table->size;
	hash_table->elem[index] = get_elem(key, index, hash);
	return (1);
}

t_hash_table	*malloc_hash_table(size_t size)
{
	t_hash_table	*hash_table;
	size_t			index;

	hash_table = (t_hash_table *)malloc(sizeof(t_hash_table));
	if (hash_table == NULL)
		return (NULL);
	hash_table->elem = (void **)malloc(sizeof(void *) * size);
	if (hash_table->elem == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		hash_table->elem[index] = NULL;
		++index;
	}
	hash_table->size = size;
	return (hash_table);
}

t_bool				initialize_table(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	ROOMS = malloc_hash_table(NROOMS);
	if (ROOMS)
		return (SUCCESS);
	return (FAIL);
}

t_bool				set_line(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	LINE = INPUT;
	if (LINE == NULL)
		return (FAIL);
	skip_line(&LINE);
	return (SUCCESS);
}


t_bool				get_room(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	while (*LINE == '#')
		skip_line(&LINE);
	if (LINE[1] == '-')
		return (FAIL);
	return (SUCCESS);
}

t_bool				store_room(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	if (hash_table_add(ROOMS, ft_strsub(LINE, 0, ft_nchar(LINE, ' ')), check_room, get_vertex))
	{
		skip_line(&LINE);
		return (SUCCESS);
	}
	return (FAIL);
}

void				print_hash_table(t_hash_table *table)
{
	size_t		i;
	t_vertex	*tmp;

	i = 0;
	ft_printf("\n\x1B[4mindex\taddress\t\tname\t\thash\t\ti\e[0m\n\n");
	while (i < table->size)
	{
		tmp = (t_vertex *)table->elem[i];
		ft_printf("[%i] -->	%p", i, table->elem[i]);
		if (tmp)
			ft_printf("\t%-16s#%u\t\t%u", tmp->name, tmp->hash, tmp->index);
		ft_putchar(10);
		++i;
	}
	ft_printf("________________________________________\n\n");
}

t_bool				print_rooms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("Currently: %s\n", __func__);
	if (FLAGS & ROOMS_O)
	{
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
	TRANSITIONS[s_set_line][SUCCESS] = s_get_room;
	TRANSITIONS[s_get_room][FAIL] = s_print_rooms;
	TRANSITIONS[s_get_room][SUCCESS] = s_store_room;
	TRANSITIONS[s_store_room][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_store_room][SUCCESS] = s_get_room;
	TRANSITIONS[s_print_rooms][FAIL] = s_uninstall_machine_rms;
	TRANSITIONS[s_print_rooms][SUCCESS] = s_uninstall_machine_rms;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_rms] = NULL;
	EVENTS[s_initialize_table_rms] = initialize_table;
	EVENTS[s_set_line] = set_line;
	EVENTS[s_get_room] = get_room;
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
