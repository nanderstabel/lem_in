/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 10:41:21 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/17 15:15:41 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								print_error(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (lem_in->flags & ERROR_O)
	{
		ft_printf(RED "An error occurred, machine was not able to: \n");
		ft_putlst(lem_in->error, "\n");
		ft_printf(EOC);
	}
	ft_lstdel(&lem_in->error, ft_freezero);
	if (lem_in->flags & ROOMS_O)
		ft_puttbl(lem_in->all_rooms);
	if (lem_in->flags & LINKS_O)
		ft_puttbl(lem_in->all_links);
	if (lem_in->flags & ERROR_O)
		ft_putendl("Ending program");
	return (SUCCESS);
}
