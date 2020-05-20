/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tables_pt.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 20:00:56 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/20 12:57:28 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				print_rooms(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t\t%s\n", __func__);
	if (lem_in->flags & ROOMS_O && lem_in->all_rooms)
		if (!ft_hash_table_print(lem_in->all_rooms, vertex_columns))
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

t_bool				print_links(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t\t%s\n", __func__);
	if (lem_in->flags & LINKS_O && lem_in->all_links)
		if (!ft_hash_table_print(lem_in->all_links, edge_columns))
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

static void			loop_paths(t_project *lem_in)
{
	lem_in->index = 0;
	while (lem_in->que_list && lem_in->que_list->content)
	{
		if ((size_t)((t_list *)((t_list *)\
			lem_in->que_list->content))->content != lem_in->index)
		{
			ft_printf("\tRound %i:\n", ((t_list *)((t_list *)\
				lem_in->que_list->content))->content);
			lem_in->index = (size_t)((t_list *)((t_list *)\
				lem_in->que_list->content))->content;
		}
		ft_printf("\t\tlength: %i --> ", ((t_list *)((t_list *)\
			lem_in->que_list->content))->next->content);
		ft_putlst(((t_list *)((t_list *)\
			lem_in->que_list->content))->next->next, vertex_name, "->");
		lem_in->que_list = lem_in->que_list->next;
	}
}

t_bool				print_paths(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t\t%s\n", __func__);
	if (lem_in->flags & PATHS_O)
	{
		if (lem_in->all_paths)
		{
			lem_in->que_list = lem_in->all_paths;
			ft_printf("\n{underline}Paths:{eoc}\n");
			loop_paths(lem_in);
			ft_putchar(10);
		}
	}
	return (SUCCESS);
}
