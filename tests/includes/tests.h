/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 09:43:44 by mgross        #+#    #+#                 */
/*   Updated: 2020/06/09 14:33:41 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H

# define TESTS_H

# include <criterion/criterion.h>
# include <stdio.h>
# include "lem_in.h"

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

// # define ERROR_MSG				RED "An error occurred, machine was not able to: \n"
# define ERROR					lem_in->error
# define ERROR_LOG(x)			error_log(lem_in, ft_strjoin("\t- ", __func__), x)

# define QUE					lem_in->que_list
# define TEMP_QUE				lem_in->temp_que_list
# define VERTEX_IN_LIST			((t_vertex *)(lem_in->temp_que_list->address))
# define TEMP_LINKS				lem_in->temp
# define NEXT_ROOM				((t_edge*)(TEMP_LINKS->address))->next
# define NEXT_ROOM_LEVEL		((t_edge*)(TEMP_LINKS->address))->next->level
# define TEMP_LINK_CAPACITY		((t_edge*)(TEMP_LINKS->address))->capacity

// # define PATH_OFFSET			((t_adlist *)((t_adlist *)QUE->address))
// # define PATH_ROUND				PATH_OFFSET->address
// # define PATH_LENGTH			PATH_OFFSET->next->address
// # define PATH_START				PATH_OFFSET->next->next	

#endif
