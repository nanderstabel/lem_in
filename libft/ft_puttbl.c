/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puttbl.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 19:37:04 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/03 17:30:53 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_puttbl(t_hash_table *table)
{
	size_t		i;
	size_t		len;
	t_elem		*tmp;
	//char		*hash;

	if (!table)
		return ;
	i = 0;
	ft_putchar(10);
	if (table->title)
		ft_printf("%s:\n", table->title);
	len = 0;
	i = 0;
	while (i < table->size)
	{
		tmp = (t_elem *)table->elem[i];
		if (tmp)
			if (len < ft_strlen(tmp->name))
				len = ft_strlen(tmp->name);
		++i;
	}
	len += 8;
	ft_printf("\x1B[4m%-*s%-*s%-*s%-*s\e[0m\n\n", ft_ndigits(table->size) + 7, "index", 18, "address", len, "name", 9, "hash");
	i = 0;
	while (i < table->size)
	{
		tmp = (t_elem *)table->elem[i];
		ft_printf("[%*i] --> %-*p", ft_ndigits(table->size), i, 18, table->elem[i]);
		if (tmp)
			ft_printf("%-*s%-*s", len, tmp->name, 9, ft_itoa_base((unsigned long long)(tmp->hash), 16));
		ft_putchar(10);
		++i;
	}
	ft_putchar(10);
}
