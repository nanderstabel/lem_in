/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 12:54:58 by mgross         #+#    #+#                */
/*   Updated: 2019/01/30 15:44:03 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	k;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (i < len && haystack[i] != '\0')
	{
		c = 0;
		k = i;
		if (haystack[k] == needle[c])
		{
			while (haystack[k] == needle[c] &&
				needle[c] != '\0' && haystack[k] != '\0' && k < len)
			{
				k++;
				c++;
			}
			if (needle[c] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
