/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 16:50:26 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/06 21:12:22 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		main(void)
{
	t_project		*lem_in;
	// t_bool			boolean;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	close(0);
	open("../maps/valid_maps/map2.map", O_RDONLY);
	set_options(lem_in);
	validate_input(lem_in);
	store_rooms(lem_in);
	store_links(lem_in);
	label_graph(lem_in);
	find_paths(lem_in);

	// ft_printf("name  source: %s\n", SOURCE->id->name);
	// TEMP_LINKS = SOURCE->links;
	// TEMP_LINK_CAPACITY = 4;
	// ft_printf("name  source: %d\n", TEMP_LINK_CAPACITY);
	capacity_from_source_augp(lem_in);
	capacity_away_from_augment_augp(lem_in);
	// ft_printf("next_room_index %d\n", NEXT_ROOM_INDEX);
	// TEMP_LINKS = SINK->links;
	// CURRENT_ROOM = NEXT_ROOM;
	// ft_printf("next_room_index %d\n", NEXT_ROOM_INDEX);

	return (0);
}
