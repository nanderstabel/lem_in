/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strval.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/30 14:36:06 by nstabel        #+#    #+#                */
/*   Updated: 2019/07/30 14:36:11 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strval(void *ptr)
{
	size_t		ret;
	char		*str;

	str = (char *)ptr;
	ret = 0;
	while (*str)
	{
		ret += *str;
		++str;
	}
	return (ret);
}
