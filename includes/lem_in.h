/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/20 18:29:05 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "machine.h"

/*
** All the possible t_states of the machine.
*/

enum
{
	s_install_machine,
	s_set_options,
	s_validate_input,
	s_store_rooms,
	s_store_links,
	s_label_graph,
	s_find_paths,
	s_augment_paths,
	s_move_ants,
	s_find_error,
	s_print_output,
	s_uninstall_machine,
	s_idle
}	e_state;

/*
** The main struct type of this project. All the necassary variables can be
** referred to through this datatype.
*/

typedef struct					s_project
{
	int							argc;
	char						**argv;
	char						*input_string;
}								t_project;

/*
** Next are the 't_event functions'. They all return a t_bool 'transition'
** value.
*/

t_bool							set_options(void *project);
t_bool							validate_input(void *project);
t_bool							storing_rooms(void *lem_in);
t_bool							storing_links(void *lem_in);
t_bool							labeling_graph(void *lem_in);
t_bool							finding_paths(void *lem_in);
t_bool							augmenting_paths(void *lem_in);
t_bool							moving_ants(void *lem_in);
t_bool							finding_error(void *lem_in);
t_bool							printing_output(void *lem_in);
t_bool							uninstalling_machine(void *lem_in);
t_bool							check_num_ants(char *line_to_check);
t_bool							check_sink(char *line_to_check);
t_bool							check_source(char *line_to_check);
t_bool							read_stdin(char **input_string);
t_bool							isdigit_to_char(char **line_to_check, int c);
t_bool							isallnum_to_char(char **line_to_check, int c);
// t_bool							check_rooms(char *line_to_check);

#endif
