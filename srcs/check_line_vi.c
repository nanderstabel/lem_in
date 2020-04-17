/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_line_vi.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 15:23:51 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/17 14:50:09 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						start_in_line_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_strcmp_delim(lem_in->input_string_copy, "##start\n", (int)'\n') == 0)
	{
		while (*lem_in->input_string_copy != '\n'\
		&& *lem_in->input_string_copy != '\0')
			lem_in->input_string_copy++;
		if (*lem_in->input_string_copy == '\n')
			lem_in->input_string_copy++;
		return (SUCCESS);
	}
	else
		return (FAIL);
}

t_bool						end_in_line_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_strcmp_delim(lem_in->input_string_copy, "##end\n", (int)'\n') == 0)
	{
		while (*lem_in->input_string_copy != '\n'\
		&& *lem_in->input_string_copy != '\0')
			lem_in->input_string_copy++;
		if (*lem_in->input_string_copy == '\n')
			lem_in->input_string_copy++;
		return (SUCCESS);
	}
	else
		return (FAIL);
}
