/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 12:53:29 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *addr;

	addr = NULL;
	while (*s)
	{
		if ((unsigned char)c == *((char*)s))
			addr = s;
		s++;
	}
	if ((unsigned char)c == *((char*)s))
		return ((char*)s);
	if (addr != NULL)
		return ((char*)addr);
	return (NULL);
}
