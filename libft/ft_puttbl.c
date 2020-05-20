/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puttbl.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 19:37:04 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/20 13:00:30 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			header(t_hash_table *table)
{
	t_list		*h_format;
	t_list		*h_content;
	t_list		*width;

	h_format = table->header_format;
	h_content = table->header_content;
	width = table->width;
	write(1, UNDERLINE, 5);
	while (h_format && h_content && width)
	{
		ft_printf(h_format->content, width->content, h_content->content);
		h_format = h_format->next;
		h_content = h_content->next;
		width = width->next;
	}
	ft_putchar(10);
	write(1, EOC, 5);
}

static void			each_elem(t_hash_table *table, t_list *b_format, \
	t_list *width, size_t i)
{
	t_list	*b_content;

	if (i + 1 == table->size)
		write(1, UNDERLINE, 5);
	ft_printf(b_format->content, width->content, i);
	b_format = b_format->next;
	width = width->next;
	if (table->elem[i])
	{
		b_content = table->elem[i]->body_content;
		while (b_format && width)
		{
			ft_printf(b_format->content, width->content, (b_content->content));
			b_format = b_format->next;
			width = width->next;
			b_content = b_content->next;
		}
	}
	else
		ft_printf(table->body_format->next->next->content, \
			table->width->next->content, "0x0  ");
	b_format = table->body_format;
	width = table->width;
	ft_putchar(10);
}

static void			body(t_hash_table *table)
{
	t_list		*b_format;
	t_list		*width;
	size_t		i;

	i = 0;
	width = table->width;
	table->width->content -= 7;
	b_format = table->body_format;
	while (i < table->size)
	{
		each_elem(table, b_format, width, i);
		++i;
	}
	ft_putendl(EOC);
	table->width->content += 7;
}

void				ft_puttbl(t_hash_table *table)
{
	if (!table || !table->header_format)
		return ;
	ft_putchar(10);
	if (table->title)
		ft_printf("%s:\n", table->title);
	header(table);
	body(table);
}
