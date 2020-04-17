/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input_machine.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:54:14 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/17 11:30:30 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions2(t_mconfig **mconfig)
{
	TRANSITIONS[s_switch_start_flag_on_vi][FAIL] = s_uninstall_machine_vi;
	TRANSITIONS[s_switch_start_flag_on_vi][SUCCESS] = s_input_file_done_vi;
	TRANSITIONS[s_check_end_in_line_vi][SUCCESS] = s_switch_end_flag_on_vi;
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

t_bool				validate_input(t_project *lem_in)
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
