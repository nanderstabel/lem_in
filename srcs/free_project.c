/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_project.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 09:33:47 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/17 22:28:06 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void								free_all_paths(t_adlist *all_paths)
{
	t_adlist *tmp;

	if (!all_paths)
		return ;
	tmp = all_paths;
	ft_putendl("here1");
	while (tmp)
	{
		ft_putendl("here1.1");
		ft_addr_lstdel((t_adlist **)&tmp->address);
		ft_putendl("here1.2");
		tmp = tmp->next;
		ft_putendl("here1.3");
	}
	ft_putendl("here2");
	ft_addr_lstdel(&all_paths);
	ft_putendl("here3");
}

t_bool								free_project(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	ft_putendl("here1");
	free(lem_in->input_string);
	ft_putendl("here2");
	ft_free_hash_table(&lem_in->all_rooms, free_vertex);
	ft_putendl("here3");
	ft_free_hash_table(&lem_in->all_links, free_edge);
	ft_putendl("here4");
	free(lem_in->room_pointers);
	ft_putendl("here5");
	free(lem_in->link_pointer);
	ft_putendl("here6");
	free_all_paths(lem_in->all_paths);
	ft_putendl("here7");
	if (lem_in->all_ants)
		ft_addr_lstdel(&lem_in->all_ants);
	free(lem_in);
	ft_putendl("here8");
	return (SUCCESS);
}
