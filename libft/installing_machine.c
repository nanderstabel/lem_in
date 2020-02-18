/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   installing_machine.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:08:27 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/18 14:44:52 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

/*
** 'Installing' the machine means to allocate sufficient memory for the machine
** variable. At the end of this function, the transition- and event tables are
** installed.
*/

t_bool			installing_machine(t_machine **machine, t_input *input)
{
	*machine = (t_machine *)malloc(sizeof(t_machine));
	if (*machine == NULL || input == NULL)
		return (FAIL);
	if (input->transitions == NULL || input->events == NULL)
		return (FAIL);
	(*machine)->current_state = 0;
	(*machine)->size = input->size;
	(*machine)->transition_table = input->transitions;
	(*machine)->event = input->events;
	(*machine)->transition = SUCCESS;
	return (SUCCESS);
}
