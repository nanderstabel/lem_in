/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprior.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 19:18:07 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isprior(char *str, char prior, char rival)
{
	while (*str)
	{
		if (*str == prior)
			return (1);
		if (*str == rival)
			return (0);
		++str;
	}
	return (0);
}
