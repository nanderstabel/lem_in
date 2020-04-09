/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 16:50:26 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/08 17:59:18 by zitzak        ########   odam.nl         */
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
	label_graph_s_to_t(lem_in);
	augmenting_paths(lem_in);


	return (0);
}
