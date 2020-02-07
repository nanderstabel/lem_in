/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 08:26:50 by mgross         #+#    #+#                */
/*   Updated: 2019/07/16 15:28:09 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(const int fd, char const *str, size_t len)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	ft_putnchar_fd(fd, str, len);
}
