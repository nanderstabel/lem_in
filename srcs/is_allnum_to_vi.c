/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_allnum_to_vi.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:14:07 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/17 15:00:18 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						isallnum_nline_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == 'L')
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	while (*lem_in->input_string_copy != '\n')
	{
		if (ft_isprint((int)*lem_in->input_string_copy) != 1)
		{
			if (*lem_in->input_string_copy == '\0')
				return (SUCCESS);
			else
				return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		}
		if (*lem_in->input_string_copy == '-')
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	lem_in->input_string_copy++;
	return (SUCCESS);
}

t_bool						isallnum_space_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != ' ')
	{
		if (ft_isprint((int)*lem_in->input_string_copy) != 1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		if (*lem_in->input_string_copy == '-')
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	lem_in->nrooms++;
	lem_in->input_string_copy++;
	return (SUCCESS);
}

t_bool						isallnum_hyph_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != '-')
	{
		if (ft_isprint((int)*lem_in->input_string_copy) != 1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	lem_in->nlinks++;
	lem_in->input_string_copy++;
	return (SUCCESS);
}
