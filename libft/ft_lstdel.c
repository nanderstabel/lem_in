/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 16:00:13 by mgross         #+#    #+#                */
/*   Updated: 2019/02/11 12:16:23 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = *alst;
	if (alst == NULL || del == NULL)
		return ;
	while (temp->next != NULL)
	{
		temp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		(*alst)->next = NULL;
		free(*alst);
		*alst = temp;
	}
	del(temp->content, temp->content_size);
	free(*alst);
	*alst = NULL;
	alst = NULL;
}
