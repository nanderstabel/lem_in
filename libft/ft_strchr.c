/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 10:17:49 by mgross         #+#    #+#                */
/*   Updated: 2019/05/21 14:59:45 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (((unsigned char)c) == *((char*)s))
		{
			return ((char*)s);
		}
		s++;
	}
	if (((unsigned char)c) == *((char*)s))
	{
		return ((char*)s);
	}
	return (NULL);
}
