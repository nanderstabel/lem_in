/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_options_so.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 18:50:42 by nstabel       #+#    #+#                 */
/*   Updated: 2020/06/30 14:37:13 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				read_argument(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->argc > 1)
	{
		--lem_in->argc;
		++lem_in->argv;
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				find_dash(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (**lem_in->argv == '-')
	{
		++(*lem_in->argv);
		return (SUCCESS);
	}
	return (FAIL);
}

static void			check_options(t_project *lem_in)
{
	if (**lem_in->argv == 'g')
		lem_in->flags |= DEBUG_O;
	else if (**lem_in->argv == 'r')
		lem_in->flags |= ROOMS_O;
	else if (**lem_in->argv == 'l')
		lem_in->flags |= LINKS_O;
	else if (**lem_in->argv == 'e')
		lem_in->flags |= ERROR_O;
	else if (**lem_in->argv == 'd')
		lem_in->flags |= DFS_O;
	else if (**lem_in->argv == 'p')
		lem_in->flags |= PATHS_O;
	else if (**lem_in->argv == 'a')
		lem_in->flags |= AUGMENT_O;
	else if (**lem_in->argv == 'c')
		lem_in->flags |= COUNT_O;
	else if (**lem_in->argv == 'b')
		lem_in->flags |= BLANK_O;
}

t_bool				find_option(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_strchr(OPTIONS, **lem_in->argv) && **lem_in->argv)
	{
		if (**lem_in->argv == 'u')
			return (FAIL);
		check_options(lem_in);
		++(*lem_in->argv);
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				validate_argument(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (**lem_in->argv == 0 && *(*lem_in->argv - 1) != '-')
		return (SUCCESS);
	return (FAIL);
}
