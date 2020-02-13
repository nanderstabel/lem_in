/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   storing_rooms.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:55:36 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/13 15:11:42 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								storing_rooms(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}
