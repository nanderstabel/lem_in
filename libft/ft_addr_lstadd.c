/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addr_lstadd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 18:32:28 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/04 16:47:46 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addr_lstadd(t_adlist **alst, t_adlist *newlst)
{
	newlst->next = *alst;
	*alst = newlst;
}
