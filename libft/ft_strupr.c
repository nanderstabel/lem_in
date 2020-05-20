/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strupr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 22:13:27 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupr(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s == NULL || str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = ft_toupper(s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
