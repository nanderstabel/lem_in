/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tables.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 11:08:09 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 10:33:03 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t\t%s\n", __func__);
	if (lem_in->flags & ROOMS_O && lem_in->all_rooms)
		if (!print_table(lem_in->all_rooms, vertex_columns))
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

t_bool				print_links(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t\t%s\n", __func__);
	if (lem_in->flags & LINKS_O && lem_in->all_links)
		if (!print_table(lem_in->all_links, edge_columns))
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

char				*vertex_name(void *item)
{
	t_vertex	*vertex;

	vertex = (t_vertex *)item;
	return (vertex->id->name);
}

static void			loop_paths(t_project *lem_in)
{
	lem_in->index = 0;
	while (lem_in->que_list && lem_in->que_list->address)
	{
		if ((size_t)((t_adlist *)((t_adlist *)\
			lem_in->que_list->address))->address != lem_in->index)
		{
			ft_printf("\tRound %i:\n", ((t_adlist *)((t_adlist *)\
				lem_in->que_list->address))->address);
			lem_in->index = (size_t)((t_adlist *)((t_adlist *)\
				lem_in->que_list->address))->address;
		}
		ft_printf("\t\tlength: %i --> ", ((t_adlist *)((t_adlist *)\
			lem_in->que_list->address))->next->address);
		ft_putadlst(((t_adlist *)((t_adlist *)\
			lem_in->que_list->address))->next->next, vertex_name, "->");
		lem_in->que_list = lem_in->que_list->next;
	}
}

t_bool				print_paths(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t\t%s\n", __func__);
	if (lem_in->flags & PATHS_O)
	{
		if (lem_in->all_paths)
		{
			lem_in->que_list = lem_in->all_paths;
			ft_printf("\n{underline}Paths:{eoc}\n");
			loop_paths(lem_in);
			ft_putchar(10);
		}
	}
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	(*mconfig)->transitions[s_install_machine_rms][FAIL] = \
		s_uninstall_machine_pt;
	(*mconfig)->transitions[s_install_machine_rms][SUCCESS] = s_print_rooms;
	(*mconfig)->transitions[s_print_rooms][FAIL] = s_uninstall_machine_pt;
	(*mconfig)->transitions[s_print_rooms][SUCCESS] = s_print_links;
	(*mconfig)->transitions[s_print_links][FAIL] = s_uninstall_machine_pt;
	(*mconfig)->transitions[s_print_links][SUCCESS] = s_print_paths;
	(*mconfig)->transitions[s_print_paths][FAIL] = s_uninstall_machine_pt;
	(*mconfig)->transitions[s_print_paths][SUCCESS] = s_uninstall_machine_pt;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_pt] = NULL;
	(*mconfig)->events[s_print_rooms] = print_rooms;
	(*mconfig)->events[s_print_links] = print_links;
	(*mconfig)->events[s_print_paths] = print_paths;
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

	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (lem_in->error)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}
