/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_read_input.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:35:29 by mgross         #+#    #+#                */
/*   Updated: 2020/02/29 12:44:03 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(test_read_stdin_vi, read_input)
{
	int		fd;
	int		ret;
	t_project	*lem_in;

	lem_in = (t_project*)ft_memalloc(sizeof(t_project));

	close(0);
	fd = open("../../maps/valid_maps/map1.map", O_RDONLY);
	cr_assert(fd == -1, "The result was %d, expected %d\n", fd, -1);

	ret = read_stdin_vi(lem_in);
	cr_assert(ret == FAIL, "The result was %d, expected %d\n", ret, FAIL);

	// cr_assert(fd == 0, "The result was %d, expected %d\n", fd, 0);
	close(0);
	fd = open("../maps/valid_maps/map1.map", O_RDONLY);
	ret = read_stdin_vi(lem_in);
	cr_assert(ret == SUCCESS, "The result was %d, expected %d\n", ret, SUCCESS);
	
	close(0);
	fd = open("../maps/valid_maps/map_big_sup.map", O_RDONLY);
	ret = read_stdin_vi(lem_in);
	cr_assert(ret == SUCCESS, "The result was %d, expected %d\n", ret, SUCCESS);

	close(0);
	fd = open("../maps/invalid_maps/map_empty.map", O_RDONLY);
	ret = read_stdin_vi(lem_in);
	cr_assert(ret == SUCCESS, "The result was %d, expected %d\n", ret, SUCCESS);
	
}