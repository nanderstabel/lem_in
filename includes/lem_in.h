/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/18 14:18:53 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

/*
** All the possible t_states of the machine.
*/

enum
{
	install_machine,
	set_options,
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
}	e_state;

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
** Next are the 't_event functions'. They all return a t_bool 'transition'
** value.
*/

t_bool							setting_options(void *lem_in);
t_bool							validating_input(void *lem_in);
t_bool							storing_rooms(void *lem_in);
t_bool							storing_links(void *lem_in);
t_bool							labeling_graph(void *lem_in);
t_bool							finding_paths(void *lem_in);
t_bool							augmenting_paths(void *lem_in);
t_bool							moving_ants(void *lem_in);
t_bool							finding_error(void *lem_in);
t_bool							printing_output(void *lem_in);
t_bool							uninstalling_machine(void *lem_in);

#endif
