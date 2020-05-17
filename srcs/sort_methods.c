/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_methods.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:09:12 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/17 23:33:28 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					sort_by_level(void *a, void *b)
{
	t_vertex	*room_a;
	t_vertex	*room_b;

	room_a = ((t_edge *)(((t_list *)a)->content))->next;
	room_b = ((t_edge *)(((t_list *)b)->content))->next;
	if (room_a->level < room_b->level)
		return (1);
	return (0);
}

int					sort_by_length(void *a, void *b)
{
	t_list	*path_a;
	t_list	*path_b;

	path_a = ((t_list *)((t_list *)a)->content)->next;
	path_b = ((t_list *)((t_list *)b)->content)->next;
	if ((size_t)path_a->content < (size_t)path_b->content)
		return (1);
	return (0);
}
