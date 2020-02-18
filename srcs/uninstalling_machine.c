/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   uninstalling_machine.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 13:02:48 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/18 13:35:49 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								uninstalling_machine(void *lem_in)
{
	lem_in = NULL;
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}
