/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_digit_to_vi.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:11:28 by mgross        #+#    #+#                 */
/*   Updated: 2020/06/30 14:08:17 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						isdigit_space_vi(t_project *lem_in)
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

t_bool						isdigit_nline_vi(t_project *lem_in)
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
	if (lem_in->nants > 100000)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	if (lem_in->flags & ROOM_LINE)
		lem_in->flags ^= ROOM_LINE;
	lem_in->input_string_copy++;
	return (SUCCESS);
}
