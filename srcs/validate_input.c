/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:54:14 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/26 14:18:14 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool								first_char_newline_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);

	if (*VALIDATE_STR == '\n')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								first_char_zero_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);

	if (*VALIDATE_STR == '0')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								first_char_delim_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);

	if (*VALIDATE_STR == '\0')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								first_char_hash_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	if (*VALIDATE_STR == '#')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								second_char_hash_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	if (*(VALIDATE_STR + 1) == '#')
		return (SUCCESS);
	else
	{
		while (*VALIDATE_STR != '\n' && *VALIDATE_STR != '\0')
			VALIDATE_STR++;
		if (*VALIDATE_STR == '\n')
			VALIDATE_STR++;
		return (FAIL);
	}
}

t_bool								isdigit_to_space_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	while (*VALIDATE_STR != ' ')
	{
		if (ft_isdigit(*VALIDATE_STR) != 1)
			return (FAIL);
		VALIDATE_STR++;
	}
	VALIDATE_STR++;
	return (SUCCESS);
}

t_bool								isdigit_to_newline_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	while (*VALIDATE_STR != '\n')
	{
		if (ft_isdigit(*VALIDATE_STR) != 1)
			return (FAIL);
		VALIDATE_STR++;
	}
	VALIDATE_STR++;
	return (SUCCESS);
}

t_bool								check_link_flag_on_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	if ((FLAGS & LINK) == LINK)
		return (SUCCESS);
	else
		return (FAIL);	
}

t_bool								isallnum_to_hyphen_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	while (*VALIDATE_STR != '-')
	{
		if (ft_isalnum((int)*VALIDATE_STR) != 1)
			return (FAIL);
		VALIDATE_STR++;
	}
	VALIDATE_STR++;
	return (SUCCESS);
}

t_bool								isallnum_to_newline_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	while (*VALIDATE_STR != '\n')
	{
		if (ft_isalnum((int)*VALIDATE_STR) != 1)
			return (FAIL);
		VALIDATE_STR++;
	}
	VALIDATE_STR++;
	return (SUCCESS);
}

t_bool								isallnum_to_space_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	while (*VALIDATE_STR != ' ')
	{
		if (ft_isalnum((int)*VALIDATE_STR) != 1)
			return (FAIL);
		VALIDATE_STR++;
	}
	VALIDATE_STR++;
	return (SUCCESS);
}

t_bool								check_if_start_command_line_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	if (ft_strcmp_delim(VALIDATE_STR, "##start\n", (int)'\n') == 0)
	{
		while (*VALIDATE_STR != '\n' && *VALIDATE_STR != '\0')
			VALIDATE_STR++;
		if (*VALIDATE_STR == '\n')
			VALIDATE_STR++;
		return (SUCCESS);
	}
	else
		return (FAIL);
}

t_bool								check_if_end_command_line_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	if (ft_strcmp_delim(VALIDATE_STR, "##end\n", (int)'\n') == 0)
	{
		while (*VALIDATE_STR != '\n' && *VALIDATE_STR != '\0')
			VALIDATE_STR++;
		if (*VALIDATE_STR == '\n')
			VALIDATE_STR++;
		return (SUCCESS);
	}
	else
		return (FAIL);
}

t_bool								skip_command_line_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	while (*VALIDATE_STR != '\n' && *VALIDATE_STR != '\0')
		VALIDATE_STR++;
	if (*VALIDATE_STR == '\n')
		VALIDATE_STR++;
	return (SUCCESS);
}

t_bool								switch_start_flag_on_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);

	if ((FLAGS & START) == START)
		return (FAIL);
	else
		FLAGS = FLAGS |= START;
		return (SUCCESS);
}

t_bool								switch_end_flag_on_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	if ((FLAGS & END) == END)
		return (FAIL);
	else
		FLAGS = FLAGS |= END;
		return (SUCCESS);
}

t_bool								switch_link_flag_on_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	if ((FLAGS & LINK) == LINK)
		return (FAIL);
	else
		FLAGS = FLAGS |= LINK;
		return (SUCCESS);
}

t_bool								find_hyphen_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);

	int		index;

	index = 0;
	while (VALIDATE_STR[index] != '\n' && VALIDATE_STR[index] != '\0')
	{
		if (VALIDATE_STR[index] == '-')
		{
			FLAGS = FLAGS |= LINK;
			return (SUCCESS);
		}
		index++;
	}
	return (FAIL);
}

t_bool								find_error_vi(t_project *lem_in)
{
	(void)lem_in;
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);	
}

t_bool		input_file_done_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);
	
	if (*VALIDATE_STR == '\0')
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool								all_flags_on_vi(t_project *lem_in)
{
	// ft_printf("Currently: %s\n", __func__);

	if ((FLAGS & START) == START && (FLAGS & END) == END && \
		(FLAGS & LINK) == LINK)
		return (SUCCESS);
	else
		return (FAIL);
}

