/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tables.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 11:08:09 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/19 11:08:09 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

enum
{
	s_install_machine_pt,
	s_print_rooms,
	s_print_links,
	s_print_paths,
	s_uninstall_machine_pt,
}	e_state_pt;

void				*print_table(t_hash_table *table, \
   						void *(*columns)(t_hash_table *table))
{
	if (!table)
		return (NULL);
	ft_hash_table_update(table, columns);
	ft_puttbl(table);
	return (table);
}

t_bool				print_rooms(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t\t%s\n", __func__);
	if (FLAGS & ROOMS_O && ALL_ROOMS)
		if (!print_table(ALL_ROOMS, vertex_columns))
			return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

t_bool				print_links(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t\t%s\n", __func__);
	if (FLAGS & LINKS_O && ALL_LINKS)
		if (!print_table(ALL_LINKS, edge_columns))
			return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

char				*vertex_name(void *item)
{
	t_vertex	*vertex;

	vertex = (t_vertex *)item;
	return (vertex->id->name);
}

t_bool				print_paths(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t\t%s\n", __func__);
	if (FLAGS & PATHS_O)
	{
		if (ALL_PATHS)
		{
			QUE = ALL_PATHS;
			ft_printf("\n{underline}Paths:{eoc}\n");
			INDEX = 0;
			while (QUE && QUE->address)
			{
				if ((size_t)PATH_ROUND != INDEX)
				{
					ft_printf("\tRound %i:\n", PATH_ROUND);
					INDEX = (size_t)PATH_ROUND;
				}
				ft_printf("\t\tlength: %i --> ", PATH_LENGTH);
				ft_putadlst(PATH_START, vertex_name, "->");
				QUE = QUE->next;
			}
			ft_putchar(10);
		}
	}
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_pt;
	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_print_rooms;
	TRANSITIONS[s_print_rooms][FAIL] = s_uninstall_machine_pt;
	TRANSITIONS[s_print_rooms][SUCCESS] = s_print_links;
	TRANSITIONS[s_print_links][FAIL] = s_uninstall_machine_pt;
	TRANSITIONS[s_print_links][SUCCESS] = s_print_paths;
	TRANSITIONS[s_print_paths][FAIL] = s_uninstall_machine_pt;
	TRANSITIONS[s_print_paths][SUCCESS] = s_uninstall_machine_pt;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_pt] = NULL;
	EVENTS[s_print_rooms] = print_rooms;
	EVENTS[s_print_links] = print_links;
	EVENTS[s_print_paths] = print_paths;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_pt);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				print_tables(t_project *lem_in)
{
	t_machine	*machine;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (ERROR)
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}
