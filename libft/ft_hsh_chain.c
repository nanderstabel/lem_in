/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hsh_chain.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 16:13:38 by nstabel        #+#    #+#                */
/*   Updated: 2019/11/17 16:53:50 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_hsh_chain(void **ar, size_t size, size_t hsh(void *))
{
	t_list		**list_ptr;
	size_t		i;
	size_t		index;

	list_ptr = (t_list **)malloc(sizeof(t_list *) * size);
	i = size;
	while (i)
	{
		list_ptr[i] = NULL;
		--i;
	}
	list_ptr[i] = NULL;
	while (ar[i])
	{
		index = hsh((void *)ar[i]) % size;
		if (list_ptr[index])
			ft_lstapp(&list_ptr[index], ft_lstnew(ar[i], sizeof(t_list)));
		else
			list_ptr[index] = ft_lstnew(ar[i], sizeof(ar[i]));
		++i;
	}
	return (list_ptr);
}
