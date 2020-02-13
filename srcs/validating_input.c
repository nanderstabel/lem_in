/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validating_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:54:14 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/13 15:11:49 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								validating_input(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}
