/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validating_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:54:14 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/18 16:12:03 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								check_num_ants(char *line_to_check)
{
	while (line_to_check)
	{
		if (ft_isdigit(*line_to_check) == 0)
			return (FAIL);
		line_to_check++;
	}
	return (SUCCESS);
}

t_bool								validating_input(void *lem_in)
{
	lem_in = NULL;
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}
