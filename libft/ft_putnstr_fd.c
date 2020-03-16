/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 08:26:50 by mgross         #+#    #+#                */
/*   Updated: 2020/03/16 12:52:40 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(const int fd, char const *str, size_t len)
{
	if (str == NULL)
		return ;
	ft_putnchar_fd(fd, str, len);
}
