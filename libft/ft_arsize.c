/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arsize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 16:33:50 by nstabel        #+#    #+#                */
/*   Updated: 2019/07/30 13:09:22 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_arsize(void **ar)
{
	size_t	size;

	size = 0;
	while (ar[size])
	{
		if (size == 2147483647 && ar[size + 1])
			return (0);
		++size;
	}
	return (size);
}
