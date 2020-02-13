/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/13 16:27:48 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

/*
** All the possible t_states of the machine.
*/

typedef enum
{
	install_machine,
	set_flags,
	validate_input,
	store_rooms,
	store_links,
	label_graph,
	find_paths,
	augment_paths,
	move_ants,
	find_error,
	print_output,
	uninstall_machine,
	idle
}	t_state;

/*
** Pseudo-boolean type.
*/

typedef enum
{
	FAIL,
	SUCCESS
}	t_bool;

/*
** The main struct type of this project. All the necassary variables can be
** referred to through this datatype.
*/

typedef struct					s_project
{
	int							argc;
	char						**argv;
}								t_project;

/*
** Prototype for all the 't_event functions'.
*/

typedef t_bool					(*t_event)(t_project *);

typedef struct					s_machine
{
	t_state						current_state;
	t_bool						transition;
	t_state						**transition_table;
	t_event						*event;
}								t_machine;

/*
** Next are the 't_event functions'. They all return a t_bool 'transition' 
** value.
*/

t_bool							setting_flags(t_project *lem_in);
t_bool							validating_input(t_project *lem_in);
t_bool							storing_rooms(t_project *lem_in);
t_bool							storing_links(t_project *lem_in);
t_bool							labeling_graph(t_project *lem_in);
t_bool							finding_paths(t_project *lem_in);
t_bool							augmenting_paths(t_project *lem_in);
t_bool							moving_ants(t_project *lem_in);
t_bool							finding_error(t_project *lem_in);
t_bool							printing_output(t_project *lem_in);
t_bool							uninstalling_machine(t_project *lem_in);

#endif
