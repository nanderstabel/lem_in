/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_file_done_vi.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: zitzak <zitzak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:17:15 by zitzak        #+#    #+#                 */
/*   Updated: 2020/04/16 13:18:01 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						input_file_done_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '\0')
		return (SUCCESS);
	else
		return (FAIL);
}
