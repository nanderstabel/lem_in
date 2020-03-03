/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_log.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:21:44 by mgross         #+#    #+#                */
/*   Updated: 2020/03/03 18:55:16 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool			error_log(t_project *lem_in, char *str, t_bool ret)
{
	t_list		*temp;

	temp = ft_lstnew(str, ft_strlen(str));
	if (ERROR == NULL)
	{
		ERROR = temp;
	}
	else
	{
		ft_lstadd(&ERROR, temp);
	}
	free(str);
	return (ret);
}
