/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   machine.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 13:24:27 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/19 11:03:14 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H

# include "libft.h"

typedef short t_state;

/*
** Pseudo-boolean type.
*/

typedef enum
{
	FAIL,
	SUCCESS,
}	t_bool;

/*
** Prototype for all the 't_event functions'.
*/

typedef t_bool	(*t_event)(void *);

typedef struct	s_mconfig
{
	t_state		size;
	t_state		**transitions;
	t_event		*events;
}				t_mconfig;

typedef struct	s_machine
{
	t_state		size;
	t_state		current_state;
	t_bool		transition;
	t_state		**transition_table;
	t_event		*event;
}				t_machine;

t_bool			installing_machine(t_machine **machine, t_mconfig *mconfig);
void			run_machine(t_machine *machine, void *project);
t_mconfig		*malloc_mconfig(t_state size);

#endif
