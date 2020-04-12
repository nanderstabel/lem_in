/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 12:57:06 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "machine.h"

# define OPTIONS				"acdeglpru"
# define ARGC					lem_in->argc
# define ARGV					lem_in->argv
# define FLAGS					lem_in->flags
# define INDEX					lem_in->index
# define STRING					lem_in->string
# define INPUT					lem_in->input_string
# define INPUT_CPY				lem_in->input_string_copy
# define NANTS					lem_in->nants
# define NROOMS					lem_in->nrooms
# define NLINKS					lem_in->nlinks
# define ALL_ROOMS				lem_in->all_rooms
# define ALL_LINKS				lem_in->all_links
# define ROOM_TYPE				lem_in->room_type
# define CURRENT_ROOM			lem_in->current_room
# define CURRENT_LINK			lem_in->current_link
# define CURRENT_ROOM_LINKS		CURRENT_ROOM->links

# define ROOM_POINTERS			lem_in->room_pointers
# define ROOM_POINTER(x)		ROOM_POINTERS[x]
# define ROOM_ELEM(x)			((t_elem *)(ROOM_POINTER(x)))
# define ROOM_CONTENT(x)		((t_vertex *)ROOM_ELEM(x)->content)
# define LINK_POINTER			lem_in->link_pointer
# define LINK_ELEM				((t_elem *)LINK_POINTER)
# define LINK_CONTENT			((t_edge *)LINK_ELEM->content)

# define SOURCE					lem_in->source
# define SINK					lem_in->sink
# define ROUND_NR				lem_in->round_nr
# define ALL_PATHS				lem_in->all_paths
# define CURRENT_PATH			lem_in->current_path
# define SELECTED				CURRENT_ROOM->selected

# define ERROR_MSG				RED "An error occurred, machine was not able to: \n"
# define ERROR					lem_in->error
# define ERROR_LOG(x)			error_log(lem_in, ft_strjoin("\t- ", __func__), x)

# define TRANSITIONS			(*mconfig)->transitions
# define EVENTS					(*mconfig)->events

# define QUE					lem_in->que_list
# define TEMP_QUE				lem_in->temp_que_list
# define VERTEX_IN_LIST			((t_vertex *)(lem_in->temp_que_list->address))
# define TEMP_LINKS				lem_in->temp
# define NEXT_ROOM				((t_edge*)(TEMP_LINKS->address))->next
# define NEXT_ROOM_LEVEL		((t_edge*)(TEMP_LINKS->address))->next->level
# define NEXT_ROOM_LINKS		((t_edge*)(TEMP_LINKS->address))->next->links
# define NEXT_ROOM_TEMP_LINKS			TEMP_QUE
# define NEXT_ROOM_TEMP_LINKS_CAPACITY	((t_edge*)(TEMP_QUE->address))->capacity

# define NEXT_ROOM_INDEX_CMP	((t_edge*)(NEXT_ROOM_TEMP_LINKS->address))->next->id->index
# define TEMP_LINK_CAPACITY		((t_edge*)(TEMP_LINKS->address))->capacity
# define TEMP_LINK_VISITED		((t_edge*)(TEMP_LINKS->address))->visited

// # define CURRENT_EDGE			CURRENT_LINK
# define EDGE_INDEX				CURRENT_LINK->id->index
# define CURRENT_ROOM_INDEX		CURRENT_ROOM->id->index
# define CURRENT_LINK_CAPACITY	CURRENT_LINK->capacity
# define NEXT_ROOM_INDEX		((t_edge*)(TEMP_LINKS->address))->next->id->index
# define INDEX_COPY				lem_in->index_copy
# define AUGMENT_PATHS			lem_in->aug_path_links
# define PATH_OFFSET			((t_adlist *)((t_adlist *)QUE->address))
# define PATH_ROUND				PATH_OFFSET->address
# define PATH_LENGTH			PATH_OFFSET->next->address
# define PATH_START				PATH_OFFSET->next->next	

# define CURRENT_ANT			((t_ant *)QUE->address)

# define DEBUG_O				(1 << 0)
# define ERROR_O				(1 << 2)
# define ROOMS_O				(1 << 3)
# define LINKS_O				(1 << 4)
# define DFS_O					(1 << 5)
# define USAGE_O				(1 << 6)
# define PATHS_O				(1 << 7)
# define AUGMENT_O				(1 << 8)
# define COUNT_O				(1 << 9)
# define START					(1 << 10)
# define END					(1 << 11)
# define LINK					(1 << 12)
# define ROOM_LINE				(1 << 13)

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
	s_label_graph_s_to_t,
	s_augment_paths,
	s_choose_graph,
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
	s_print_usage_message,
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
	s_print_tables_rms,
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
	s_add_room_to_link,
	s_add_link_to_room,
	s_swap_rooms,
	s_set_line,
	s_print_tables_lks,
	s_uninstall_machine_lks,
}	e_state_lks;

