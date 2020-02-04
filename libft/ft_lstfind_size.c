/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfind_size.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 13:05:22 by mgross         #+#    #+#                */
/*   Updated: 2019/02/28 12:48:14 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function searches through the list for size. If it finds size it returns
** a pointer to the element in the list. If not it returns NULL.
*/

t_list	*ft_lstfind_size(t_list *head, size_t size)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp->content_size == size)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
