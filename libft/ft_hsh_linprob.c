/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hsh_linprob.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 16:15:39 by nstabel        #+#    #+#                */
/*   Updated: 2019/07/30 14:31:44 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_hsh_linprob(void **ar, size_t size, size_t hsh(void *))
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
		index = hsh((char *)ar[i]) % size;
		while (list_ptr[index])
			index = (index == size) ? 0 : index + 1;
		list_ptr[index] = ft_lstnew(ar[i], sizeof(ar[i]));
		++i;
	}
	return (list_ptr);
}
