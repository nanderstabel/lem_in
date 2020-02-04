/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 17:17:08 by mgross         #+#    #+#                */
/*   Updated: 2019/04/03 11:28:40 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	d;

	d = 0;
	i = 0;
	count = 1;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
			count = 1;
		}
		if (s[i] != c && count == 1 && s[i] != '\0')
		{
			d++;
			count = 0;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (d);
}

static char		**ft_malloc_string(char **str, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		count = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			count++;
		}
		if (count > 0)
		{
			str[j] = ft_strnew(count);
			if (str[j] == NULL)
				return (NULL);
			j++;
		}
	}
	return (str);
}

static char		**ft_string_copy(char **str, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	d;

	d = 0;
	i = 0;
	while (s[d] != '\0')
	{
		j = 0;
		while (s[d] == c && s[d] != '\0')
			d++;
		if (s[d] != c && s[d] != '\0')
		{
			while (s[d] != c && s[d] != '\0')
			{
				str[i][j] = s[d];
				j++;
				d++;
			}
			str[i][j] = '\0';
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**str;

	if (s == NULL)
		return (NULL);
	i = ft_count_words(s, c);
	str = (char**)malloc(sizeof(char*) * (i + 1));
	if (str == NULL)
		return (NULL);
	str = ft_malloc_string(str, s, c);
	str = ft_string_copy(str, s, c);
	return (str);
}
