/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/17 11:30:30 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "machine.h"

# define OPTIONS				"abcdeglpru"
// # define ARGC					lem_in->argc
// # define ARGV					lem_in->argv
// # define FLAGS					lem_in->flags
// # define INDEX					lem_in->index
// # define STRING					lem_in->string
// # define INPUT					lem_in->input_string
// # define INPUT_CPY				lem_in->input_string_copy
# define NANTS					lem_in->nants
# define NROOMS					lem_in->nrooms
# define NLINKS					lem_in->nlinks
// # define ALL_ROOMS				lem_in->all_rooms
// # define ALL_LINKS				lem_in->all_links
// # define ROOM_TYPE				lem_in->room_type
# define CURRENT_ROOM			lem_in->current_room
// # define CURRENT_LINK			lem_in->current_link
# define CURRENT_ROOM_LINKS		CURRENT_ROOM->links

// # define ROOM_POINTERS			lem_in->room_pointers
// # define ROOM_POINTER(x)		ROOM_POINTERS[x]
// # define ROOM_ELEM(x)			((t_elem *)(ROOM_POINTER(x)))
// # define ROOM_CONTENT(x)		((t_vertex *)ROOM_ELEM(x)->content)
// # define LINK_POINTER			lem_in->link_pointer
// # define LINK_ELEM				((t_elem *)LINK_POINTER)
// # define LINK_CONTENT			((t_edge *)LINK_ELEM->content)

// # define SOURCE					lem_in->source
// # define SINK					lem_in->sink
// # define ROUND_NR				lem_in->round_nr
// # define ALL_PATHS				lem_in->all_paths
// # define CURRENT_PATH			lem_in->current_path
// # define SELECTED				CURRENT_ROOM->selected

# define ERROR_MSG				RED "An error occurred, machine was not able to: \n"
# define ERROR					lem_in->error
// # define ERROR_LOG(x)			error_log(lem_in, ft_strjoin("\t- ", __func__), x)
// error_log(lem_in, ft_strjoin("\t- ", __func__), SUCCESS)
// error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL)


# define TRANSITIONS			(*mconfig)->transitions
# define EVENTS					(*mconfig)->events

# define QUE					lem_in->que_list
# define TEMP_QUE				lem_in->temp_que_list
# define VERTEX_IN_LIST			((t_vertex *)(lem_in->temp_que_list->address))
# define TEMP_LINKS				lem_in->temp

# define NEXT_ROOM				((t_edge*)(lem_in->temp->address))->next
// ((t_edge*)(lem_in->temp->address))->next

# define NEXT_ROOM_LEVEL		((t_edge*)(lem_in->temp->address))->next->level
# define NEXT_ROOM_LINKS		((t_edge*)(lem_in->temp->address))->next->links

# define NEXT_ROOM_TEMP_LINKS			lem_in->temp_que_list
# define NEXT_ROOM_TEMP_LINKS_CAPACITY	((t_edge*)(lem_in->temp_que_list->address))->capacity

# define NEXT_ROOM_INDEX_CMP	((t_edge*)(lem_in->temp_que_list->address))->next->id->index
# define TEMP_LINK_CAPACITY		((t_edge*)(lem_in->temp->address))->capacity
# define TEMP_LINK_VISITED		((t_edge*)(lem_in->temp->address))->visited

// # define CURRENT_EDGE			CURRENT_LINK
# define EDGE_INDEX				lem_in->current_link->id->index
# define CURRENT_ROOM_INDEX		lem_in->current_room->id->index
# define CURRENT_LINK_CAPACITY	lem_in->current_link->capacity
# define NEXT_ROOM_INDEX		((t_edge*)(lem_in->temp->address))->next->id->index
# define INDEX_COPY				lem_in->index_copy
# define AUGMENT_PATHS			lem_in->aug_path_links
// # define PATH_OFFSET			((t_adlist *)((t_adlist *)QUE->address))
// # define PATH_ROUND				PATH_OFFSET->address
// # define PATH_LENGTH			PATH_OFFSET->next->address
// # define PATH_START				PATH_OFFSET->next->next	

// # define CURRENT_ANT			((t_ant *)QUE->address)

