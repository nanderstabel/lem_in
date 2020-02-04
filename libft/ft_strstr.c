/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 11:14:22 by mgross         #+#    #+#                */
/*   Updated: 2019/01/30 15:41:13 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	c;
	size_t	k;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		c = 0;
		k = i;
		if (haystack[k] == needle[c])
		{
			while (haystack[k] == needle[c] &&
				needle[c] != '\0' && haystack[k] != '\0')
			{
				c++;
				k++;
			}
			if (needle[c] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
