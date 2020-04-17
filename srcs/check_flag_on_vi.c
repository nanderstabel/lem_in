/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_flag_on_vi.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 15:29:08 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/17 14:58:13 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						link_flag_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & LINK)
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool						allflags_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((lem_in->flags & START) && (lem_in->flags & END) &&
		(lem_in->flags & LINK))
		return (SUCCESS);
	else
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
}

t_bool						line_room_hash_vi(t_project *lem_in)
{
	if (lem_in->flags & ROOM_LINE)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

t_bool						next_line_room_vi(t_project *lem_in)
{
	if (lem_in->flags & ROOM_LINE)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}
