/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_label_graph.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 17:27:26 by mgross         #+#    #+#                */
/*   Updated: 2020/03/10 17:31:35 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"


Test(test_label_graph, init_bfs_test)
{
	t_project		*lem_in;
	int				fd;
	t_bool			boolean;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/map1.map", O_RDONLY);
	set_options(lem_in);
	validate_input(lem_in);
	store_rooms(lem_in);
	store_links(lem_in);

	boolean = init_bfs(lem_in);
	cr_assert_str_eq(((t_vertex *)(QUE->address))->id->name,"0", "The result was %s, expected %s\n", ((t_vertex *)(QUE->address))->id->name, "0");
	free(lem_in);
	lem_in = NULL;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/flow_ten.map", O_RDONLY);
	set_options(lem_in);
	validate_input(lem_in);
	store_rooms(lem_in);
	store_links(lem_in);

	boolean = init_bfs(lem_in);
	cr_assert_str_eq(((t_vertex *)(QUE->address))->id->name,"Fog1", "The result was %s, expected %s\n", ((t_vertex *)(QUE->address))->id->name, "Fog1");
}

Test(test_label_graph, que_list_remain_bfs_test)
{
	t_project		*lem_in;
	int				fd;
	t_bool			boolean;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/map1.map", O_RDONLY);
	set_options(lem_in);
	validate_input(lem_in);
	store_rooms(lem_in);
	store_links(lem_in);
	init_bfs(lem_in);

	boolean = que_list_remain_bfs(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	cr_assert_str_eq(CURRENT_ROOM->id->name, VERTEX_IN_LIST->id->name, "The result was %s, expected %s\n", CURRENT_ROOM->id->name, VERTEX_IN_LIST->id->name);
}