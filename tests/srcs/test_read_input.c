/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_read_input.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:35:29 by mgross         #+#    #+#                */
/*   Updated: 2020/02/19 17:35:31 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(test_read_stdin, read)
{
	char *string;
	int		fd;
	int		ret;


	close(0);
	fd = open("../../maps/valid_maps/map1.map", O_RDONLY);
	cr_assert(fd == -1, "The result was %d, expected %d\n", fd, -1);

	ret = read_stdin(&string);
	cr_assert(ret == FAIL, "The result was %d, expected %d\n", ret, FAIL);

	fd = open("../maps/valid_maps/map1.map", O_RDONLY);
	cr_assert(fd == 0, "The result was %d, expected %d\n", fd, 0);

	ret = read_stdin(&string);
	cr_assert(ret == SUCCESS, "The result was %d, expected %d\n", ret, SUCCESS);

}