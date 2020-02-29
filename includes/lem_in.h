/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/29 18:08:57 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "machine.h"

# define OPTIONS			"grl"
# define ARGC				lem_in->argc
# define ARGV				lem_in->argv
# define FLAGS				lem_in->flags
# define INPUT				lem_in->input_string
# define ERROR				lem_in->error
# define INPUT_CPY			lem_in->input_string_copy

# define NANTS				lem_in->nants
# define NROOMS				lem_in->nrooms
# define NLINKS				lem_in->nlinks
# define ROOMS				lem_in->rooms
# define LINKS				lem_in->links
# define TRANSITIONS		(*mconfig)->transitions
# define EVENTS				(*mconfig)->events

# define DEBUG_O			(1 << 0)
# define ROOMS_O			(1 << 1)
# define LINKS_O			(1 << 2)
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
	s_uninstall_machine,
}	e_state;

enum
{
	s_install_machine_opt,
	s_read_argument_opt,
	s_find_dash_opt,
	s_find_option_opt,
	s_validate_argument_opt,
	s_uninstall_machine_opt,
}	e_state_opt;

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
	s_install_machine_rms,
	s_initialize_table_rms,
	s_set_line,
	s_get_type,
	s_store_room,
	s_print_rooms,
	s_uninstall_machine_rms,
}	e_state_rms;

typedef enum
{
	standard,
	start,
	end
}	t_type;

typedef struct					s_vertex
{
	t_type						type;
	size_t						index;
	size_t						hash;
	char						*name;
}								t_vertex;

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
	char						*input_string_copy;
	char						*line_to_check;
	char						*line;
	size_t						nants;
	size_t						nrooms;
	size_t						nlinks;
	t_hash_table				*rooms;
	t_hash_table				*links;
	t_type						room_type;
	t_list						*error;
}								t_project;


/*
** Next are the 't_event functions'. They all return a t_bool 'transition'
** value.
*/

t_bool							set_options(t_project *lem_in);
t_bool							validate_input(t_project *lem_in);
t_bool							store_rooms(t_project *lem_in);
t_bool							store_links(t_project *lem_in);
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
// t_bool							find_error_vi(t_project *lem_in);
t_bool							skip_command_line_vi(t_project *lem_in);

t_bool							read_argument(t_project *lem_in);
t_bool							find_dash(t_project *lem_in);
t_bool							find_option(t_project *lem_in);
t_bool							validate_argument(t_project *lem_in);
t_bool							error_log(t_project *lem_in, char *str, t_bool ret);

#endif
