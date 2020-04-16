/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_digits_to_vi.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: zitzak <zitzak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:11:28 by zitzak        #+#    #+#                 */
/*   Updated: 2020/04/16 13:14:21 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						isdigit_to_space_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != ' ')
	{
		if (ft_isdigit(*lem_in->input_string_copy) != 1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	lem_in->input_string_copy++;
	return (SUCCESS);
}

t_bool						isdigit_to_newline_vi(t_project *lem_in)
{
	char		*temp;

	temp = lem_in->input_string_copy;
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != '\n')
	{
		if (ft_isdigit(*lem_in->input_string_copy) != 1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	if (lem_in->nants == 0)
		lem_in->nants = ft_atoi(temp);
	if (lem_in->flags & ROOM_LINE)
		lem_in->flags ^= ROOM_LINE;
	lem_in->input_string_copy++;
	return (SUCCESS);
}
