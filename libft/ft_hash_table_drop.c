/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash_table_drop.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/18 17:03:12 by nstabel       #+#    #+#                 */
/*   Updated: 2020/03/18 17:03:12 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void     cut_list(t_list *row, size_t cutoff)
{
    size_t      index;

    index = 1;
    while (index < cutoff)
    {
        row = row->next;
        ++index;
    }
    ft_lstdel(&row->next, ft_freezero);
    row->next = NULL;
}

static void     cut_adlist(t_adlist *row, size_t cutoff)
{
    size_t      index;

    index = 1;
    while (index < cutoff)
    {
        row = row->next;
        ++index;
    }
    ft_addr_lstdel(&row->next);
    row->next = NULL;
}

void            *ft_hash_table_drop(t_hash_table *table, size_t cutoff)
{
    size_t      index;
    t_elem      *elem;

    if (!table || cutoff < 4)
        return (NULL);
    cut_list(table->header_content, cutoff);
    cut_list(table->header_format, cutoff);
    cut_list(table->body_format, cutoff);
    cut_adlist(table->width, cutoff);
    index = 0;
    while (index < table->size)
    {
        if (table->elem[index])
        {
            elem = table->elem[index];
            cut_adlist(elem->body_content, cutoff - 1);
        }
        ++index;
    }
    if (cutoff == 4)
        table->mounted = 0;
    return (table);
}
