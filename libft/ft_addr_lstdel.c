/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addr_lstdel.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 19:54:06 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/12 20:25:00 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addr_lstdel(t_adlist **alst)
{
	t_adlist	*tmp;

	while (*alst)
	{
		ft_putendl("here2.1.4.1");
		tmp = *alst;
		ft_putendl("here2.1.4.2");
		ft_addr_lstdelone(&tmp);
		ft_putendl("here2.1.4.3");
		*alst = (*alst)->next;
		ft_putendl("here2.1.4.4");
	}
	ft_memdel((void **)alst);
}
