/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 10:41:21 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 10:41:24 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								print_error(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (lem_in->flags & ERROR_O)
	{
		ft_printf(ERROR_MSG);
		ft_putlst(ERROR, "\n");
		ft_printf(EOC);
	}
	ft_lstdel(&ERROR, ft_freezero);
	if (lem_in->flags & ROOMS_O)
		ft_puttbl(ALL_ROOMS);
	if (lem_in->flags & LINKS_O)
		ft_puttbl(ALL_LINKS);
	if (lem_in->flags & ERROR_O)
		ft_putendl("Ending program");
	return (SUCCESS);
}
