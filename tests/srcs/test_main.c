/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 16:50:26 by mgross         #+#    #+#                */
/*   Updated: 2020/02/26 16:38:37 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		main(void)
{
	char			*str;
	t_project		*lem_in;
	// t_bool			boolean;
	t_list			*temp;
	// char			*test;
	

	lem_in = (t_project*)malloc(sizeof(t_project));
	lem_in->error = NULL;
	lem_in->error = NULL;
	str = ft_strdup("function1");
	temp = ft_lstnew(str, ft_strlen(str));
	lem_in->error = temp;
	error_log(lem_in, "function2");
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			ft_printf("string in list: %s\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	return (0);
}