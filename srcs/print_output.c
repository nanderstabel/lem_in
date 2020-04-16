/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_output.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 19:10:56 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 17:14:48 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				print_input(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & BLANK_O)
		return (FAIL);
	ft_printf("%s\n", lem_in->input_string);
	return (SUCCESS);
}

int					sort_by_length(void *a, void *b)
{
	t_adlist	*path_a;
	t_adlist	*path_b;

	path_a = ((t_adlist *)((t_adlist *)a)->address)->next;
	path_b = ((t_adlist *)((t_adlist *)b)->address)->next;
	if ((size_t)path_a->address < (size_t)path_b->address)
		return (1);
	return (0);
}

t_ant			*get_ant(size_t nbr)
{
	t_ant		*ant;

	ant = (t_ant *)ft_memalloc(sizeof(t_ant));
	ant->name = ft_itoa((int)nbr);
	ant->name = ft_insert(&ant->name, "L", 0);
	return (ant);
}

t_bool				sort_paths(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->index = 1;
	ft_addr_lstsrt(&lem_in->all_paths, sort_by_length);
	return (SUCCESS);
}

t_bool				spawn_ants(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->que_list = lem_in->all_paths;
	while (lem_in->que_list && lem_in->index <= lem_in->nants)
	{
		if ((size_t)((t_adlist *)((t_adlist *)\
			lem_in->que_list->address))->next->address <= lem_in->nturns)
		{
			lem_in->current_ant = get_ant(lem_in->index);
			lem_in->current_ant->location = ((t_adlist *)((t_adlist *)\
				lem_in->que_list->address))->next->next;
			if (lem_in->all_ants)
				ft_addr_lstapp(&lem_in->all_ants, \
					ft_addr_lstnew((void *)lem_in->current_ant));
			else
				lem_in->all_ants = ft_addr_lstnew((void *)lem_in->current_ant);
			++lem_in->index;
		}
		lem_in->que_list = lem_in->que_list->next;
	}
	return (SUCCESS);
}

static void			loop_paths(t_project *lem_in)
{
	lem_in->que_list = lem_in->all_ants;
	while (lem_in->que_list)
	{
		((t_ant *)lem_in->que_list->address)->location = \
			((t_ant *)lem_in->que_list->address)->location->next;
		ft_printf("%s-%s", ((t_ant *)lem_in->que_list->address)->name, \
			((t_vertex *)((t_ant *)lem_in->que_list->address)\
			->location->address)->id->name);
		if (lem_in->que_list->next)
			ft_putchar(' ');
		if ((t_vertex *)((t_ant *)\
			lem_in->que_list->address)->location->address == lem_in->sink)
		{
			free(((t_ant *)lem_in->que_list->address));
			if (lem_in->que_list == lem_in->all_ants)
				lem_in->all_ants = lem_in->que_list->next;
			else
				lem_in->temp_que_list->next = lem_in->que_list->next;
		}
		else
			lem_in->temp_que_list = lem_in->que_list;
		lem_in->que_list = lem_in->que_list->next;
	}
}

t_bool				move_all_ants(t_project *lem_in)
{
	static int count;

	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->all_ants)
		return (FAIL);
	if (lem_in->flags & COUNT_O)
		ft_printf("Turn %-5i:\t", 1 + count);
	++count;
	loop_paths(lem_in);
	--lem_in->nturns;
	ft_putchar(10);
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	(*mconfig)->transitions[s_install_machine_rms][FAIL] = \
		s_uninstall_machine_po;
	(*mconfig)->transitions[s_install_machine_rms][SUCCESS] = s_print_input;
	(*mconfig)->transitions[s_print_input][FAIL] = s_print_tables_po;
	(*mconfig)->transitions[s_print_input][SUCCESS] = s_sort_paths;
	(*mconfig)->transitions[s_sort_paths][FAIL] = s_uninstall_machine_po;
	(*mconfig)->transitions[s_sort_paths][SUCCESS] = s_spawn_ants;
	(*mconfig)->transitions[s_spawn_ants][FAIL] = s_uninstall_machine_po;
	(*mconfig)->transitions[s_spawn_ants][SUCCESS] = s_move_all_ants;
	(*mconfig)->transitions[s_move_all_ants][FAIL] = s_print_tables_po;
	(*mconfig)->transitions[s_move_all_ants][SUCCESS] = s_spawn_ants;
	(*mconfig)->transitions[s_print_tables_po][FAIL] = s_uninstall_machine_po;
	(*mconfig)->transitions[s_print_tables_po][SUCCESS] = \
		s_uninstall_machine_po;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_po] = NULL;
	(*mconfig)->events[s_print_input] = print_input;
	(*mconfig)->events[s_sort_paths] = sort_paths;
	(*mconfig)->events[s_spawn_ants] = spawn_ants;
	(*mconfig)->events[s_move_all_ants] = move_all_ants;
	(*mconfig)->events[s_print_tables_po] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_po);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								print_output(t_project *lem_in)
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
