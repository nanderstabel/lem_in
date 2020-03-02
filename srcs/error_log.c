/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_log.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:21:44 by mgross         #+#    #+#                */
/*   Updated: 2020/03/02 14:48:00 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool			error_log(t_project *lem_in, char *str, t_bool ret)
{
	t_list		*temp;

	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	temp = ft_lstnew(str, ft_strlen(str));
	if (lem_in->error == NULL)
	{
		lem_in->error = temp;
	}
	else
	{
		ft_lstapp(&lem_in->error, temp);
	}
	free(str);
	return (ret);
}
