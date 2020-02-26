/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_log.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:21:44 by mgross         #+#    #+#                */
/*   Updated: 2020/02/26 16:43:04 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool			error_log(t_project *lem_in, char	*function_name)
{
	t_list		*temp;
	char		*str;

	str = ft_strdup(function_name);
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
	return (FAIL);
}
