/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 12:58:29 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** The function receives an addres of a charakter string as argument.
**
** The function reads a map redirected to STDIN during the execution of lem_in.
**
**	It return a FAIL if read returns a -1 or a SUCCESS if everything went well.
*/

// t_bool		read_stdin_vi(t_project *lem_in)
// {
// 	char			*temp;
// 	int				ret;
// 	char			buf[BUFF_SIZE + 1];
// 	char			*new;

// 	ft_printf("\t%s\n", __func__);
// 	ret = 1;
// 	new = ft_strnew(0);
// 	while (ret !=  0)
// 	{
// 		ret = read(STDIN_FILENO, buf, BUFF_SIZE);
// 		if (ret == -1)
// 			return (FAIL);
// 		buf[ret] = '\0';
// 		temp = new;
// 		new = ft_strjoin(new, buf);
// 		free(temp);
// 	}
// 	lem_in->input_string = new;
// 	lem_in->input_eval_string = lem_in->input_string;
// 	return (SUCCESS);
// }
