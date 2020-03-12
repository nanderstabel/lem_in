/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addr_lstdelone.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 19:54:53 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/12 12:47:51 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addr_lstdelone(t_adlist **alst)
{
	(*alst)->address = NULL;
	ft_memdel((void **)alst);
}
