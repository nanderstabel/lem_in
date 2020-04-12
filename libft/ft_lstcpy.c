/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/21 13:38:37 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstcpy(t_list *alst)
{
	t_list	*cpy;
	t_list	*tmp;

	if (alst == NULL && alst->next == NULL)
		return (NULL);
	cpy = ft_memalloc(sizeof(*alst));
	if (cpy == NULL)
		return (NULL);
	ft_memmove(cpy, alst, sizeof(*alst));
	tmp = cpy->next;
	alst = alst->next;
	while (alst)
	{
		tmp = ft_memalloc(sizeof(*alst));
		ft_memmove(tmp, alst, sizeof(*alst));
		tmp = cpy->next;
		alst = alst->next;
	}
	return (cpy);
}
