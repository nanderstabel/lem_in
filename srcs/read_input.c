/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 12:58:29 by mgross         #+#    #+#                */
/*   Updated: 2020/02/19 15:02:47 by mgross        ########   odam.nl         */
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

t_bool		read_stdin(char **input_string)
{
	char			*temp;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*new;

	ret = 1;
	new = ft_strnew(0);
	while (ret !=  0)
	{
		ret = read(STDIN_FILENO, buf, BUFF_SIZE);
		if (ret == -1)
			return (FAIL);
		buf[ret] = '\0';
		temp = new;
		new = ft_strjoin(new, buf);
		free(temp);
	}
	*input_string = new;
	return (SUCCESS);
}
