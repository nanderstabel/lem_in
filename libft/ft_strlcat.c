/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:58:04 by mgross         #+#    #+#                */
/*   Updated: 2019/02/04 13:48:04 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	len;
	int		i;

	i = 0;
	dst_len = ft_strlen(dst);
	len = dst_len;
	if (size == 0)
		return (ft_strlen(src) + size);
	if (dst_len < (size - 1))
	{
		while (dst_len < (size - 1) && src[i] != '\0')
		{
			dst[dst_len] = src[i];
			i++;
			dst_len++;
		}
		dst[dst_len] = '\0';
	}
	if (size < len)
		return (ft_strlen(src) + size);
	if (size >= len)
		return (ft_strlen(src) + len);
	return (0);
}
