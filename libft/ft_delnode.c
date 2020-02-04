/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_delnode.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 23:38:24 by nstabel        #+#    #+#                */
/*   Updated: 2019/11/16 23:51:03 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delnode(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
	content = NULL;
}
