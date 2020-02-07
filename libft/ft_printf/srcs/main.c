/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 14:42:18 by mgross         #+#    #+#                */
/*   Updated: 2020/01/17 13:56:42 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_printf_fd(1, format, ap));
}

int		ft_dprintf(const int fd, const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_printf_fd(fd, format, ap));
}
