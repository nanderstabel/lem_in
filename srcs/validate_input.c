/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:54:14 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/10 13:39:35 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								first_char_newline_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*INPUT_CPY == '\n')
		return (ERROR_LOG(SUCCESS));
	else
		return (FAIL);
}

t_bool								first_char_zero_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*INPUT_CPY == '0')
		return (ERROR_LOG(SUCCESS));
	else
		return (FAIL);
}

t_bool								next_line_room_hash_vi(t_project *lem_in)
{
	if ((FLAGS & ROOM_LINE) == ROOM_LINE)
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

t_bool								next_line_room_link_vi(t_project *lem_in)
{
	if ((FLAGS & ROOM_LINE) == ROOM_LINE)
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

t_bool								first_char_delim_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*INPUT_CPY == '\0')
		return (ERROR_LOG(SUCCESS));
	else
		return (FAIL);
}

t_bool								first_char_hash_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*INPUT_CPY == '#')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								second_char_hash_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*(INPUT_CPY + 1) == '#')
		return (SUCCESS);
	else
	{
		while (*INPUT_CPY != '\n' && *INPUT_CPY != '\0')
			INPUT_CPY++;
		if (*INPUT_CPY == '\n')
			INPUT_CPY++;
		return (FAIL);
	}
}

t_bool								isdigit_to_space_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*INPUT_CPY != ' ')
	{
		if (ft_isdigit(*INPUT_CPY) != 1)
			return (ERROR_LOG(FAIL));
		INPUT_CPY++;
	}
	INPUT_CPY++;
	return (SUCCESS);
}

t_bool								isdigit_to_newline_vi(t_project *lem_in)
{
	char		*temp;

	temp = INPUT_CPY;
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*INPUT_CPY != '\n')
	{
		if (ft_isdigit(*INPUT_CPY) != 1)
			return (ERROR_LOG(FAIL));
		INPUT_CPY++;
	}
	if (NANTS == 0)
		NANTS = ft_atoi(temp);
	if ((FLAGS & ROOM_LINE) == ROOM_LINE)
		FLAGS ^= ROOM_LINE;
	INPUT_CPY++;
	return (SUCCESS);
}

t_bool								check_link_flag_on_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((FLAGS & LINK) == LINK)
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								isallnum_to_hyphen_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*INPUT_CPY != '-')
	{
		if (ft_isprint((int)*INPUT_CPY) != 1)
			return (ERROR_LOG(FAIL));
		INPUT_CPY++;
	}
	NLINKS++;
	INPUT_CPY++;
	return (SUCCESS);
}

t_bool								isallnum_to_newline_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*INPUT_CPY == 'L')
		return (ERROR_LOG(FAIL));
	while (*INPUT_CPY != '\n')
	{
		if (ft_isprint((int)*INPUT_CPY) != 1)
		{
			if (*INPUT_CPY == '\0')
				return (SUCCESS);
			else
				return (ERROR_LOG(FAIL));
		}
		if (*INPUT_CPY == '-')
			return (ERROR_LOG(FAIL));
		INPUT_CPY++;
	}
	INPUT_CPY++;
	return (SUCCESS);
}

t_bool								isallnum_to_space_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*INPUT_CPY != ' ')
	{
		if (ft_isprint((int)*INPUT_CPY) != 1)
			return (ERROR_LOG(FAIL));
		if (*INPUT_CPY == '-')
			return (ERROR_LOG(FAIL));
		INPUT_CPY++;
	}
	NROOMS++;
	INPUT_CPY++;
	return (SUCCESS);
}

t_bool								check_if_start_command_line_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_strcmp_delim(INPUT_CPY, "##start\n", (int)'\n') == 0)
	{
		while (*INPUT_CPY != '\n' && *INPUT_CPY != '\0')
			INPUT_CPY++;
		if (*INPUT_CPY == '\n')
			INPUT_CPY++;
		return (SUCCESS);
	}
	else
		return (FAIL);
}

t_bool								check_if_end_command_line_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_strcmp_delim(INPUT_CPY, "##end\n", (int)'\n') == 0)
	{
		while (*INPUT_CPY != '\n' && *INPUT_CPY != '\0')
			INPUT_CPY++;
		if (*INPUT_CPY == '\n')
			INPUT_CPY++;
		return (SUCCESS);
	}
	else
		return (FAIL);
}

