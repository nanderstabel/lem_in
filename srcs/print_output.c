/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_output.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 19:10:56 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/25 13:03:30 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

t_bool								print_output(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
    	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}
