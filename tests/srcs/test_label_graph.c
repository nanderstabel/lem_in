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

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	close(0);
	open("../maps/valid_maps/map1.map", O_RDONLY);
	set_options(lem_in);
	validate_input(lem_in);
	store_rooms(lem_in);
	store_links(lem_in);

	init_bfs(lem_in);
	cr_assert_str_eq(((t_vertex *)(TEMP_QUE->address))->id->name,"0", "The result was %s, expected %s\n", ((t_vertex *)(TEMP_QUE->address))->id->name, "0");
	free(lem_in);
	lem_in = NULL;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	close(0);
	open("../maps/valid_maps/flow_ten.map", O_RDONLY);
	set_options(lem_in);
	validate_input(lem_in);
	store_rooms(lem_in);
	store_links(lem_in);

	init_bfs(lem_in);
	cr_assert_str_eq(((t_vertex *)(TEMP_QUE->address))->id->name,"Fog1", "The result was %s, expected %s\n", ((t_vertex *)(TEMP_QUE->address))->id->name, "Fog1");
}

Test(test_label_graph, que_list_remain_bfs_test)
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
	init_bfs(lem_in);

	boolean = que_list_remain_bfs(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	cr_assert_str_eq(CURRENT_ROOM->id->name, VERTEX_IN_LIST->id->name, "The result was %s, expected %s\n", CURRENT_ROOM->id->name, VERTEX_IN_LIST->id->name);

	TEMP_QUE = NULL;
	// ft_printf("Pointer 1 = %p", QUE);
	boolean = que_list_remain_bfs(lem_in);
	// ft_printf("Pointer 2 = %p", QUE);
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);
	cr_assert(QUE == NULL);
}

Test(test_label_graph, edge_list_remain_bfs_test)
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
	init_bfs(lem_in);
	que_list_remain_bfs(lem_in);

	boolean = edge_list_remain_bfs(lem_in);
	cr_assert(boolean == SUCCESS,  "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("Pointer 1 = %p\n", TEMP_  QUE);
	
	TEMP_LINKS = NULL;
	boolean = edge_list_remain_bfs(lem_in);
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("Pointer 2 = %p\n", TEMP_QUE);

}

Test(test_label_graph, capacity_available_bfs_test)
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
	init_bfs(lem_in);
	que_list_remain_bfs(lem_in);
	edge_list_remain_bfs(lem_in);

	boolean = capacity_available_bfs(lem_in);
	cr_assert(boolean == SUCCESS,  "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("Pointer 1 = %p\n", TEMP_LINKS);
	
	TEMP_LINK_CAPACITY = 0;
	boolean = capacity_available_bfs(lem_in);
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("Pointer 1 = %p\n", TEMP_LINKS);
}

Test(test_label_graph, vertex_has_level_bfs_test)
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
	init_bfs(lem_in);
	que_list_remain_bfs(lem_in);
	edge_list_remain_bfs(lem_in);
	capacity_available_bfs(lem_in);

	boolean = vertex_has_level_bfs(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ------------------- Hier is nog niet de fail getest ---------------
}

Test(test_label_graph, update_level_and_que_bfs_test)
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
	init_bfs(lem_in);
	que_list_remain_bfs(lem_in);
	edge_list_remain_bfs(lem_in);
	capacity_available_bfs(lem_in);
	vertex_has_level_bfs(lem_in);

	boolean = update_level_and_que_bfs(lem_in);
	cr_assert(boolean == SUCCESS);
}

