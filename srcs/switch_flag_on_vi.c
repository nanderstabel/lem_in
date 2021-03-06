/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   switch_flag_on_vi.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 15:26:10 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/19 09:44:29 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						set_start_flag_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & START)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	else
	{
		lem_in->flags |= START;
		lem_in->flags |= ROOM_LINE;
	}
	return (SUCCESS);
}

t_bool						set_end_flag_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & END)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	else
	{
		lem_in->flags |= END;
		lem_in->flags |= ROOM_LINE;
	}
	return (SUCCESS);
}

t_bool						switch_link_flag_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & LINK)
		return (FAIL);
	else
		lem_in->flags |= LINK;
	return (SUCCESS);
}

t_bool						find_hyphen_vi(t_project *lem_in)
{
	int		index;

	index = 0;
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (lem_in->input_string_copy[index] != '\n'\
	&& lem_in->input_string_copy[index] != '\0')
	{
		if (lem_in->input_string_copy[index] == '-')
		{
			lem_in->flags |= LINK;
			return (SUCCESS);
		}
		index++;
	}
	return (FAIL);
}
