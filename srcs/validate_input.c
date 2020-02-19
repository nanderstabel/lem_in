/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:54:14 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/19 11:19:56 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								check_num_ants(char *line_to_check)
{
	if (line_to_check == NULL || *line_to_check == '\0' \
	|| *line_to_check == '0')
		return (FAIL);
	while (*line_to_check)
	{
		if (ft_isdigit(*line_to_check) != 1)
			return (FAIL);
		line_to_check++;
	}
	return (SUCCESS);
}

t_bool								check_sink(char *line_to_check)
{
	if (line_to_check == NULL)
		return (FAIL);
	if (ft_strcmp(line_to_check, "##end") == 0)
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								check_source(char *line_to_check)
{
	if (line_to_check == NULL)
		return (FAIL);
	if (ft_strcmp(line_to_check, "##start") == 0)
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								validate_input(void *project)
{
	// int index = 1;
	t_project *test;
	// int fd;

	test = (t_project*)project;

	// ft_printf("%i\n", test->argc);
	char buf[BUFF_SIZE + 1];
	int ret = 0;
	// ret = read(STDIN_FILENO, buf, BUFF_SIZE);
	buf[ret] = '\0'; 

	ft_printf("%s", buf);
	// lem_in = NULL;
	ft_printf("Currently: %s\n", __func__);

	// while (index < test->argc)
	// {
	// 	ft_printf("input string line [%i]: %s\n", index, test->argv[index]);
	// 	index++;

	// }
	return (SUCCESS);
}
