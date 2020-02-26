/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 16:50:26 by mgross         #+#    #+#                */
/*   Updated: 2020/02/26 08:46:12 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		main(void)
{
	t_project 		*lem_in;
	// char			*temp;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	EVAL_STR = ft_strdup("##start\nkdjkfj");
	// ft_printf("%s\n", temp);
	printf("return: %d\n", ft_strcmp_delim(EVAL_STR, "##starft\n", (int)'\n'));

	

	
	return (0);
}