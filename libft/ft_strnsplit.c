/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 12:56:34 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c, size_t size)
{
	size_t	count;
	size_t	i;
	size_t	d;

	d = 0;
	i = 0;
	count = 1;
	while (s[i] != '\0' && i < size)
	{
		while (s[i] == c && s[i] != '\0' && i < size)
		{
			i++;
			count = 1;
		}
		if (s[i] != c && count == 1 && s[i] != '\0' && i < size)
		{
			d++;
			count = 0;
		}
		while (s[i] != c && s[i] != '\0' && i < size)
			i++;
	}
	return (d);
}

static char		**ft_malloc_string(char **str, char const *s, char c, size_t r)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	while (s[i] != '\0' && i < r)
	{
		count = 0;
		while (s[i] == c && s[i] != '\0' && i < r)
			i++;
		while (s[i] != c && s[i] != '\0' && i < r)
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

static char		**ft_string_copy(char **str, char const *s, char c, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d;

	d = 0;
	i = 0;
	while (s[d] != '\0' && d < size)
	{
		j = 0;
		while (s[d] == c && s[d] != '\0' && d < size)
			d++;
		if (s[d] != c && s[d] != '\0' && d < size)
		{
			while (s[d] != c && s[d] != '\0' && d < size)
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

char			**ft_strnsplit(char const *s, char c, size_t size)
{
	size_t	i;
	char	**str;

	if (s == NULL || !size)
		return (NULL);
	i = ft_count_words(s, c, size);
	str = (char**)malloc(sizeof(char*) * (i + 1));
	if (str == NULL)
		return (NULL);
	str = ft_malloc_string(str, s, c, size);
	str = ft_string_copy(str, s, c, size);
	return (str);
}
