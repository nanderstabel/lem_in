/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 11:59:35 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlst(t_list *lst, char *str)
{
	while (lst)
	{
		write(1, lst->content, lst->content_size);
		if (str && lst->next)
			ft_putstr(str);
		lst = lst->next;
	}
	ft_putchar('\n');
}
