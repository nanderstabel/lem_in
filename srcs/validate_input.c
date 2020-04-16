/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:54:14 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/15 15:42:23 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool						first_char_newline_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '\n')
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), SUCCESS));
	else
		return (FAIL);
}

t_bool						first_char_zero_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '0')
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), SUCCESS));
	else
		return (FAIL);
}

t_bool						next_line_room_hash_vi(t_project *lem_in)
{
	if (lem_in->flags & ROOM_LINE)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

t_bool						next_line_room_link_vi(t_project *lem_in)
{
	if (lem_in->flags & ROOM_LINE)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}

t_bool						first_char_delim_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '\0')
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), SUCCESS));
	else
		return (FAIL);
}

t_bool						first_char_hash_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '#')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool						sec_char_hash_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '\0')
		return (FAIL);
	if (*(lem_in->input_string_copy + 1) == '#')
		return (SUCCESS);
	else
	{
		while (*lem_in->input_string_copy != '\n'\
		&& *lem_in->input_string_copy != '\0')
			lem_in->input_string_copy++;
		if (*lem_in->input_string_copy == '\n')
			lem_in->input_string_copy++;
		return (FAIL);
	}
}

t_bool						isdigit_to_space_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != ' ')
	{
		if (ft_isdigit(*lem_in->input_string_copy) != 1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	lem_in->input_string_copy++;
	return (SUCCESS);
}

t_bool						isdigit_to_newline_vi(t_project *lem_in)
{
	char		*temp;

	temp = lem_in->input_string_copy;
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != '\n')
	{
		if (ft_isdigit(*lem_in->input_string_copy) != 1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	if (lem_in->nants == 0)
		lem_in->nants = ft_atoi(temp);
	if (lem_in->flags & ROOM_LINE)
		lem_in->flags ^= ROOM_LINE;
	lem_in->input_string_copy++;
	return (SUCCESS);
}

t_bool						check_link_flag_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & LINK)
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool						isallnum_to_hyphen_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != '-')
	{
		if (ft_isprint((int)*lem_in->input_string_copy) != 1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	NLINKS++;
	lem_in->input_string_copy++;
	return (SUCCESS);
}

t_bool						isallnum_to_newline_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == 'L')
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	while (*lem_in->input_string_copy != '\n')
	{
		if (ft_isprint((int)*lem_in->input_string_copy) != 1)
		{
			if (*lem_in->input_string_copy == '\0')
				return (SUCCESS);
			else
				return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		}
		if (*lem_in->input_string_copy == '-')
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	lem_in->input_string_copy++;
	return (SUCCESS);
}

t_bool						isallnum_to_space_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != ' ')
	{
		if (ft_isprint((int)*lem_in->input_string_copy) != 1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		if (*lem_in->input_string_copy == '-')
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		lem_in->input_string_copy++;
	}
	NROOMS++;
	lem_in->input_string_copy++;
	return (SUCCESS);
}

t_bool						check_start_in_line_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_strcmp_delim(lem_in->input_string_copy, "##start\n", (int)'\n') == 0)
	{
		while (*lem_in->input_string_copy != '\n'\
		&& *lem_in->input_string_copy != '\0')
			lem_in->input_string_copy++;
		if (*lem_in->input_string_copy == '\n')
			lem_in->input_string_copy++;
		return (SUCCESS);
	}
	else
		return (FAIL);
}

t_bool						check_end_in_line_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_strcmp_delim(lem_in->input_string_copy, "##end\n", (int)'\n') == 0)
	{
		while (*lem_in->input_string_copy != '\n'\
		&& *lem_in->input_string_copy != '\0')
			lem_in->input_string_copy++;
		if (*lem_in->input_string_copy == '\n')
			lem_in->input_string_copy++;
		return (SUCCESS);
	}
	else
		return (FAIL);
}

t_bool						skip_command_line_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (*lem_in->input_string_copy != '\n'\
	&& *lem_in->input_string_copy != '\0')
		lem_in->input_string_copy++;
	if (*lem_in->input_string_copy == '\n')
		lem_in->input_string_copy++;
	return (SUCCESS);
}

t_bool						switch_start_flag_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & START)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	else
	{
		lem_in->flags |= START;
		lem_in->flags |= ROOM_LINE;
	}
	return (SUCCESS);
}

