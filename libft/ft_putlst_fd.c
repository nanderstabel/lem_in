/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlst_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: zitzak <zitzak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 20:12:15 by zitzak        #+#    #+#                 */
/*   Updated: 2020/05/22 20:13:08 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlst_fd(t_list *lst, char *str, int fd)
{
	while (lst)
	{
		write(fd, lst->content, lst->content_size);
		if (str && lst->next)
			ft_putstr_fd(str, fd);
		lst = lst->next;
	}
	ft_putchar_fd('\n', fd);
}
