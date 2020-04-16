/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_augmenting_paths.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: zitzak <zitzak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 15:24:24 by zitzak        #+#    #+#                 */
/*   Updated: 2020/04/16 16:28:25 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(augmenting_paths_suite, capacity_from_sink_augp_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	close(0);
	open("../maps/valid_maps/map1.map", O_RDONLY);
	set_options(lem_in);
	validate_input(lem_in);
	store_rooms(lem_in);
	store_links(lem_in);
	label_graph(lem_in);
	find_paths(lem_in);

	boolean = capacity_from_sink_augp(lem_in);
	cr_assert(boolean == FAIL, "boolean  = %d",  boolean);
	free(lem_in);
	lem_in = NULL;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	close(0);
	open("../maps/valid_maps/map2.map", O_RDONLY);
	set_options(lem_in);
	validate_input(lem_in);
	store_rooms(lem_in);
	store_links(lem_in);
	label_graph(lem_in);
	find_paths(lem_in);

	boolean = capacity_from_sink_augp(lem_in);
	cr_assert(boolean == SUCCESS, "boolean  = %d",  boolean);

}