t_bool		read_stdin_vi(t_project *lem_in)
{
	char			*temp;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*new;

	// ft_printf("Currently: %s\n", __func__);
	
	ret = 1;
	new = ft_strnew(0);
	while (ret != 0)
	{
		ret = read(0, buf, BUFF_SIZE);
		if (ret == -1)
			return (FAIL);
		buf[ret] = '\0';
		temp = new;
		new = ft_strjoin(new, buf);
		free(temp);
	}
	lem_in->input_string = new;
	VALIDATE_STR = lem_in->input_string;
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_install_machine][SUCCESS] = s_read_stdin_vi;
	TRANSITIONS[s_read_stdin_vi][FAIL] = s_uninstall_machine_vi; //ERROR
	TRANSITIONS[s_read_stdin_vi][SUCCESS] = s_first_char_delim_vi;
	TRANSITIONS[s_first_char_delim_vi][SUCCESS] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_first_char_delim_vi][FAIL] = s_first_char_newline_vi;
	TRANSITIONS[s_first_char_newline_vi][SUCCESS] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_first_char_newline_vi][FAIL] = s_first_char_zero_vi;
	TRANSITIONS[s_first_char_zero_vi][SUCCESS] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_first_char_zero_vi][FAIL] = s_isdigit_to_newline_vi;
	TRANSITIONS[s_isdigit_to_newline_vi][FAIL] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_isdigit_to_newline_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_input_file_done_vi][FAIL] = s_first_char_hash_vi; // <<<while>>>
	TRANSITIONS[s_input_file_done_vi][SUCCESS] = s_all_flags_on_vi;
	TRANSITIONS[s_all_flags_on_vi][FAIL] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_all_flags_on_vi][SUCCESS] = s_uninstall_machine_vi; // INPUT VALIDATED
	TRANSITIONS[s_first_char_hash_vi][FAIL] = s_check_link_flag_on_vi;
	TRANSITIONS[s_first_char_hash_vi][SUCCESS] = s_second_char_hash_vi;
	TRANSITIONS[s_second_char_hash_vi][FAIL] = s_input_file_done_vi;
	TRANSITIONS[s_second_char_hash_vi][SUCCESS] = s_check_if_start_command_line_vi; 
	TRANSITIONS[s_check_if_start_command_line_vi][FAIL] = s_check_if_end_command_line_vi;
	TRANSITIONS[s_check_if_start_command_line_vi][SUCCESS] = s_switch_start_flag_on_vi;
	TRANSITIONS[s_switch_start_flag_on_vi][FAIL] = s_uninstall_machine_vi; //ERROR
	TRANSITIONS[s_switch_start_flag_on_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_check_if_end_command_line_vi][SUCCESS] = s_switch_end_flag_on_vi;
	TRANSITIONS[s_check_if_end_command_line_vi][FAIL] = s_input_file_done_vi;
	TRANSITIONS[s_switch_end_flag_on_vi][SUCCESS] = s_skip_command_line_vi;
	TRANSITIONS[s_switch_end_flag_on_vi][FAIL] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_skip_command_line_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_skip_command_line_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_check_link_flag_on_vi][SUCCESS] = s_isallnum_to_hyphen_vi;// <<<<<<<<<<<<<<<<<<
	TRANSITIONS[s_check_link_flag_on_vi][FAIL] = s_find_hyphen_vi;
	TRANSITIONS[s_isallnum_to_hyphen_vi][SUCCESS] = s_isallnum_to_newline_vi;
	TRANSITIONS[s_isallnum_to_hyphen_vi][FAIL] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_isallnum_to_newline_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_isallnum_to_newline_vi][FAIL] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_find_hyphen_vi][SUCCESS] = s_isallnum_to_hyphen_vi;
	TRANSITIONS[s_find_hyphen_vi][FAIL] = s_isallnum_to_space_vi;
	TRANSITIONS[s_isallnum_to_space_vi][SUCCESS] = s_isdigit_to_space_vi;
	TRANSITIONS[s_isallnum_to_space_vi][FAIL] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_isdigit_to_space_vi][SUCCESS] = s_isdigit_to_newline_vi;
	TRANSITIONS[s_isdigit_to_space_vi][FAIL] = s_uninstall_machine_vi;//ERROR
	TRANSITIONS[s_isdigit_to_newline_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_isdigit_to_newline_vi][FAIL] = s_uninstall_machine_vi;//ERROR
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
	EVENTS[s_uninstall_machine_vi] = find_error_vi;
	EVENTS[s_uninstall_machine_vi] = NULL;
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

	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	ft_printf("Currently: %s\n", __func__);
	return (SUCCESS);
}
