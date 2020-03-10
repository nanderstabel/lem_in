/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addr_lstdelone.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 19:54:53 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/05 22:42:41 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addr_lstdelone(t_adlist **alst, void (*del)(void *, size_t))
{
	if (del)
		del((*alst)->address, 8);
	(*alst)->address = NULL;
	ft_memdel((void **)alst);
}
