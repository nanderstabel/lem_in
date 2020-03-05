/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addr_lstdel.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 19:54:06 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/05 22:42:01 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addr_lstdel(t_adlist **alst, void (*del)(void *, size_t))
{
	t_adlist	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		ft_addr_lstdelone(alst, del);
		*alst = tmp;
	}
	ft_memdel((void **)alst);
}