enum
{
	DEBUG_O = (1 << 0),
	ERROR_O = (1 << 2),
	ROOMS_O = (1 << 3),
	LINKS_O = (1 << 4),
	DFS_O = (1 << 5),
	USAGE_O = (1 << 6),
	PATHS_O = (1 << 7),
	AUGMENT_O = (1 << 8),
	COUNT_O = (1 << 9),
	BLANK_O = (1 << 10),
	START = (1 << 11),
	END = (1 << 12),
	LINK = (1 << 13),
	ROOM_LINE = (1 << 14)
}	e_flags;

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
	s_sec_char_hash_vi,
	s_find_hyphen_vi,
	s_isdigit_to_newline_vi,
	s_isdigit_to_space_vi,
	s_isallnum_to_hyphen_vi,
	s_isallnum_to_space_vi,
	s_isallnum_to_newline_vi,
	s_check_end_in_line_vi,
	s_check_start_in_line_vi,
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
	s_install_machine_dfs,
	s_sort_links_lists,
	s_start_path,
	s_find_next_room,
	s_backtrack_path,
	s_remove_room,
	s_delete_path,
	s_traverse_path,
	s_check_sink,
	s_store_path,
	s_print_tables_dfs,
	s_uninstall_machine_dfs,
}	e_state_dfs;

enum
{
	s_install_machine_bfs_st,
	s_init_bfs_st,
	s_que_list_remain_bfs_st,
	s_edge_list_remain_bfs_st,
	s_vertex_has_level_bfs_st,
	s_capacity_available_bfs_st,
	s_update_level_and_que_bfs_st,
	s_print_tables_bfs_st,
	s_uninstall_machine_bfs_st,
}	e_state_bfs_st;

enum
{
	s_install_machine_augp,
	s_init_augp,
	s_capacity_from_sink_augp,
	s_move_lower_level_augp,
	s_check_augment_path_augp,
	s_capacity_away_from_augment_augp,
	s_check_move_lower_level_augp,
	s_get_indexes_edges_augp,
	s_current_room_sink_augp,
	s_current_room_source_augp,
	s_clear_rooms_on_graph_augp,
	s_clear_links_on_graph_augp,
	s_print_tables_augp,
	s_uninstall_machine_augp,
}	e_state_augp;

enum
{
	s_install_machine_cg,
	s_set_global_vars,
	s_set_graph_vars,
	s_get_graph,
	s_delete_excess_paths,
	s_clean_pathslist,
	s_finish_graph_calculation,
	s_calculate_turn,
	s_update_stored_graph,
	s_print_tables_cg,
	s_uninstall_machine_cg,
}	e_state_cg;

enum
{
	s_install_machine_po,
	s_print_input,
	s_sort_paths,
	s_spawn_ants,
	s_move_all_ants,
	s_print_tables_po,
	s_uninstall_machine_po,
}	e_state_po;

enum
{
	s_install_machine_pt,
	s_print_rooms,
	s_print_links,
	s_print_paths,
	s_uninstall_machine_pt,
}	e_state_pt;

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
	size_t						loop;
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
t_bool							print_error(t_project *lem_in);
t_bool							print_output(t_project *lem_in);
t_bool							free_project(t_project *lem_in);
t_bool							read_stdin_vi(t_project *lem_in);

t_bool							first_char_newline_vi(t_project *lem_in);
t_bool							first_char_zero_vi(t_project *lem_in);
t_bool							first_char_delim_vi(t_project *lem_in);
t_bool							first_char_hash_vi(t_project *lem_in);
t_bool							sec_char_hash_vi(t_project *lem_in);
t_bool							isdigit_to_newline_vi(t_project *lem_in);
t_bool							isdigit_to_space_vi(t_project *lem_in);
t_bool							check_start_in_line_vi(t_project *lem_in);
t_bool							check_end_in_line_vi(t_project *lem_in);
t_bool							check_link_flag_on_vi(t_project *lem_in);
t_bool							switch_end_flag_on_vi(t_project *lem_in);
t_bool							switch_start_flag_on_vi(t_project *lem_in);
t_bool							isallnum_to_newline_vi(t_project *lem_in);
t_bool							isallnum_to_hyphen_vi(t_project *lem_in);
t_bool							find_hyphen_vi(t_project *lem_in);
t_bool							switch_link_flag_on_vi(t_project *lem_in);
t_bool							isallnum_to_space_vi(t_project *lem_in);
t_bool							print_error(t_project *lem_in);
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

