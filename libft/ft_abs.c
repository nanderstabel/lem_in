/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 20:21:43 by nstabel        #+#    #+#                */
/*   Updated: 2019/11/28 20:23:19 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return ((size_t)nb);
}