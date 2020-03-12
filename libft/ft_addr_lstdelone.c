/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addr_lstdelone.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 19:54:53 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/12 20:22:25 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addr_lstdelone(t_adlist **alst)
{
	ft_putendl("here2.1.4.2.1");
	if (*alst == NULL)
		return ;
	ft_putendl("here2.1.4.2.2");
	ft_printf("address: %p\n", *alst);
	(*alst)->address = NULL;
	ft_putendl("here2.1.4.2.3");
	ft_memdel((void **)alst);
	ft_putendl("here2.1.4.2.4");
}
