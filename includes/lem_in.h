/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/10 17:42:38 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "machine.h"

# define OPTIONS			"eglr"
# define ARGC				lem_in->argc
# define ARGV				lem_in->argv
# define FLAGS				lem_in->flags
# define INDEX				lem_in->index
# define STRING				lem_in->string
# define INPUT				lem_in->input_string
# define INPUT_CPY			lem_in->input_string_copy
# define NANTS				lem_in->nants
# define NROOMS				lem_in->nrooms
# define NLINKS				lem_in->nlinks
# define ALL_ROOMS			lem_in->all_rooms
# define ALL_LINKS			lem_in->all_links
# define ROOM_TYPE			lem_in->room_type
# define CURRENT_ROOM		lem_in->current_room
# define CURRENT_LINK		lem_in->current_link

# define ROOM_POINTERS		lem_in->room_pointers
# define ROOM_POINTER(x)	ROOM_POINTERS[x]
# define ROOM_ELEM(x)		((t_elem *)(ROOM_POINTER(x)))
# define ROOM_CONTENT(x)	((t_vertex *)ROOM_ELEM(x)->content)
# define LINK_POINTER		lem_in->link_pointer
# define LINK_ELEM			((t_elem *)LINK_POINTER)
# define LINK_CONTENT		((t_edge *)LINK_ELEM->content)

# define SOURCE				lem_in->source
# define SINK				lem_in->sink
# define PATHS_LIST			lem_in->paths_list
# define CURRENT_PATH		lem_in->current_path

# define ERROR_MSG			RED "An error occurred, machine was not able to: \n"
# define ERROR				lem_in->error
# define ERROR_LOG(x)		error_log(lem_in, ft_strjoin("\t- ", __func__), x)

# define TRANSITIONS		(*mconfig)->transitions
# define EVENTS				(*mconfig)->events

# define DEBUG_O			(1 << 0)
# define ERROR_O			(1 << 2)
# define ROOMS_O			(1 << 3)
# define LINKS_O			(1 << 4)
# define START				(1 << 5)
# define END				(1 << 6)
# define LINK				(1 << 7)
# define ROOM_LINE			(1 << 8)

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
	s_print_error,
	s_print_output,
	s_free_project,
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
	s_next_line_room_hash_vi,
	s_next_line_room_link_vi,
	s_check_link_flag_on_vi,
	s_all_flags_on_vi,
	s_input_file_done_vi,
	s_uninstall_machine_vi,
}	e_state_vi;

enum
{
	s_install_machine_rms,
	s_initialize_table_rms,
	s_set_line_rms,
	s_get_type,
	s_store_room,
	s_print_rooms,
	s_uninstall_machine_rms,
}	e_state_rms;

enum
{
	s_install_machine_lks,
	s_initialize_table_lks,
	s_save_roomnames,
	s_find_first_room,
	s_find_second_room,
	s_store_link,
	s_add_rooms_to_link,
	s_add_link_to_room,
	s_set_line,
	s_print_links,
	s_uninstall_machine_lks,
}	e_state_lks;

enum
{
	first_room,
	second_room
}	e_room;

typedef enum
{
	standard,
	source,
	sink
}	t_type;

typedef struct					s_vertex
{
	t_elem						*id;
	t_type						type;
	size_t						level;
	t_adlist					*links;
}								t_vertex;

typedef struct					s_edge
{
	t_elem						*id;
	size_t						capacity;
	t_vertex					*back;
	t_vertex					*forward;
}								t_edge;

/*
** The main struct type of this project. All the necassary variables can be
** referred to through this datatype.
*/

typedef struct					s_project
{
	int							argc;
	char						**argv;
	int							flags;
	size_t						index;
	char						*string;
	char						*input_string;
	char						*input_string_copy;
	size_t						nants;
	size_t						nrooms;
	size_t						nlinks;
	t_hash_table				*all_rooms;
	t_hash_table				*all_links;
	t_type						room_type;
	void						**room_pointers;
	void						*link_pointer;
	t_vertex					*current_room;
	t_edge						*current_link;
	t_vertex					*source;
	t_vertex					*sink;
	t_adlist					*paths_list;
	t_adlist					*current_path;
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
t_bool							find_paths(t_project *lem_in);
t_bool							augmenting_paths(t_project *lem_in);
t_bool							moving_ants(t_project *lem_in);
t_bool							print_error(t_project *lem_in);
t_bool							printing_output(t_project *lem_in);
t_bool							free_project(t_project *lem_in);
t_bool							read_stdin_vi(t_project *lem_in);

t_bool							first_char_newline_vi(t_project *lem_in);
t_bool							first_char_zero_vi(t_project *lem_in);
t_bool							first_char_delim_vi(t_project *lem_in);
t_bool							first_char_hash_vi(t_project *lem_in);
t_bool							second_char_hash_vi(t_project *lem_in);
t_bool							isdigit_to_newline_vi(t_project *lem_in);
t_bool							isdigit_to_space_vi(t_project *lem_in);
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
t_bool							print_error(t_project *lem_in);
t_bool							print_output(t_project *lem_in);
t_bool							input_file_done_vi(t_project *lem_in);
t_bool							all_flags_on_vi(t_project *lem_in);
t_bool							read_stdin(char **input_string);
t_bool							skip_command_line_vi(t_project *lem_in);
t_bool							next_line_room_link_vi(t_project *lem_in);
t_bool							next_line_room_hash_vi(t_project *lem_in);


t_bool							read_argument(t_project *lem_in);
t_bool							find_dash(t_project *lem_in);
t_bool							find_option(t_project *lem_in);
t_bool							validate_argument(t_project *lem_in);
t_bool							error_log(t_project *lem_in, char *str, t_bool ret);

t_vertex						*get_vertex(void);
void							*vertex_columns(t_hash_table *table);
void							free_vertex(void *content);
void							*get_edge(void);
void							*edge_columns(t_hash_table *table);
void							free_edge(void *content);


void	*ft_hash_table_append(t_hash_table *table, void *(*columns)(t_hash_table *table));
#endif
