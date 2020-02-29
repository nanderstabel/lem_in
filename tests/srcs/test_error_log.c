// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   test_error_log.c                                   :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: mgross <mgross@student.codam.nl>             +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2020/02/26 14:25:38 by mgross         #+#    #+#                */
// /*   Updated: 2020/02/26 16:42:42 by mgross        ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

#include "tests.h"

Test(error_log_suite, error_log_test)
{
	char			*str;
	t_project		*lem_in;
	t_bool			boolean;
	t_list			*temp;
	
	lem_in = (t_project*)malloc(sizeof(t_project));
	lem_in->error = NULL;
	boolean = error_log(lem_in, ft_strdup(__func__), FAIL);
	// ft_printf("String: %s\n");
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			// ft_printf("string in list: %s\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	lem_in->error = NULL;
	str = ft_strdup("function1");
	temp = ft_lstnew(str, ft_strlen(str));
	lem_in->error = temp;
	boolean = error_log(lem_in, ft_strdup("function2"), FAIL);
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			// ft_printf("string in list: %s\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
}
