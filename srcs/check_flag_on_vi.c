/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_flag_on_vi.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: zitzak <zitzak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 15:29:08 by zitzak        #+#    #+#                 */
/*   Updated: 2020/04/16 13:26:27 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						check_link_flag_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & LINK)
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool						all_flags_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((lem_in->flags & START) && (lem_in->flags & END) &&
		(lem_in->flags & LINK))
		return (SUCCESS);
	else
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
}

t_bool						next_line_room_hash_vi(t_project *lem_in)
{
	if (lem_in->flags & ROOM_LINE)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

t_bool						next_line_room_link_vi(t_project *lem_in)
{
	if (lem_in->flags & ROOM_LINE)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}
