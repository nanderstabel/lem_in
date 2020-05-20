/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putadlst.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/20 18:44:21 by nstabel       #+#    #+#                 */
/*   Updated: 2020/03/20 18:44:21 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putadlst(t_adlist *lst, char *(*content)(void *item), char *str)
{
	while (lst)
	{
		ft_putstr(content(lst->address));
		if (str && lst->next)
			ft_putstr(str);
		lst = lst->next;
	}
	ft_putchar('\n');
}
