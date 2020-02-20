/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 16:50:26 by mgross         #+#    #+#                */
/*   Updated: 2020/02/20 17:07:37 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		main(void)
{
	char	*str;
	t_bool	boolean;

	str = ft_strdup("12343568\n9374595");
	boolean = isdigit_to_char(&str, (int)'\n');
	ft_printf("boolean: %d\nstr: %s\n", boolean, str);

	return (0);
}