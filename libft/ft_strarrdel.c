/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 19:02:13 by mgross         #+#    #+#                */
/*   Updated: 2019/09/13 18:42:44 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function frees all levels of an 2D array.
*/

void	ft_strarrdel(char ***array, size_t size_x)
{
	size_t		x;

	x = 0;
	while (x < size_x)
	{
		ft_strdel(&(*array)[x]);
		x++;
	}
	free(*array);
	*array = NULL;
}
