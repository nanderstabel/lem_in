/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_log.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:21:44 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/16 20:10:05 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool			error_log(t_project *lem_in, char *str, t_bool ret)
{
	t_list		*temp;

	temp = ft_lstnew(str, ft_strlen(str));
	if (lem_in->error == NULL)
	{
		lem_in->error = temp;
	}
	else
	{
		ft_lstadd(&lem_in->error, temp);
	}
	free(str);
	return (ret);
}
