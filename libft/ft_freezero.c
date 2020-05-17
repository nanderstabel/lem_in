/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freezero.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 19:00:00 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/17 21:32:35 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freezero(void *mem, size_t size)
{
	if (!mem)
		return ;
	ft_bzero(mem, size);
	free(mem);
	mem = NULL;
}
