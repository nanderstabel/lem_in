/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsrt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/21 15:07:34 by nstabel        #+#    #+#                */
/*   Updated: 2019/06/27 11:24:13 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		partition(t_list *head, t_list **front, t_list **back)
{
	t_list		*fast;
	t_list		*slow;

	if (head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

static t_list	*merge(t_list *a, t_list *b, int (*method)(void *, void *))
{
	t_list		*ret;

	ret = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (method(a, b))
	{
		ret = a;
		ret->next = merge(a->next, b, method);
	}
	else
	{
		ret = b;
		ret->next = merge(a, b->next, method);
	}
	return (ret);
}

void			ft_lstsrt(t_list **alst, int (*method)(void *, void *))
{
	t_list			*head;
	t_list			*a;
	t_list			*b;

	head = *alst;
	if (head == NULL || head->next == NULL)
		return ;
	partition(head, &a, &b);
	ft_lstsrt(&a, method);
	ft_lstsrt(&b, method);
	*alst = merge(a, b, method);
}
