/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 14:07:39 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	char	*sub_str;

	c = 0;
	if (s == NULL)
		return (NULL);
	sub_str = ft_strnew(len);
	if (sub_str == NULL)
		return (NULL);
	while (c < len)
	{
		sub_str[c] = s[start];
		start++;
		c++;
	}
	sub_str[c] = '\0';
	return (sub_str);
}
