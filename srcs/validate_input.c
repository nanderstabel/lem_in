/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:54:14 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/23 20:46:25 by nstabel       ########   odam.nl         */
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

// t_bool								check_line_ants(char *line_to_check)
// {
// 	if (*line_to_check == '\n' || *line_to_check == '0')
// 		return (FAIL);
// 	if (!isdigit_to_char(&line_to_check, (int)'\n'))
// 		return (FAIL);
// 	else
// 		return (SUCCESS);
// }

// t_bool								isdigit_to_char(char **line_to_check, int c)
// {
// 	while (**line_to_check != (char)c)
// 	{
// 		if (ft_isdigit(**line_to_check) != 1)
// 			return (FAIL);
// 		(*line_to_check)++;
// 	}
// 	return (SUCCESS);
// }

t_bool								isallnum_to_char(char **line_to_check, int c)
{
	while (**line_to_check != (char)c)
	{
		if (ft_isalnum(**line_to_check) != 1)
			return (FAIL);
		(*line_to_check)++;
	}
	return (SUCCESS);
}

/*
** The function takes as argument a charakter string.
**
** The function checks if the line send is the charakter string ##end.
**
** Return values are FAIL and SUCCESS depending if the string was found.
*/

t_bool								check_link_sink_command(char *line_to_check)
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
** The function checks if the line send is the charakter string ##start.
**
** Return values are FAIL and SUCCESS depending if the string was found.
*/

t_bool								check_link_source_command(char *line_to_check)
{
	if (line_to_check == NULL)
		return (FAIL);
	if (ft_strcmp(line_to_check, "##start") == 0)
		return (SUCCESS);
	else
		return (FAIL);
}

// t_bool								check_line_rooms(char *line_to_check)
// {
// 	if(!isallnum_to_char(&line_to_check, ' '))
// 		return (FAIL);
// 	line_to_check++;
// 	if(!isdigit_to_char(&line_to_check, ' '))
// 		return (FAIL);
// 	line_to_check++;
// 	if(!isdigit_to_char(&line_to_check, '\n'))
// 		return (FAIL);
// 	return (SUCCESS);
// }

// t_bool							transition_state(char *line_to_read)
// {
	
// }

// t_bool							point_line(void *project)
// {
// 	t_project	*lem_in;

// 	lem_in = (t_project*)project;
// }
// t_bool								check_rooms4(char *line_to_check)
// {
// 	int			len;
// 	int			index;
// 	char		*

// 	len = ft_strlen(line_to_check);
// 	index = 0;
// 	while (*line_to_check != ' ' && *line_to_check != '\n' && *line_to_check != '\0')
// 	{
// 		if (ft_isalnum(*line_to_check) != 1)
// 			return (FAIL);
// 	}
// 	if ()
// }


// static void			get_transitions(t_mconfig **mconfig)
// {
// 	TRANSITION[s_install_machine_vi][FAIL] = s_idle;
// 	TRANSITION[s_install_machine_vi][SUCCESS] = s_check_line_ants_vi;
// 	TRANSITION[s_check_line_ants_vi][FAIL] = s_find_error; // Is het handig hier de zelfde error te pakken?
// 	TRANSITION[s_check_line_ants_vi][SUCCESS] = s_point_line_vi;
// 	TRANSITION[s_point_line_vi][FAIL] = s_point_line_vi;
// 	TRANSITION[s_point_line_vi][SUCCESS] = s_point_line_vi;
// }

t_bool								validate_input(void *project)
{
	t_project *test;

	test = (t_project*)project;

	ft_printf("Currently: %s\n", __func__);
	read_stdin(&test->input_string);

	return (SUCCESS);
}
