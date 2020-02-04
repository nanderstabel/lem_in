/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 12:40:21 by mgross         #+#    #+#                */
/*   Updated: 2019/02/11 14:54:42 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_head;
	t_list	*temp;

	new_head = f(lst);
	temp = new_head;
	lst = lst->next;
	while (lst != NULL)
	{
		new_head->next = f(lst);
		lst = lst->next;
		new_head = new_head->next;
	}
	return (temp);
}
