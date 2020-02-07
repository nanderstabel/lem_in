/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_output.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/08 15:18:01 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/21 10:39:29 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function searches for specific definition inside the string. If it
** finds a corresponding one, it writes the # define code from the header
** onto the string.
*/

static int	set_style(t_flags *conv, char *style)
{
	if (ft_strequ(style, "bright") || ft_strequ(style, "bold"))
		write(conv->fd, BOLD, 4);
	else if (ft_strequ(style, "italics"))
		write(conv->fd, ITALICS, 4);
	else if (ft_strequ(style, "underline"))
		write(conv->fd, UNDERLINE, 4);
	else if (ft_strequ(style, "eoc"))
		write(conv->fd, EOC, 4);
	else
		return (0);
	conv->num += 4;
	return (1);
}

/*
** This function searches for specific definition inside the string. If it
** finds a corresponding one, it writes the # define code from the header
** onto the string.
*/

static int	set_color(t_flags *conv, char *color)
{
	if (ft_strequ(color, "black"))
		write(conv->fd, BLACK, 5);
	else if (ft_strequ(color, "red"))
		write(conv->fd, RED, 5);
	else if (ft_strequ(color, "green"))
		write(conv->fd, GREEN, 5);
	else if (ft_strequ(color, "yellow"))
		write(conv->fd, YELLOW, 5);
	else if (ft_strequ(color, "blue"))
		write(conv->fd, BLUE, 5);
	else if (ft_strequ(color, "magenta"))
		write(conv->fd, MAGENTA, 5);
	else if (ft_strequ(color, "cyan"))
		write(conv->fd, CYAN, 5);
	else if (ft_strequ(color, "white"))
		write(conv->fd, WHITE, 5);
	else
		return (0);
	conv->num += 5;
	return (1);
}

/*
** This function searches for specific definition inside the string. If it
** finds a corresponding one, it writes the # define code from the header
** onto the string.
*/

static int	set_off(t_flags *conv, char *off)
{
	if (ft_strequ(off, "bright off") || ft_strequ(off, "bold off"))
		write(conv->fd, BOLD_OFF, 5);
	else if (ft_strequ(off, "italics off"))
		write(conv->fd, ITALICS_OFF, 5);
	else if (ft_strequ(off, "underline off"))
		write(conv->fd, UNDERLINE_OFF, 5);
	else
		return (0);
	conv->num += 5;
	return (1);
}

/*
** This function copies the color specifications into a string then empty's
** the buf, and sends the string with the style specification to the diffrent
** functions to write to the buf.
*/

void		color_output(t_flags *conv, const char **format)
{
	char		*ansi;
	const char	*find;
	int			i;
	int			len;

	find = *format;
	len = ft_nchar(find, '}');
	find++;
	ansi = ft_strnew(len);
	i = 0;
	while (*find != '}')
	{
		ansi[i] = *find;
		find++;
		i++;
	}
	print_buf(conv);
	if (set_style(conv, ansi) + set_color(conv, ansi) + set_off(conv, ansi))
	{
		*format = find + 1;
		if (**format == '{')
			color_output(conv, format);
	}
	ft_strdel(&ansi);
}