t_bool								skip_command_line_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*INPUT_CPY != '\n' && *INPUT_CPY != '\0')
		INPUT_CPY++;
	if (*INPUT_CPY == '\n')
		INPUT_CPY++;
	return (SUCCESS);
}

t_bool								switch_start_flag_on_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((FLAGS & START) == START)
		return (ERROR_LOG(FAIL));
	else
	{
		FLAGS |= START;
		FLAGS |= ROOM_LINE;
	}
		return (SUCCESS);
}

t_bool								switch_end_flag_on_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((FLAGS & END) == END)
		return (ERROR_LOG(FAIL));
	else
	{
		FLAGS |= END;
		FLAGS |= ROOM_LINE;
	}
		return (SUCCESS);
}

t_bool								switch_link_flag_on_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((FLAGS & LINK) == LINK)
		return (FAIL);
	else
		FLAGS |= LINK;
		return (SUCCESS);
}

t_bool								find_hyphen_vi(t_project *lem_in)
{
	int		index;

	index = 0;
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (INPUT_CPY[index] != '\n' && INPUT_CPY[index] != '\0')
	{
		if (INPUT_CPY[index] == '-')
		{
			FLAGS |= LINK;
			return (SUCCESS);
		}
		index++;
	}
	return (FAIL);
}

t_bool		input_file_done_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*INPUT_CPY == '\0')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								all_flags_on_vi(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((FLAGS & START) == START && (FLAGS & END) == END && \
		(FLAGS & LINK) == LINK)
		return (SUCCESS);
	else
		return (ERROR_LOG(FAIL));
}

