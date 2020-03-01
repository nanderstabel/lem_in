/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 16:50:26 by mgross         #+#    #+#                */
/*   Updated: 2020/02/29 16:41:18 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		main(void)
{
	int				fd;
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/map1.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	NANTS = 0;
	NLINKS = 0;
	NROOMS = 0;
	INPUT_CPY = NULL;
	lem_in->input_string = NULL;
	boolean = validate_input(lem_in);
	// cr_assert(NANTS == 3, "The result was %zu, expected %d\n", NANTS, 3);
	// cr_assert(NROOMS == 4, "The result was %zu, expected %d\n", NROOMS, 4);
	// cr_assert(NLINKS == 3, "The result was %zu, expected %d\n", NLINKS, 3);

	close(0);
	fd = open("../maps/valid_maps/map2.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	NANTS = 0;
	NLINKS = 0;
	NROOMS = 0;
	INPUT_CPY = NULL;
	lem_in->input_string = NULL;
	boolean = validate_input(lem_in);
	// cr_assert(NANTS == 4, "The result was %zu, expected %d\n", NANTS, 4);
	// cr_assert(NROOMS == 8, "The result was %zu, expected %d\n", NROOMS, 8);
	// cr_assert(NLINKS == 9, "The result was %zu, expected %d\n", NLINKS, 9);
	
	close(0);
	fd = open("../maps/valid_maps/map3.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	NANTS = 0;
	NLINKS = 0;
	NROOMS = 0;
	INPUT_CPY = NULL;
	lem_in->input_string = NULL;
	boolean = validate_input(lem_in);
	// cr_assert(NANTS == 4, "The result was %zu, expected %d\n", NANTS, 4);
	// cr_assert(NROOMS == 8, "The result was %zu, expected %d\n", NROOMS, 8);
	// cr_assert(NLINKS == 9, "The result was %zu, expected %d\n", NLINKS, 9);
}
