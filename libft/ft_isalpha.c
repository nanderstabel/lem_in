/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 08:33:03 by mgross         #+#    #+#                */
/*   Updated: 2019/01/24 08:37:52 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if (ft_islower(c) == 1)
	{
		return (1);
	}
	if (ft_isupper(c) == 1)
	{
		return (1);
	}
	return (0);
}
