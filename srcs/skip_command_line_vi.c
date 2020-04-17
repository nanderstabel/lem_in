/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   skip_command_line_vi.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:17:39 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/17 15:14:01 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						skip_comm_line_vi(t_project *lem_in)
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
