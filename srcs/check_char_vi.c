/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_functions_vi.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: zitzak <zitzak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 15:19:33 by zitzak        #+#    #+#                 */
/*   Updated: 2020/04/15 15:20:58 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						first_char_newline_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '\n')
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), SUCCESS));
	else
		return (FAIL);
}

t_bool						first_char_zero_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '0')
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), SUCCESS));
	else
		return (FAIL);
}

t_bool						first_char_delim_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '\0')
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), SUCCESS));
	else
		return (FAIL);
}

t_bool						first_char_hash_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '#')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool						sec_char_hash_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '\0')
		return (FAIL);
	if (*(lem_in->input_string_copy + 1) == '#')
		return (SUCCESS);
	else
	{
		while (*lem_in->input_string_copy != '\n'\
		&& *lem_in->input_string_copy != '\0')
			lem_in->input_string_copy++;
		if (*lem_in->input_string_copy == '\n')
			lem_in->input_string_copy++;
		return (FAIL);
	}
}
