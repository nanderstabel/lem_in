/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_error.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 13:01:21 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/02 14:48:00 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								print_error(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
    	ft_printf("%s\n", __func__);
	while (ERROR)
	{
		if (FLAGS & ERROR_O)
			ft_printf("An error occured, machine was not able to: %s\n", ERROR->content);
		ERROR = ERROR->next;
	}
	if (FLAGS & ROOMS_O)
		ft_puttbl(ALL_ROOMS);
	if (FLAGS & LINKS_O)
		ft_puttbl(ALL_LINKS);
	if (FLAGS & ERROR_O)
		ft_putendl("Ending program");
	return (SUCCESS);
}
