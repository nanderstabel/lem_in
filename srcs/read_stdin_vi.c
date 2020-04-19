/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_stdin_vi.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 15:16:03 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/19 09:44:29 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool							read_stdin_vi(t_project *lem_in)
{
	char			*temp;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*new;

	ret = 1;
	new = ft_strnew(0);
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (ret != 0)
	{
		ret = read(0, buf, BUFF_SIZE);
		if (ret == -1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		buf[ret] = '\0';
		temp = new;
		new = ft_strjoin(new, buf);
		free(temp);
	}
	lem_in->input_string = new;
	lem_in->input_string_copy = lem_in->input_string;
	return (SUCCESS);
}
