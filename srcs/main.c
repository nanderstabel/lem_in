/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 17:31:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/12 13:35:20 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			malloc_transition_table(t_machine **machine)
{
	(*machine)->state = uninstall_machine;
	(*machine)->transition = (t_state **)malloc(sizeof(t_state *) * ((*machine)->state + 1));
	while ((*machine)->state >= idle)
	{
		(*machine)->transition[(*machine)->state] = (t_state *)malloc(sizeof(t_state) * 2);
		--(*machine)->state;
	}
}

void			fill_transition_table(t_machine **machine)
{
	(*machine)->transition[idle][0] = idle;
	(*machine)->transition[idle][1] = install_machine;
	(*machine)->transition[install_machine][0] = print_output;
	(*machine)->transition[install_machine][1] = receive_input;
	(*machine)->transition[receive_input][0] = print_output;
	(*machine)->transition[receive_input][1] = validate_input;
	(*machine)->transition[validate_input][0] = print_output;
	(*machine)->transition[validate_input][1] = idle;
	(*machine)->transition[print_output][0] = print_output;
	(*machine)->transition[print_output][1] = uninstall_machine;
	(*machine)->transition[uninstall_machine][0] = idle;
	(*machine)->transition[uninstall_machine][1] = uninstall_machine;
}

void			install_transitions(t_machine **machine)
{
	malloc_transition_table(machine);
	fill_transition_table(machine);
}

void			malloc_event_table(t_machine **machine)
{
	(*machine)->event = (t_event *)malloc(sizeof(t_event) * (uninstall_machine + 1));
}

void			fill_event_table(t_machine **machine)
{
	(*machine)->event[idle] = NULL;
	(*machine)->event[install_machine] = NULL;
	(*machine)->event[receive_input] = receiving_input;
	(*machine)->event[validate_input] = validating_input;
	(*machine)->event[print_output] = printing_output;
	(*machine)->event[uninstall_machine] = uninstalling_machine;
}

void			install_events(t_machine **machine)
{
	malloc_event_table(machine);
	fill_event_table(machine);
}

void			install(t_machine **machine)
{
	*machine = (t_machine *)malloc(sizeof(t_machine));

	install_transitions(machine);
	install_transitions(machine);
}

int								receiving_input(void *pointer)
{
	pointer = NULL;
	return (0);
}	

int								validating_input(void *pointer)
{
	pointer = NULL;
	return (0);
}	

int								printing_output(void *pointer)
{
	pointer = NULL;
	return (0);
}	

int								uninstalling_machine(void *pointer)
{
	pointer = NULL;
	return (0);
}	

int								ending_program(void *pointer)
{
	pointer = NULL;
	return (0);
}			

int				main(int argc, char **argv)
{
	t_machine	*machine;

	argc = 0;
	argv = NULL;
	install(&machine);
	while (machine->state != idle)
	{
		++machine->state;
	}
	free(machine);
	machine = NULL;
	return (0);
}
