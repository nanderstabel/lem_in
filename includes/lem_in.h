/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:05:13 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/12 13:49:35 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef enum
{
	idle,
	install_machine,
	receive_input,
	validate_input,
	print_output,
	uninstall_machine,
}	t_state;

typedef int						(*t_event)(void *);

typedef struct					s_machine
{
	t_state						state;
	t_state						**transition;
	t_event						*event;
}								t_machine;

int								receiving_input(void *pointer);
int								validating_input(void *pointer);
// int								storing_rooms(void *pointer);
// int								storing_links(void *pointer);
// int								doing_bfs(void *pointer);
// int								doing_dfs(void *pointer);
// int								augmenting_paths(void *pointer);
// int								moving_ants(void *pointer);
// int								formatting_output(void *pointer);
int								printing_output(void *pointer);
int								uninstalling_machine(void *pointer);
int								ending_program(void *pointer);
int		hello2(int num);
char	*hello(void);
#endif
