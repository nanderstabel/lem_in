/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc_mconfig.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 17:30:00 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/19 10:38:38 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

t_mconfig		*malloc_mconfig(t_state size)
{
	t_mconfig		*mconfig;
	t_state			proxy;

	mconfig = (t_mconfig *)ft_memalloc(sizeof(t_mconfig));
	mconfig->size = size;
	mconfig->transitions = \
		(t_state **)malloc(sizeof(t_state *) * size);
	proxy = 0;
	while (proxy < size)
	{
		mconfig->transitions[proxy] = (t_state *)malloc(sizeof(t_state) * 2);
		++proxy;
	}
	mconfig->events = (t_event *)malloc(sizeof(t_event) * size);
	return (mconfig);
}
