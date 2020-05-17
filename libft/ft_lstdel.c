/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 16:00:13 by mgross        #+#    #+#                 */
/*   Updated: 2020/05/18 01:38:04 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = *alst;
	if (alst == NULL)
		return ;
	while (temp->next != NULL)
	{
		temp = (*alst)->next;
		if (del)
			del((*alst)->content, (*alst)->content_size);
		(*alst)->next = NULL;
		free(*alst);
		*alst = temp;
	}
	if (del)
		del(temp->content, temp->content_size);
	free(*alst);
	*alst = NULL;
	alst = NULL;
}
