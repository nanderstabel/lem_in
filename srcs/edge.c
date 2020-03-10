/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edge.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 14:00:18 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/04 15:09:15 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				*get_edge(void)
{
	t_edge		*edge;

	edge = (t_edge *)malloc(sizeof(t_edge));
	edge->id = NULL;
	edge->capacity = 0;
	edge->back = NULL;
	edge->forward = NULL;
	return (edge);
}

void				free_edge(void *content)
{
	t_edge	*edge;

	edge = (t_edge *)content;
	if (!edge)
		return ;
	free(edge);
}