t_bool						switch_end_flag_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & END)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	else
	{
		lem_in->flags |= END;
		lem_in->flags |= ROOM_LINE;
	}
	return (SUCCESS);
}

t_bool						switch_link_flag_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & LINK)
		return (FAIL);
	else
		lem_in->flags |= LINK;
	return (SUCCESS);
}

t_bool						find_hyphen_vi(t_project *lem_in)
{
	int		index;

	index = 0;
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (lem_in->input_string_copy[index] != '\n'\
	&& lem_in->input_string_copy[index] != '\0')
	{
		if (lem_in->input_string_copy[index] == '-')
		{
			lem_in->flags |= LINK;
			return (SUCCESS);
		}
		index++;
	}
	return (FAIL);
}

t_bool						input_file_done_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (*lem_in->input_string_copy == '\0')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool							all_flags_on_vi(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((lem_in->flags & START) && (lem_in->flags & END) && \
		(lem_in->flags & LINK))
		return (SUCCESS);
	else
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
}

t_bool							read_stdin_vi(t_project *lem_in)
{
	char			*temp;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*new;

	ret = 1;
	new = ft_strnew(0);
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (ret != 0)
	{
		ret = read(0, buf, BUFF_SIZE);
		if (ret == -1)
			return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
		buf[ret] = '\0';
		temp = new;
		new = ft_strjoin(new, buf);
		free(temp);
	}
	lem_in->input_string = new;
	lem_in->input_string_copy = lem_in->input_string;
	return (SUCCESS);
}

static void			get_transitions2(t_mconfig **mconfig)
{
	TRANSITIONS[s_switch_start_flag_on_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_switch_start_flag_on_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_check_end_in_line_vi][SUCCESS] = \
	s_switch_end_flag_on_vi;
	TRANSITIONS[s_check_end_in_line_vi][FAIL] = s_skip_command_line_vi;
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
	TRANSITIONS[s_next_line_room_hash_vi][SUCCESS] = s_sec_char_hash_vi;
	TRANSITIONS[s_sec_char_hash_vi][FAIL] = s_input_file_done_vi;
	TRANSITIONS[s_sec_char_hash_vi][SUCCESS] = s_check_start_in_line_vi;
	TRANSITIONS[s_check_start_in_line_vi][FAIL] = s_check_end_in_line_vi;
	TRANSITIONS[s_check_start_in_line_vi][SUCCESS] = s_switch_start_flag_on_vi;
	get_transitions2(mconfig);
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine] = NULL;
	EVENTS[s_read_stdin_vi] = read_stdin_vi;
	EVENTS[s_first_char_newline_vi] = first_char_newline_vi;
	EVENTS[s_first_char_zero_vi] = first_char_zero_vi;
	EVENTS[s_first_char_delim_vi] = first_char_delim_vi;
	EVENTS[s_first_char_hash_vi] = first_char_hash_vi;
	EVENTS[s_sec_char_hash_vi] = sec_char_hash_vi;
	EVENTS[s_find_hyphen_vi] = find_hyphen_vi;
	EVENTS[s_next_line_room_hash_vi] = next_line_room_hash_vi;
	EVENTS[s_next_line_room_link_vi] = next_line_room_link_vi;
	EVENTS[s_isdigit_to_newline_vi] = isdigit_to_newline_vi;
	EVENTS[s_isdigit_to_space_vi] = isdigit_to_space_vi;
	EVENTS[s_isallnum_to_hyphen_vi] = isallnum_to_hyphen_vi;
	EVENTS[s_isallnum_to_space_vi] = isallnum_to_space_vi;
	EVENTS[s_isallnum_to_newline_vi] = isallnum_to_newline_vi;
	EVENTS[s_check_end_in_line_vi] = check_end_in_line_vi;
	EVENTS[s_check_start_in_line_vi] = check_start_in_line_vi;
	EVENTS[s_switch_start_flag_on_vi] = switch_start_flag_on_vi;
	EVENTS[s_switch_end_flag_on_vi] = switch_end_flag_on_vi;
	EVENTS[s_switch_link_flag_on_vi] = switch_link_flag_on_vi;
	EVENTS[s_skip_command_line_vi] = skip_command_line_vi;
	EVENTS[s_check_link_flag_on_vi] = check_link_flag_on_vi;
	EVENTS[s_all_flags_on_vi] = all_flags_on_vi;
	EVENTS[s_input_file_done_vi] = input_file_done_vi;
}

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

	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (ERROR)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}
