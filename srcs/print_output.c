/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_output.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 19:10:56 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/03 14:26:21 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

t_bool								print_output(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	return (SUCCESS);
}
