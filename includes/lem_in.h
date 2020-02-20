/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/20 19:26:14 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "machine.h"

# define TRANSITION (*mconfig)->transitions 


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

enum
{
	s_install_machine_vi,
	s_point_line_vi,
	s_check_line_ants_vi,
	// s_set_options,
	// s_validate_input,
	// s_store_rooms,
	// s_store_links,
	// s_label_graph,
	// s_find_paths,
	// s_augment_paths,
	// s_move_ants,
	// s_find_error,
	// s_print_output,
	// s_uninstall_machine,
	s_idle_vi
}	e_state_vi;

/*
** The main struct type of this project. All the necassary variables can be
** referred to through this datatype.
*/

typedef struct					s_project
{
	int							argc;
	char						**argv;
	char						*input_string;
	char						*line_to_check;
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
t_bool							check_line_ants(char *line_to_check);
t_bool							check_link_sink_command(char *line_to_check);
t_bool							check_link_source_command(char *line_to_check);
t_bool							read_stdin(char **input_string);
t_bool							isdigit_to_char(char **line_to_check, int c);
t_bool							isallnum_to_char(char **line_to_check, int c);
t_bool							check_line_rooms(char *line_to_check);

#endif
