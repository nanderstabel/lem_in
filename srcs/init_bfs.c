/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bfs.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:50:27 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/17 11:30:30 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				init_bfs(t_project *lem_in)
{
	size_t	index;

	index = 0;
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (index < lem_in->all_rooms->size)
	{
		((t_vertex*)(lem_in->all_rooms->elem[index]->content))->level = 0;
		index++;
	}
	lem_in->que_list = ft_addr_lstnew((void*)lem_in->sink);
	lem_in->temp_que_list = lem_in->que_list;
	return (SUCCESS);
}
