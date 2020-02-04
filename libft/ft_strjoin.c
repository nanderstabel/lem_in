/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 14:30:59 by mgross         #+#    #+#                */
/*   Updated: 2019/02/06 10:06:18 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*cat_str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	cat_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (cat_str == NULL)
		return (NULL);
	while (*s1)
	{
		cat_str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		cat_str[i] = *s2;
		i++;
		s2++;
	}
	cat_str[i] = '\0';
	return (cat_str);
}
