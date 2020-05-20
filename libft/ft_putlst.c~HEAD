/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 11:59:35 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/18 00:58:22 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlst(t_list *lst, char *(*content)(void *item), char *str)
{
	while (lst)
	{
		if (content)
			ft_putstr(content(lst->content));
		else
			ft_putstr(str);
		if (str && lst->next)
			ft_putstr(str);
		lst = lst->next;
	}
	ft_putchar('\n');
}
