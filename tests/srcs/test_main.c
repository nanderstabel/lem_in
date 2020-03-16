/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 16:50:26 by mgross         #+#    #+#                */
/*   Updated: 2020/03/12 15:56:44 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		main(void)
{
	t_project		*lem_in;
	int				fd;
	t_bool			boolean;
	char *temp;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/map1.map", O_RDONLY);
	set_options(lem_in);
	validate_input(lem_in);
	store_rooms(lem_in);
	store_links(lem_in);

	boolean = init_bfs(lem_in);
	que_list_remain_bfs(lem_in);
	temp = ((t_vertex *)(QUE->address))->id->name;
	ft_printf("string :%s len %d\n", ((t_vertex *)(QUE->address))->id->name, ft_strlen(((t_vertex *)(QUE->address))->id->name));
	// ((t_edge*)(TEMP_LINKS->address))->forward->level
	ft_printf("test: %d\n", ((t_edge*)(TEMP_LINKS->address))->forward->level);
	return (0);
}
