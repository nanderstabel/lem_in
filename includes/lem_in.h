/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/07 13:34:58 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef enum
{
	install_machine = -1,
	receive_input,
	validate_input,
	store_rooms,
	store_links,
	do_bfs,
	do_dfs,
	augment_paths,
	move_ants,
	format_output,
	print_output,
	uninstall_machine,
	end_program
}	t_transition;

typedef enum
{
	idle,
	machine_installed,
	input_received,
	validated_input,
	stored_rooms,
	stored_links,
	finished_flow,
	finished_bfs,
	finished_dfs,
	finished_augmentation,
	moved_ants,
	printed_output,
}	t_state;

typedef t_transition			(*t_event)(void *);

typedef struct					s_machine
{
	t_state						state;
	t_transition				event;
	t_event						*event;
	t_list						*output;
}								t_machine;

t_transition					receiving_input(void *pointer);
t_transition					validating_input(void *pointer);
t_transition					storing_rooms(void *pointer);
t_transition					storing_links(void *pointer);
t_transition					doing_bfs(void *pointer);
t_transition					doing_dfs(void *pointer);
t_transition					augmenting_paths(void *pointer);
t_transition					moving_ants(void *pointer);
t_transition					formatting_output(void *pointer);
t_transition					printing_output(void *pointer);
t_transition					uninstalling_machine(void *pointer);
t_transition					ending_program(void *pointer);

#endif
