/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 14:54:32 by mgross         #+#    #+#                */
/*   Updated: 2019/02/06 10:07:22 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_skip_begin(char const *s1)
{
	int	c;

	c = 0;
	while (s1[c] == ' ' || s1[c] == '\t' || s1[c] == '\n')
	{
		c++;
	}
	return (c);
}

static int		ft_skip_end(char const *s1, size_t len)
{
	int c;

	c = 0;
	while (s1[len - 1] == ' ' || s1[len - 1] == '\t' || s1[len - 1] == '\n')
	{
		c++;
		len--;
	}
	return (c);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	c[2];
	size_t	len;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	c[0] = ft_skip_begin(s);
	c[1] = c[0];
	i = 0;
	if (c[0] != len)
		c[0] = c[0] + ft_skip_end(s, len);
	str = ft_strnew(len - c[0]);
	if (str == NULL)
		return (NULL);
	while ((len - c[0]) > 0)
	{
		str[i] = s[c[1]];
		i++;
		len--;
		c[1]++;
	}
	str[i] = '\0';
	return (str);
}
