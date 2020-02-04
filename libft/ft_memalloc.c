/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 09:52:17 by mgross         #+#    #+#                */
/*   Updated: 2019/09/13 14:08:50 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	new = (void*)malloc(size);
	if (new == NULL)
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