t_bool		read_stdin_vi(t_project *lem_in)
{
	char			*temp;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*new;

	ret = 1;
	new = ft_strnew(0);
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (ret != 0)
	{
		ret = read(0, buf, BUFF_SIZE);
		if (ret == -1)
			return (ERROR_LOG(FAIL));
		buf[ret] = '\0';
		temp = new;
		new = ft_strjoin(new, buf);
		free(temp);
	}
	lem_in->input_string = new;
	INPUT_CPY = lem_in->input_string;
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_install_machine][SUCCESS] = s_read_stdin_vi;
	TRANSITIONS[s_read_stdin_vi][FAIL] = s_uninstall_machine_vi; 
	TRANSITIONS[s_read_stdin_vi][SUCCESS] = s_first_char_delim_vi;
	TRANSITIONS[s_first_char_delim_vi][SUCCESS] = s_uninstall_machine_vi;
	TRANSITIONS[s_first_char_delim_vi][FAIL] = s_first_char_newline_vi;
	TRANSITIONS[s_first_char_newline_vi][SUCCESS] = s_uninstall_machine_vi;
	TRANSITIONS[s_first_char_newline_vi][FAIL] = s_first_char_zero_vi;
	TRANSITIONS[s_first_char_zero_vi][SUCCESS] = s_uninstall_machine_vi;
	TRANSITIONS[s_first_char_zero_vi][FAIL] = s_isdigit_to_newline_vi;
	TRANSITIONS[s_isdigit_to_newline_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_isdigit_to_newline_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_input_file_done_vi][FAIL] = s_first_char_hash_vi;
	TRANSITIONS[s_input_file_done_vi][SUCCESS] = s_all_flags_on_vi;
	TRANSITIONS[s_all_flags_on_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_all_flags_on_vi][SUCCESS] = s_uninstall_machine_vi;
	TRANSITIONS[s_first_char_hash_vi][FAIL] = s_check_link_flag_on_vi;
	TRANSITIONS[s_first_char_hash_vi][SUCCESS] = s_next_line_room_hash_vi;
	TRANSITIONS[s_next_line_room_hash_vi][FAIL] = s_uninstall_machine_vi; 
	TRANSITIONS[s_next_line_room_hash_vi][SUCCESS] = s_second_char_hash_vi;
	TRANSITIONS[s_second_char_hash_vi][FAIL] = s_input_file_done_vi;
	TRANSITIONS[s_second_char_hash_vi][SUCCESS] = s_check_if_start_command_line_vi; 
	TRANSITIONS[s_check_if_start_command_line_vi][FAIL] = s_check_if_end_command_line_vi;
	TRANSITIONS[s_check_if_start_command_line_vi][SUCCESS] = s_switch_start_flag_on_vi;
	TRANSITIONS[s_switch_start_flag_on_vi][FAIL] = s_uninstall_machine_vi; 
	TRANSITIONS[s_switch_start_flag_on_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_check_if_end_command_line_vi][SUCCESS] = s_switch_end_flag_on_vi;
	TRANSITIONS[s_check_if_end_command_line_vi][FAIL] = s_skip_command_line_vi;
	TRANSITIONS[s_switch_end_flag_on_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_switch_end_flag_on_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_skip_command_line_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_skip_command_line_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_check_link_flag_on_vi][SUCCESS] = s_next_line_room_link_vi;
	TRANSITIONS[s_next_line_room_link_vi][SUCCESS] = s_isallnum_to_hyphen_vi;
	TRANSITIONS[s_next_line_room_link_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_check_link_flag_on_vi][FAIL] = s_find_hyphen_vi;
	TRANSITIONS[s_isallnum_to_hyphen_vi][SUCCESS] = s_isallnum_to_newline_vi;
	TRANSITIONS[s_isallnum_to_hyphen_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_isallnum_to_newline_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_isallnum_to_newline_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_find_hyphen_vi][SUCCESS] = s_isallnum_to_hyphen_vi;
	TRANSITIONS[s_find_hyphen_vi][FAIL] = s_isallnum_to_space_vi;
	TRANSITIONS[s_isallnum_to_space_vi][SUCCESS] = s_isdigit_to_space_vi;
	TRANSITIONS[s_isallnum_to_space_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_isdigit_to_space_vi][SUCCESS] = s_isdigit_to_newline_vi;
	TRANSITIONS[s_isdigit_to_space_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_isdigit_to_newline_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_isdigit_to_newline_vi][FAIL] = s_uninstall_machine_vi;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine] = NULL;
	EVENTS[s_read_stdin_vi] = read_stdin_vi;
	EVENTS[s_first_char_newline_vi] = first_char_newline_vi;
	EVENTS[s_first_char_zero_vi] = first_char_zero_vi;
	EVENTS[s_first_char_delim_vi] = first_char_delim_vi;
	EVENTS[s_first_char_hash_vi] = first_char_hash_vi;
	EVENTS[s_second_char_hash_vi] = second_char_hash_vi;
	EVENTS[s_find_hyphen_vi] = find_hyphen_vi;
	EVENTS[s_next_line_room_hash_vi] = next_line_room_hash_vi;
	EVENTS[s_next_line_room_link_vi] = next_line_room_link_vi;
	EVENTS[s_isdigit_to_newline_vi] = isdigit_to_newline_vi;
	EVENTS[s_isdigit_to_space_vi] = isdigit_to_space_vi;
	EVENTS[s_isallnum_to_hyphen_vi] = isallnum_to_hyphen_vi;
	EVENTS[s_isallnum_to_space_vi] = isallnum_to_space_vi;
	EVENTS[s_isallnum_to_newline_vi] = isallnum_to_newline_vi;
	EVENTS[s_check_if_end_command_line_vi] = check_if_end_command_line_vi;
	EVENTS[s_check_if_start_command_line_vi] = check_if_start_command_line_vi;
	EVENTS[s_switch_start_flag_on_vi] = switch_start_flag_on_vi;
	EVENTS[s_switch_end_flag_on_vi] = switch_end_flag_on_vi;
	EVENTS[s_switch_link_flag_on_vi] = switch_link_flag_on_vi;
	EVENTS[s_skip_command_line_vi] = skip_command_line_vi;
	EVENTS[s_check_link_flag_on_vi] = check_link_flag_on_vi;
	EVENTS[s_all_flags_on_vi] = all_flags_on_vi;
	EVENTS[s_input_file_done_vi] = input_file_done_vi;
}

/*
** Returns the configurated mconfig struct. Important to note here is that
** the size you give to malloc_mconfig sould be the state with the highest
** value.
*/

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_vi);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								validate_input(t_project *lem_in)
{
	t_machine		*machine;

	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (ERROR)
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}
