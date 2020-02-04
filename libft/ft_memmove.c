/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 12:18:21 by mgross         #+#    #+#                */
/*   Updated: 2019/01/28 11:49:42 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*srcs;
	size_t	index;

	index = 0;
	dest = (char*)dst;
	srcs = (char*)src;
	if (((srcs + len) - dest) > 0 && srcs < dest)
	{
		while (len > 0)
		{
			dest[len - 1] = srcs[len - 1];
			len--;
		}
	}
	else
	{
		while (index < len)
		{
			dest[index] = srcs[index];
			index++;
		}
	}
	return (dst);
}
