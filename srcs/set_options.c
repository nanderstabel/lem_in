/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setting_options.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 14:58:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/13 16:13:30 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								set_options(void *project)
{
	t_project	*lem_in;

	lem_in = (t_project *)project;
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}