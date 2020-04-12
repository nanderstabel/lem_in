/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   install_machine.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:08:27 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:45:03 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

/*
** 'Installing' the machine means to allocate sufficient memory for the machine
** variable. At the end of this function, the transition- and event tables are
** installed.
*/

t_bool			install_machine(t_machine **machine, t_mconfig *mconfig)
{
	*machine = (t_machine *)malloc(sizeof(t_machine));
	if (*machine == NULL || mconfig == NULL)
		return (FAIL);
	if (mconfig->transitions == NULL || mconfig->events == NULL)
		return (FAIL);
	(*machine)->current_state = 0;
	(*machine)->last_state = 0;
	(*machine)->size = mconfig->size;
	(*machine)->transition_table = mconfig->transitions;
	(*machine)->events = mconfig->events;
	free(mconfig);
	(*machine)->transition = SUCCESS;
	return (SUCCESS);
}
