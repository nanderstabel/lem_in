/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bfs_st.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 14:15:54 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/19 09:44:29 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				init_bfs_st(t_project *lem_in)
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
	lem_in->que_list = ft_addr_lstnew((void*)lem_in->source);
	lem_in->temp_que_list = lem_in->que_list;
	lem_in->source->level = 0;
	return (SUCCESS);
}
