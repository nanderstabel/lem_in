/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hsh_quadprob.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 16:15:30 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_hsh_quadprob(void **ar, size_t size, size_t hsh(void *))
{
	t_list		**list_ptr;
	size_t		i;
	size_t		j;
	size_t		index;

	list_ptr = (t_list **)malloc(sizeof(t_list *) * size);
	i = size;
	j = 0;
	while (i)
	{
		list_ptr[i] = NULL;
		--i;
	}
	list_ptr[i] = NULL;
	while (ar[i])
	{
		index = hsh((char *)ar[i]) % size;
		while (list_ptr[(index + j * j) % size])
			index = (index == size) ? 0 : index + 1;
		list_ptr[(index + j * j) % size] = ft_lstnew(ar[i], sizeof(ar[i]));
		++i;
	}
	return (list_ptr);
}
