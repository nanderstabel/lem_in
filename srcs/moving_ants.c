/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moving_ants.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 13:00:43 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/13 15:11:26 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								moving_ants(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}
