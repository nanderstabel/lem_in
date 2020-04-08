/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 14:27:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/17 14:27:03 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstrev(t_list *alst)
{
	t_list	*a;
	t_list	*b;

	if (!alst)
		return (NULL);
	a = alst;
	while (a->next)
	{
		b = alst;
		alst = a->next;
		a->next = alst->next;
		alst->next = b;
	}
	return (alst);
}
