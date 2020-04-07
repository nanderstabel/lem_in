/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_project.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 09:33:47 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/07 10:46:17 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void								free_all_paths(t_adlist *all_paths)
{
	t_adlist *tmp;

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
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	free(INPUT);
	ft_free_hash_table(&ALL_ROOMS, free_vertex);
	ft_free_hash_table(&ALL_LINKS, free_edge);
	free(ROOM_POINTERS);
	free(LINK_POINTER);
	free_all_paths(ALL_PATHS);
	free(lem_in);
	return (SUCCESS);
}
