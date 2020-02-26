/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/26 13:30:00 by mgross        ########   odam.nl         */
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
# define EVAL_STR			lem_in->input_eval_string
# define TRANSITIONS		(*mconfig)->transitions
# define EVENTS				(*mconfig)->events

# define DEBUG				(1 << 0)
# define START				(1 << 3)
# define END				(1 << 4)
# define LINK				(1 << 5)

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
	s_read_stdin_vi,
	s_first_char_newline_vi,
	s_first_char_zero_vi,
	s_first_char_delim_vi,
	s_first_char_hash_vi,
	s_second_char_hash_vi,
	s_find_hyphen_vi,
	s_isdigit_to_newline_vi,
	s_isdigit_to_space_vi,
	s_isallnum_to_hyphen_vi,
	s_isallnum_to_space_vi,
	s_isallnum_to_newline_vi,
	s_check_if_end_command_line_vi,
	s_check_if_start_command_line_vi,
	s_switch_start_flag_on_vi,
	s_switch_end_flag_on_vi,
	s_switch_link_flag_on_vi,
	s_skip_command_line_vi,
	s_check_link_flag_on_vi,
	s_all_flags_on_vi,
	s_input_file_done_vi,
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
	char						*input_eval_string;
	t_list						*error;
}								t_project;

/*
** Next are the 't_event functions'. They all return a t_bool 'transition'
** value.
*/

t_bool							set_options(t_project *lem_in);
t_bool							validate_input(t_project *lem_in);
t_bool							storing_rooms(t_project *lem_in);
t_bool							storing_links(t_project *lem_in);
t_bool							labeling_graph(t_project *lem_in);
t_bool							finding_paths(t_project *lem_in);
t_bool							augmenting_paths(t_project *lem_in);
t_bool							moving_ants(t_project *lem_in);
t_bool							finding_error(t_project *lem_in);
t_bool							printing_output(t_project *lem_in);
t_bool							uninstalling_machine(t_project *lem_in);
t_bool							read_stdin_vi(t_project *lem_in);

t_bool							first_char_newline_vi(t_project *lem_in);
t_bool							first_char_zero_vi(t_project *lem_in);
t_bool							first_char_delim_vi(t_project *lem_in);
t_bool							first_char_hash_vi(t_project *lem_in);
t_bool							second_char_hash_vi(t_project *lem_in);
t_bool							isdigit_to_newline_vi(t_project *lem_in);
t_bool							isdigit_to_space_vi(t_project *lem_in);
// t_bool							check_start_flag_on_vi(t_project *lem_in);
// t_bool							check_end_flag_on_vi(t_project *lem_in);
t_bool							check_if_start_command_line_vi(t_project *lem_in);
t_bool							check_if_end_command_line_vi(t_project *lem_in);
t_bool							check_link_flag_on_vi(t_project *lem_in);
t_bool							switch_end_flag_on_vi(t_project *lem_in);
t_bool							switch_start_flag_on_vi(t_project *lem_in);
t_bool							isallnum_to_newline_vi(t_project *lem_in);
t_bool							isallnum_to_hyphen_vi(t_project *lem_in);
t_bool							find_hyphen_vi(t_project *lem_in);
t_bool							switch_link_flag_on_vi(t_project *lem_in);
t_bool							isallnum_to_space_vi(t_project *lem_in);
t_bool							find_error(t_project *lem_in);
t_bool							print_output(t_project *lem_in);
t_bool							input_file_done_vi(t_project *lem_in);
t_bool							all_flags_on_vi(t_project *lem_in);
t_bool							read_stdin(char **input_string);
t_bool							find_error_vi(t_project *lem_in);
t_bool							skip_command_line_vi(t_project *lem_in);

t_bool							read_argument(t_project *lem_in);
t_bool							find_dash(t_project *lem_in);
t_bool							find_option(t_project *lem_in);
t_bool							validate_argument(t_project *lem_in);

#endif
