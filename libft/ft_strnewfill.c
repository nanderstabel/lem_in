/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnewfill.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 10:44:47 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewfill(size_t len, char c)
{
	return (ft_memset(ft_strnew(len), c, len));
}
