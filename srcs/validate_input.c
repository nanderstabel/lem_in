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

/*
** The function takes as argument a charakter string.
**
** The function checks if the first line of the input, the line for the num of
** ants, is a valid line. It is a valid line if there are only digits and the
** number is not 0.
**
** Return values are FAIL or SUCCESS depending if only digits are found (no 0)
** or other charakters are mixed into the string.
*/

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

/*
** The function takes as argument a charakter string.
**
** The function checks if the line send is the charakter strin ##end.
**
** Return values are FAIL and SUCCESS depending if the string was found.
*/

t_bool								check_sink(char *line_to_check)
{
	if (line_to_check == NULL)
		return (FAIL);
	if (ft_strcmp(line_to_check, "##end") == 0)
		return (SUCCESS);
	else
		return (FAIL);
}

/*
** The function takes as argument a charakter string.
**
** The function checks if the line send is the charakter strin ##start.
**
** Return values are FAIL and SUCCESS depending if the string was found.
*/

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
	t_project *test;

	test = (t_project*)project;

	ft_printf("Currently: %s\n", __func__);
	read_stdin(&test->input_string);

	return (SUCCESS);
}
