/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 23:03:38 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/17 23:10:22 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_ptr(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = (void *)content;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
