/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   uninstalling_machine.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 13:02:48 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/13 15:11:46 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								uninstalling_machine(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}
