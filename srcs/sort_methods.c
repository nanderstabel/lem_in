/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_methods.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:09:12 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 19:09:12 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					sort_by_level(void *a, void *b)
{
	t_vertex	*room_a;
	t_vertex	*room_b;

	room_a = ((t_edge *)(((t_adlist *)a)->address))->next;
	room_b = ((t_edge *)(((t_adlist *)b)->address))->next;
	if (room_a->level < room_b->level)
		return (1);
	return (0);
}

int					sort_by_length(void *a, void *b)
{
	t_adlist	*path_a;
	t_adlist	*path_b;

	path_a = ((t_adlist *)((t_adlist *)a)->address)->next;
	path_b = ((t_adlist *)((t_adlist *)b)->address)->next;
	if ((size_t)path_a->address < (size_t)path_b->address)
		return (1);
	return (0);
}
