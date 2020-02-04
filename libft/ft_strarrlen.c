/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:12:09 by mgross         #+#    #+#                */
/*   Updated: 2019/03/21 14:41:59 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function measures the length of an 2D array. If the last array is not
** pointed to NULL the bahavior is undefiend.
*/

size_t		ft_strarrlen(const char **array)
{
	size_t	len;

	len = 0;
	while (array[len] != NULL)
	{
		len++;
	}
	return (len);
}
