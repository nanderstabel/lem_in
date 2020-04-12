/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   machine.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 21:08:03 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:40:17 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H

# include "libft.h"

typedef short t_state;

/*
** Pseudo-boolean type.
*/

typedef struct s_project	t_project;

typedef enum
{
	FAIL,
	SUCCESS,
}	t_bool;

/*
** Prototype for all the 't_event functions'.
*/

typedef t_bool		(*t_event)(t_project *);

/*
** The mconfig struct can be used to send the configuration data of your project
** (the size, transition table and event table) to the machine struct. It can be
** be viewed as binding the binding compononent between your project and the
** state machine.
*/

typedef struct	s_mconfig
{
	t_state		size;
	t_state		**transitions;
	t_event		*events;
}				t_mconfig;

/*
** The machine struct. When configured with the data in the mconfig struct of a
** project it is used to loop through the different states and events of your
** project.
*/

typedef struct	s_machine
{
	t_state		size;
	t_state		current_state;
	t_state		last_state;
	t_bool		transition;
	t_state		**transition_table;
	t_event		*events;
}				t_machine;

t_bool			install_machine(t_machine **machine, t_mconfig *mconfig);
void			run_machine(t_machine *machine, t_project *project);
t_mconfig		*malloc_mconfig(t_state size);
t_bool			uninstall_machine(t_machine **machine);

#endif
