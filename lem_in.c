/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 17:31:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/07 13:34:59 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		install_handlers(t_machine **machine)
{
	(*machine)->handler = (t_event_handler *)malloc(sizeof(t_event_handler) * \
							(deinstalling_machine + 1));
	(*machine)->handler[receiving_input] = ps_receiving_input_handler;
	(*machine)->handler[reading_argument] = ps_reading_argument_handler;
	(*machine)->handler[verifying_argument] = ps_verifying_argument_handler;
	(*machine)->handler[adding_to_stack] = ps_adding_to_stack_handler;
	(*machine)->handler[completing_stack] = ps_completing_stack_handler;
	(*machine)->handler[planting_tree] = ps_planting_tree_handler;
	(*machine)->handler[verifying_stack] = ps_verifying_stack_handler;
	(*machine)->handler[growing_leaves] = ps_growing_leaves_handler;
	(*machine)->handler[printing_command] = ps_printing_command_handler;
	(*machine)->handler[deleting_stack] = ps_deleting_stack_handler;
	(*machine)->handler[printing_error] = ps_printing_error_handler;
	(*machine)->handler[deinstalling_machine] = ps_deinstalling_machine_handler;
}

static void		install_states(t_machine **machine)
{
	(*machine)->state = (t_state *)malloc(sizeof(t_state) * \
							machine_deinstalled);
	(*machine)->state[machine_installed] = receiving_input;
	(*machine)->state[input_received] = reading_argument;
	(*machine)->state[no_input] = printing_error;
	(*machine)->state[argument_read] = verifying_argument;
	(*machine)->state[no_argument] = completing_stack;
	(*machine)->state[argument_valid] = adding_to_stack;
	(*machine)->state[argument_invalid] = printing_error;
	(*machine)->state[added_to_stack] = reading_argument;
	(*machine)->state[stack_completed] = planting_tree;
	(*machine)->state[tree_planted] = verifying_stack;
	(*machine)->state[stack_valid] = printing_command;
	(*machine)->state[stack_invalid] = growing_leaves;
	(*machine)->state[leaves_grew] = verifying_stack;
	(*machine)->state[command_printed] = deleting_stack;
	(*machine)->state[stack_deleted] = deinstalling_machine;
	(*machine)->state[error_printed] = deinstalling_machine;
}

void			install(t_machine **machine)
{
	*machine = (t_machine *)malloc(sizeof(t_machine));
	*machine->event = (t_event *)malloc(sizeof(t_event) * end_program);
	*machine->event[receive_input] = 
}

int				main(int argc, char **argv)
{
	t_machine	*machine;

	install(&machine);
	while (machine->state != idle)
		machine->state = (*machine->event[machine->transition])(machine);
	free(machine);
	machine = NULL;
	return (0);
}
