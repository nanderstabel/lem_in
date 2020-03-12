/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addr_lstdel.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 19:54:06 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/12 12:47:39 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addr_lstdel(t_adlist **alst)
{
	t_adlist	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		ft_addr_lstdelone(alst);
		*alst = tmp;
	}
	ft_memdel((void **)alst);
}
