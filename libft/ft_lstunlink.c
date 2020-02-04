/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstunlink.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 14:29:48 by mgross         #+#    #+#                */
/*   Updated: 2019/03/08 18:02:12 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This functions first finds the element send to it in the list send to it. It
** then removes the element from the list and linkes the one before and after
** with each other. It then frees the element which got send to the function.
** If the element is not in the list, it will return NULL;
*/

static t_list	*ft_split_function(t_list **head, t_list *lst, t_list *temp)
{
	if (*head == lst && temp->next == NULL)
	{
		free(lst->content);
		free(lst);
		*head = NULL;
		return (NULL);
	}
	else if (*head == lst && temp == lst)
	{
		*head = temp->next;
		free(lst->content);
		free(lst);
		return (NULL);
	}
	else if (temp->next == lst && temp->next->next == NULL)
	{
		temp->next = NULL;
		free(lst->content);
		free(lst);
		return (NULL);
	}
	temp->next = temp->next->next;
	free(lst->next->content);
	free(lst);
	return (NULL);
}

t_list			*ft_lstunlink(t_list **head, t_list *lst)
{
	t_list	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (temp == lst)
			break ;
		else if (temp->next == lst)
			break ;
		temp = temp->next;
	}
	if (temp == NULL)
		return (lst);
	ft_split_function(head, lst, temp);
	return (NULL);
}
