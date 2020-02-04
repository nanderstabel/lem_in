/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 10:10:34 by mgross         #+#    #+#                */
/*   Updated: 2019/03/20 10:44:59 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function prints out all levels of an array, sperated by a newline. The
** last element of the 2D array has to point to NULL, otherwise behavior is
** undefined.
*/

void	ft_putstrarr(const char **array)
{
	int		j;

	j = 0;
	while (array[j] != NULL)
	{
		ft_putstr(array[j]);
		ft_putchar('\n');
		j++;
	}
}
