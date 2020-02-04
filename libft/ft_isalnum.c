/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 08:43:45 by mgross         #+#    #+#                */
/*   Updated: 2019/01/24 08:48:29 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1)
	{
		return (1);
	}
	if (ft_isdigit(c) == 1)
	{
		return (1);
	}
	return (0);
}
