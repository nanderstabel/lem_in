/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_project.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 09:33:47 by nstabel       #+#    #+#                 */
/*   Updated: 2020/06/29 19:09:07 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void								free_all_paths(t_adlist *all_paths)
{
	t_adlist *tmp;

	if (!all_paths)
		return ;
	tmp = all_paths;
	while (tmp)
	{
		ft_addr_lstdel((t_adlist **)&tmp->address);
		tmp = tmp->next;
	}
	ft_addr_lstdel(&all_paths);
}

t_bool								free_project(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	free_all_paths(lem_in->all_paths);
	free(lem_in->input_string);
	ft_free_hash_table(&lem_in->all_rooms, free_vertex);
	ft_free_hash_table(&lem_in->all_links, free_edge);
	free(lem_in->room_pointers);
	free(lem_in->link_pointer);
	if (lem_in->all_ants)
		ft_addr_lstdel(&lem_in->all_ants);
	free(lem_in);
	return (SUCCESS);
}
