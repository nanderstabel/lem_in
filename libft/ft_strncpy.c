/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 16:54:13 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (len > 0)
	{
		if (src[i] == '\0')
		{
			while (len > 0)
			{
				dst[i] = '\0';
				i++;
				len--;
			}
			return (dst);
		}
		else
		{
			dst[i] = src[i];
			i++;
			len--;
		}
	}
	return (dst);
}