enum
{
	s_install_machine_bfs,
	s_init_bfs,
	s_que_list_remain_bfs,
	s_edge_list_remain_bfs,
	s_vertex_has_level_bfs,
	s_capacity_available_bfs,
	s_update_level_and_que_bfs,
	s_print_tables_bfs,
	s_uninstall_machine_bfs,
}	e_state_bfs;

enum
{
	s_install_machine_bfs_s_to_t,
	s_init_bfs_s_to_t,
	s_que_list_remain_bfs_s_to_t,
	s_edge_list_remain_bfs_s_to_t,
	s_vertex_has_level_bfs_s_to_t,
	s_capacity_available_bfs_s_to_t,
	s_update_level_and_que_bfs_s_to_t,
	s_print_tables_bfs_s_to_t,
	s_uninstall_machine_bfs_s_to_t,
}	e_state_bfs_s_to_t;

enum
{
	s_install_machine_augp,
	s_init_augp,
	s_capacity_from_source_augp,
	s_capacity_to_lower_level_augp,
	s_capacity_to_higher_level_augp,
	s_capacity_away_from_augment_augp,
	s_check_capacity_to_lower_level_augp,
	s_get_indexes_edges_augp,
	s_current_room_sink_augp,
	s_current_room_source_augp,
	s_clear_capacity_on_graph_augp,
	s_print_tables_augp,
	s_uninstall_machine_augp,
}	e_state_augp;

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
	size_t						visited;
	t_adlist					*selected;
	t_adlist					*links;
}								t_vertex;

typedef struct					s_edge
{
	t_elem						*id;
	size_t						capacity;
	size_t						visited;
	t_vertex					*next;
}								t_edge;

typedef struct					s_ant
{
	char						*name;
	t_adlist					*location;
}								t_ant;

typedef struct					s_graph_vars
{
	size_t						source_ants;
	size_t						sink_ants;
	size_t						turns;
}								t_graph_vars;

/*
** The main struct type of this project. All the necassary variables can be
** referred to through this datatype.
*/

typedef struct					s_project
{
	int							count;//temp


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
	size_t						nturns;
	t_hash_table				*all_rooms;
	t_hash_table				*all_links;
	t_type						room_type;
	void						**room_pointers;
	void						*link_pointer;
	t_vertex					*current_room;
	t_edge						*current_link;
	t_vertex					*source;
	t_vertex					*sink;

	size_t						level;
	t_adlist					*que_list;
	t_adlist					*temp_que_list;
	t_adlist					*temp;
	t_adlist					*aug_path_links;

	t_adlist					*all_ants;
	t_ant						*current_ant;
	t_adlist					*all_paths;
	t_adlist					*current_path;

	size_t						round_nr;
	size_t						round_temp;
	t_graph_vars				graph_vars;
	size_t						index_copy;
	t_list						*error;
	int							fd;
}								t_project;

/*
** Next are the 't_event functions'. They all return a t_bool 'transition'
** value.
*/

t_bool							set_options(t_project *lem_in);
t_bool							validate_input(t_project *lem_in);
t_bool							store_rooms(t_project *lem_in);
t_bool							store_links(t_project *lem_in);
t_bool							label_graph(t_project *lem_in);
t_bool							label_graph_s_to_t(t_project *lem_in);
t_bool							find_paths(t_project *lem_in);
t_bool							augmenting_paths(t_project *lem_in);
t_bool							choose_graph(t_project *lem_in);
t_bool							move_ants(t_project *lem_in);
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

t_bool							init_bfs(t_project *lem_in);
t_bool							que_list_remain_bfs(t_project *lem_in);
t_bool							edge_list_remain_bfs(t_project *lem_in);
t_bool							capacity_available_bfs(t_project *lem_in);
t_bool							vertex_has_level_bfs(t_project *lem_in);
t_bool							update_level_and_que_bfs(t_project *lem_in);

t_bool							init_bfs_s_to_t(t_project *lem_in);
t_bool							que_list_remain_bfs_s_to_t(t_project *lem_in);
t_bool							edge_list_remain_bfs_s_to_t(t_project *lem_in);
t_bool							capacity_available_bfs_s_to_t(t_project *lem_in);
t_bool							vertex_has_level_bfs_s_to_t(t_project *lem_in);
t_bool							update_level_and_que_bfs_s_to_t(t_project *lem_in);

t_bool							capacity_from_source_augp(t_project *lem_in);
t_bool 							capacity_to_lower_level_augp(t_project *lem_in);
t_bool							capacity_away_from_augment_augp(t_project *lem_in);
t_bool							init_augp(t_project *lem_in);
t_bool							capacity_to_higher_level_augp(t_project *lem_in);
t_bool							get_indexes_edges_augp(t_project *lem_in);
t_bool							check_capacity_to_lower_level_augp(t_project *lem_in);
t_bool							current_room_sink_augp(t_project *lem_in);
t_bool							current_room_source_augp(t_project *lem_in);
t_bool							clear_capacity_on_graph_augp(t_project *lem_in);



t_bool							print_tables(t_project *lem_in);

#endif
