/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 17:31:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/11 17:38:42 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			install_transitions(t_machine **machine)
{
	t_state		transition[deinstall_machine + 1][2];

	(*machine)->transition = transition;
	(*machine)->transition[idle][0] = idle;
	(*machine)->transition[idle][1] = install_machine;
	(*machine)->transition[install_machine][0] = print_output;
	(*machine)->transition[install_machine][1] = receive_input;
	(*machine)->transition[receive_input][0] = print_output;
	(*machine)->transition[receive_input][1] = validate_input;
	(*machine)->transition[validate_input][0] = print_output;
	(*machine)->transition[validate_input][1] = idle;
	(*machine)->transition[print_output][0] = print_output;
	(*machine)->transition[print_output][1] = deinstall_machine;
	(*machine)->transition[deinstall_machine][0] = idle;
	(*machine)->transition[deinstall_machine][1] = deinstall_machine;
}

void			install(t_machine **machine)
{
	*machine = (t_machine *)malloc(sizeof(t_machine));

	install_transitions(machine)

}

int				main(int argc, char **argv)
{
	t_machine	*machine;

	install(&machine);
	while (machine->state != idle)
	{
		machine->state = machine->transition[machine->state][machine->event[machine->state]];
	}
	free(machine);
	machine = NULL;
	return (0);
}
