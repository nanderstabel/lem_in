/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_project.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 15:52:06 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/19 17:08:55 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void								free_all_paths(t_adlist *all_paths)
{
	t_adlist	*tmp;

	while (all_paths)
	{
		tmp = all_paths;
		ft_addr_lstdel(all_paths->address);
		ft_addr_lstdelone(&tmp);
		all_paths = all_paths->next;
	}
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
	//free_all_paths(ALL_PATHS);
	free(lem_in);
	return (SUCCESS);
}
