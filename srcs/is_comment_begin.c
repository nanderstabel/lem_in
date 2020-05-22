/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_comment_begin.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: zitzak <zitzak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 18:56:02 by zitzak        #+#    #+#                 */
/*   Updated: 2020/05/22 20:39:05 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						ischar_hash_b_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '#')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool						sec_char_hash_b_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*(lem_in->input_string_copy + 1) == '#')
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	else
	{
		return (SUCCESS);
	}
}

t_bool						skip_comm_line_b_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != '\n'\
	&& *lem_in->input_string_copy != '\0')
		lem_in->input_string_copy++;
	if (*lem_in->input_string_copy == '\n')
		lem_in->input_string_copy++;
	return (SUCCESS);
}