char							*vertex_name(void *item);
t_vertex						*get_vertex(void);
void							*vertex_columns(t_hash_table *table);
void							free_vertex(void *content);
void							*get_edge(void);
void							*edge_columns(t_hash_table *table);
void							free_edge(void *content);
t_ant							*get_ant(size_t nbr);

t_bool							init_bfs(t_project *lem_in);
t_bool							que_list_remain_bfs(t_project *lem_in);
t_bool							edge_list_remain_bfs(t_project *lem_in);
t_bool							capacity_available_bfs(t_project *lem_in);
t_bool							vertex_has_level_bfs(t_project *lem_in);
t_bool							update_level_and_que_bfs(t_project *lem_in);

t_bool							init_bfs_st(t_project *lem_in);
t_bool							que_list_remain_bfs_st(t_project *lem_in);
t_bool							edge_list_remain_bfs_st(t_project *lem_in);
t_bool							capacity_available_bfs_st(t_project *lem_in);
t_bool							vertex_has_level_bfs_st(t_project *lem_in);
t_bool							update_level_and_que_bfs_st(t_project *lem_in);

t_bool							capacity_from_sink_augp(t_project *lem_in);
t_bool 							move_lower_level_augp(t_project *lem_in);
t_bool							capacity_away_from_augment_augp(t_project *lem_in);
t_bool							init_augp(t_project *lem_in);
t_bool							check_augment_path_augp(t_project *lem_in);
t_bool							get_indexes_edges_augp(t_project *lem_in);
t_bool							check_move_lower_level_augp(t_project *lem_in);
t_bool							current_room_sink_augp(t_project *lem_in);
t_bool							current_room_source_augp(t_project *lem_in);
t_bool							clear_rooms_on_graph_augp(t_project *lem_in);
t_bool							clear_links_on_graph_augp(t_project *lem_in);

t_bool							read_argument(t_project *lem_in);
t_bool							find_dash(t_project *lem_in);
t_bool							find_option(t_project *lem_in);
t_bool							validate_argument(t_project *lem_in);
t_bool							print_usage_message(t_project *lem_in);

t_bool							initialize_table_rms(t_project *lem_in);
t_bool							set_line_rms(t_project *lem_in);
t_bool							get_type(t_project *lem_in);
t_bool							store_room(t_project *lem_in);

t_bool							initialize_table_lks(t_project *lem_in);
t_bool							save_roomnames(t_project *lem_in);
t_bool							find_first_room(t_project *lem_in);
t_bool							find_second_room(t_project *lem_in);
t_bool							store_link(t_project *lem_in);
t_bool							add_room_to_link(t_project *lem_in);
t_bool							add_link_to_room(t_project *lem_in);
t_bool							swap_rooms(t_project *lem_in);
t_bool							set_line(t_project *lem_in);

t_bool							sort_links_lists(t_project *lem_in);
t_bool							start_path(t_project *lem_in);
t_bool							find_next_room(t_project *lem_in);
t_bool							backtrack_path(t_project *lem_in);
t_bool							delete_path(t_project *lem_in);
t_bool							remove_room(t_project *lem_in);
t_bool							traverse_path(t_project *lem_in);
t_bool							check_sink(t_project *lem_in);
t_bool							store_path(t_project *lem_in);

t_bool							print_input(t_project *lem_in);
t_bool							sort_paths(t_project *lem_in);
t_bool							spawn_ants(t_project *lem_in);
t_bool							move_all_ants(t_project *lem_in);

t_bool							set_global_vars(t_project *lem_in);
t_bool							set_graph_vars(t_project *lem_in);
t_bool							get_graph(t_project *lem_in);
t_bool							delete_excess_paths(t_project *lem_in);
t_bool							clean_pathslist(t_project *lem_in);
t_bool							finish_graph_calculation(t_project *lem_in);
t_bool							calculate_turn(t_project *lem_in);
t_bool							update_stored_graph(t_project *lem_in);

t_bool							print_rooms(t_project *lem_in);
t_bool							print_links(t_project *lem_in);
t_bool							print_paths(t_project *lem_in);




t_bool							print_tables(t_project *lem_in);
int								sort_by_level(void *a, void *b);
int								sort_by_length(void *a, void *b);


#endif
