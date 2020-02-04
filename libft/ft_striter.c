/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 12:46:48 by mgross         #+#    #+#                */
/*   Updated: 2019/02/04 07:54:19 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		(*f)(&s[i]);
		i++;
	}
}
