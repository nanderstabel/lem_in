/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setting_flags.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 14:58:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/13 15:11:33 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								setting_flags(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}
