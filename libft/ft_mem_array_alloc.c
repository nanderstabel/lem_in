/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mem_array_alloc.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 15:41:35 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:16:44 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function creates a 2D array the size of x and y and returns this array
** or a NULL pointer if its failed.
*/

void	**ft_mem_array_alloc(size_t x_dim, size_t size_x, size_t size_y)
{
	void		**array;
	size_t		x;

	x = 0;
	array = ft_memalloc(size_x);
	if (array == NULL)
		return (NULL);
	while (x < x_dim)
	{
		array[x] = ft_memalloc(size_y);
		if (array[x] == NULL)
			return (NULL);
		x++;
	}
	return (array);
}
