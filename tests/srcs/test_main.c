/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 16:50:26 by mgross         #+#    #+#                */
/*   Updated: 2020/02/29 12:16:59 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

// int		main(void)
// {
// 	char			*str;
// 	t_project		*lem_in;
// 	t_list			*temp;
	

// 	lem_in = (t_project*)malloc(sizeof(t_project));
// 	lem_in->error = NULL;
// 	lem_in->error = NULL;
// 	str = ft_strdup("function1");
// 	temp = ft_lstnew(str, ft_strlen(str));
// 	lem_in->error = temp;
// 	error_log(lem_in, "function2");
// 	if (lem_in->error)
// 	{
// 		temp = lem_in->error;
// 		while(temp != NULL)
// 		{
// 			ft_printf("string in list: %s\n", (char*)temp->content);
// 			temp = temp->next;
// 		}
// 	}
// 	return (0);
// }

int			main(void)
{
	int				fd;
	t_project		*lem_in;
	t_bool			boolean;
	t_list			*temp;

	close(0);
	fd = open("../maps/valid_maps/map1.map", O_RDONLY);
	lem_in = (t_project*)malloc(sizeof(t_project));
	ERROR = NULL;
	FLAGS = 0;
	boolean = validate_input(lem_in);
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			ft_printf("-- Function that failed: %s\n\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	// ft_printf("boolean: %d\ninput_string:\n%s\n", boolean, lem_in->input_string);
	return (0);

}

// int			main(void)
// {
// 	t_project		*lem_in;
// 	t_bool			boolean;
// 	t_list			*temp;
	
// 	lem_in = (t_project*)malloc(sizeof(t_project));
// 	lem_in->error = NULL;
// 	boolean = error_log(lem_in, ft_strdup(__func__), FAIL);
// 	// ft_printf("String: %s\n");
// 	if (lem_in->error)
// 	{
// 		temp = lem_in->error;
// 		while(temp != NULL)
// 		{
// 			ft_printf("string in list: %s\n", (char*)temp->content);
// 			temp = temp->next;
// 		}
// 	}
// }