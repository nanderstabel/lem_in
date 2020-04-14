/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_output.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 19:10:56 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/14 10:20:30 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

enum
{
	s_install_machine_po,
	s_print_input,
	s_sort_paths,
	s_spawn_ants,
	s_move_all_ants,
	s_print_tables_po,
	s_uninstall_machine_po,
}	e_state_po;

t_bool				print_input(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (FLAGS & BLANK_O)
		return (FAIL);
	ft_printf("%s\n", INPUT);
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
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	INDEX = 1;
	ft_addr_lstsrt(&ALL_PATHS, sort_by_length);
	return (SUCCESS);
}

t_bool				spawn_ants(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	QUE = ALL_PATHS;
	while (QUE && INDEX <= NANTS)
	{
		if ((size_t)PATH_LENGTH <= lem_in->nturns)
		{
			lem_in->current_ant = get_ant(INDEX);
			lem_in->current_ant->location = PATH_START;
			if (lem_in->all_ants)
				ft_addr_lstapp(&lem_in->all_ants, ft_addr_lstnew((void *)lem_in->current_ant));
			else
				lem_in->all_ants = ft_addr_lstnew((void *)lem_in->current_ant);
			++INDEX;
		}
		QUE = QUE->next;
	}
	return (SUCCESS);
}

t_bool				move_all_ants(t_project *lem_in)
{
	static int count;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->all_ants)
		return (FAIL);
	if (FLAGS & COUNT_O)
		ft_printf("Turn %-5i:\t", 1 + count);
	++count;
	QUE = lem_in->all_ants;
	while (QUE)
	{
		CURRENT_ANT->location = CURRENT_ANT->location->next;
		ft_printf("%s-%s", CURRENT_ANT->name, ((t_vertex *)CURRENT_ANT->location->address)->id->name);
		if (QUE->next)
			ft_putchar(' ');
		if ((t_vertex *)CURRENT_ANT->location->address == SINK)
		{
			//delnode
			if (QUE == lem_in->all_ants)
				lem_in->all_ants = QUE->next;
			else
				TEMP_QUE->next = QUE->next;
		}
		else
			TEMP_QUE = QUE;
		QUE = QUE->next;
	}
	--lem_in->nturns;
	ft_putchar(10);
	return (SUCCESS);
}

t_bool				proto(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_po;
	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_print_input;
	TRANSITIONS[s_print_input][FAIL] = s_print_tables_po;
	TRANSITIONS[s_print_input][SUCCESS] = s_sort_paths;
	TRANSITIONS[s_sort_paths][FAIL] = s_uninstall_machine_po;
	TRANSITIONS[s_sort_paths][SUCCESS] = s_spawn_ants;
	TRANSITIONS[s_spawn_ants][FAIL] = s_uninstall_machine_po;
	TRANSITIONS[s_spawn_ants][SUCCESS] = s_move_all_ants;
	TRANSITIONS[s_move_all_ants][FAIL] = s_print_tables_po;
	TRANSITIONS[s_move_all_ants][SUCCESS] = s_spawn_ants;
	TRANSITIONS[s_print_tables_po][FAIL] = s_uninstall_machine_po;
	TRANSITIONS[s_print_tables_po][SUCCESS] = s_uninstall_machine_po;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_po] = NULL;
	EVENTS[s_print_input] = print_input;
	EVENTS[s_sort_paths] = sort_paths;
	EVENTS[s_spawn_ants] = spawn_ants;
	EVENTS[s_move_all_ants] = move_all_ants;
	EVENTS[s_print_tables_po] = print_tables;
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

	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (ERROR)
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}
