/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/23 20:28:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "machine.h"

# define OPTIONS			"d"
# define ARGC				lem_in->argc
# define ARGV				lem_in->argv
# define FLAGS				lem_in->flags
# define ERROR				lem_in->error
# define TRANSITIONS		(*mconfig)->transitions
# define EVENTS				(*mconfig)->events

# define DEBUG				(1 << 0)

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
	s_uninstall_machine
}	e_state;

enum
{
	s_install_machine_vi,
	s_find_error_vi,
	s_first_char_newline_vi,
	s_first_char_zero_vi,
	s_first_char_delim_vi,
	s_first_char_hash_vi,
	s_isdigit_to_newline_vi,
	s_isdigit_to_space_vi,
	s_check_start_flag_on_vi,
	s_check_end_flag_on_vi,
	s_second_char_hash_vi,
	s_check_line_end_command_vi,
	s_check_line_start_command_vi,
	s_switch_start_flag_on_vi,
	s_switch_end_flag_on_vi,
	s_check_link_flag_on_vi,
	s_isallnum_to_hyphen_vi,
	s_isallnum_to_newline_vi,
	s_find_hyphen_vi,
	s_switch_link_flag_on_vi,
	s_isallnum_to_space_vi,
	s_uninstall_machine_vi,
}	e_state_vi;

enum
{
	s_install_machine_opt,
	s_read_argument_opt,
	s_find_dash_opt,
	s_find_option_opt,
	s_validate_argument_opt,
	s_find_error_opt,
	s_uninstall_machine_opt,
}	e_state_opt;

/*
** The main struct type of this project. All the necassary variables can be
** referred to through this datatype.
*/

typedef struct					s_project
{
	int							argc;
	char						**argv;
	int							flags;
	char						*input_string;
	char						*line_to_check;
	t_list						*error;
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
t_bool							read_stdin(char **input_string);

t_bool							first_char_newline_vi(void *project);
t_bool							first_char_zero_vi(void	*project);
t_bool							first_char_delim_vi(void *project);
t_bool							first_char_hash_vi(void *project);
t_bool							second_char_hash_vi(void	*project);
t_bool							isdigit_to_newline_vi(void *project);
t_bool							isdigit_to_space_vi(void *project);
t_bool							check_start_flag_on_vi(void *project);
t_bool							check_end_flag_on_vi(void *project);
t_bool							check_line_start_command(void *project);
t_bool							check_line_end_command(void *project);
t_bool							check_link_flag_on_vi(void *project);
t_bool							switch_end_flag_on_vi(void *project);
t_bool							switch_start_flag_on_vi(void *project);
t_bool							isallnum_to_newline_vi(void *project);
t_bool							isallnum_to_hyphen_vi(void *project);
t_bool							find_hyphen_vi(void *project);
t_bool							switch_link_flag_on_vi(void *project);
t_bool							isallnum_to_space_vi(void *project);
t_bool							find_error(void *lem_in);
t_bool							print_output(void *lem_in);
t_bool							check_num_ants(char *line_to_check);
t_bool							check_sink(char *line_to_check);
t_bool							check_source(char *line_to_check);
t_bool							read_stdin(char **input_string);

t_bool							read_argument(void *project);
t_bool							find_dash(void *project);
t_bool							find_option(void *project);
t_bool							validate_argument(void *project);

#endif
