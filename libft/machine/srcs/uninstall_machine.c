/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   uninstall_machine.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 17:38:34 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:45:25 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

/*
** 'Uninstalling' the machine means to free all the allocated memory that the
** machine has used during the run of the program.
*/

t_bool			uninstall_machine(t_machine **machine)
{
	t_state			proxy;

	free((*machine)->events);
	proxy = 0;
	while (proxy < (*machine)->size)
	{
		free((*machine)->transition_table[proxy]);
		++proxy;
	}
	free((*machine)->transition_table);
	free(*machine);
	return (SUCCESS);
}
