/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transitions_events_vi.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: zitzak <zitzak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 20:28:21 by zitzak        #+#    #+#                 */
/*   Updated: 2020/05/22 20:38:42 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			get_transitions3_vi(t_mconfig **mconfig)
{
	(*mconfig)->transitions[s_isallnum_nline_vi][SUCCESS] = s_input_done_vi;
	(*mconfig)->transitions[s_isallnum_nline_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_find_hyphen_vi][SUCCESS] = s_isallnum_hyph_vi;
	(*mconfig)->transitions[s_find_hyphen_vi][FAIL] = s_isallnum_space_vi;
	(*mconfig)->transitions[s_isallnum_space_vi][SUCCESS] = s_isdigit_space_vi;
	(*mconfig)->transitions[s_isallnum_space_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_isdigit_space_vi][SUCCESS] = s_isdigit_nline_vi;
	(*mconfig)->transitions[s_isdigit_space_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_isdigit_nline_vi][SUCCESS] = s_input_done_vi;
	(*mconfig)->transitions[s_isdigit_nline_vi][FAIL] = s_uninstall_machine_vi;
}

void			get_transitions2_vi(t_mconfig **mconfig)
{
	(*mconfig)->transitions[s_ischar_hash_vi][FAIL] = s_link_flag_on_vi;
	(*mconfig)->transitions[s_ischar_hash_vi][SUCCESS] = s_line_room_hash_vi;
	(*mconfig)->transitions[s_line_room_hash_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_line_room_hash_vi][SUCCESS] = s_sec_char_hash_vi;
	(*mconfig)->transitions[s_sec_char_hash_vi][FAIL] = s_input_done_vi;
	(*mconfig)->transitions[s_sec_char_hash_vi][SUCCESS] = s_start_in_line_vi;
	(*mconfig)->transitions[s_start_in_line_vi][FAIL] = s_end_in_line_vi;
	(*mconfig)->transitions[s_start_in_line_vi][SUCCESS] = s_set_start_flag_vi;
	(*mconfig)->transitions[s_set_start_flag_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_set_start_flag_vi][SUCCESS] = s_input_done_vi;
	(*mconfig)->transitions[s_end_in_line_vi][SUCCESS] = s_set_end_flag_vi;
	(*mconfig)->transitions[s_end_in_line_vi][FAIL] = s_skip_comm_line_vi;
	(*mconfig)->transitions[s_set_end_flag_vi][SUCCESS] = s_input_done_vi;
	(*mconfig)->transitions[s_set_end_flag_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_skip_comm_line_vi][SUCCESS] = s_input_done_vi;
	(*mconfig)->transitions[s_skip_comm_line_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_link_flag_on_vi][SUCCESS] = s_next_line_room_vi;
	(*mconfig)->transitions[s_next_line_room_vi][SUCCESS] = s_isallnum_hyph_vi;
	(*mconfig)->transitions[s_next_line_room_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_link_flag_on_vi][FAIL] = s_find_hyphen_vi;
	(*mconfig)->transitions[s_isallnum_hyph_vi][SUCCESS] = s_isallnum_nline_vi;
	(*mconfig)->transitions[s_isallnum_hyph_vi][FAIL] = s_uninstall_machine_vi;
	get_transitions3_vi(mconfig);
}

void			get_transitions_vi(t_mconfig **mconfig)
{
	(*mconfig)->transitions[s_install_machine][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_install_machine][SUCCESS] = s_read_stdin_vi;
	(*mconfig)->transitions[s_read_stdin_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_read_stdin_vi][SUCCESS] = s_ischar_hash_b_vi;
	(*mconfig)->transitions[s_ischar_hash_b_vi][SUCCESS] = s_sec_char_hash_b_vi;
	(*mconfig)->transitions[s_ischar_hash_b_vi][FAIL] = s_ischar_del_vi;
	(*mconfig)->transitions[s_sec_char_hash_b_vi][SUCCESS] =
	s_skip_comm_line_b_vi;
	(*mconfig)->transitions[s_sec_char_hash_b_vi][FAIL] =
	s_uninstall_machine_vi;
	(*mconfig)->transitions[s_skip_comm_line_b_vi][SUCCESS] =
	s_ischar_hash_b_vi;
	(*mconfig)->transitions[s_ischar_del_vi][SUCCESS] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_ischar_del_vi][FAIL] = s_ischar_nlne_vi;
	(*mconfig)->transitions[s_ischar_nlne_vi][SUCCESS] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_ischar_nlne_vi][FAIL] = s_ischar_zero_vi;
	(*mconfig)->transitions[s_ischar_zero_vi][SUCCESS] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_ischar_zero_vi][FAIL] = s_isdigit_nline_vi;
	(*mconfig)->transitions[s_isdigit_nline_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_isdigit_nline_vi][SUCCESS] = s_input_done_vi;
	(*mconfig)->transitions[s_input_done_vi][FAIL] = s_ischar_hash_vi;
	(*mconfig)->transitions[s_input_done_vi][SUCCESS] = s_allflags_on_vi;
	(*mconfig)->transitions[s_allflags_on_vi][FAIL] = s_uninstall_machine_vi;
	(*mconfig)->transitions[s_allflags_on_vi][SUCCESS] = s_uninstall_machine_vi;
	get_transitions2_vi(mconfig);
}

void			get_events2_vi(t_mconfig **mconfig)
{
	(*mconfig)->events[s_skip_comm_line_b_vi] = skip_comm_line_b_vi;
	(*mconfig)->events[s_link_flag_on_vi] = link_flag_on_vi;
	(*mconfig)->events[s_allflags_on_vi] = allflags_on_vi;
	(*mconfig)->events[s_input_done_vi] = input_done_vi;
}

void			get_events_vi(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine] = NULL;
	(*mconfig)->events[s_read_stdin_vi] = read_stdin_vi;
	(*mconfig)->events[s_ischar_nlne_vi] = ischar_nlne_vi;
	(*mconfig)->events[s_ischar_zero_vi] = ischar_zero_vi;
	(*mconfig)->events[s_ischar_del_vi] = ischar_del_vi;
	(*mconfig)->events[s_ischar_hash_b_vi] = ischar_hash_b_vi;
	(*mconfig)->events[s_ischar_hash_vi] = ischar_hash_vi;
	(*mconfig)->events[s_sec_char_hash_vi] = sec_char_hash_vi;
	(*mconfig)->events[s_sec_char_hash_b_vi] = sec_char_hash_b_vi;
	(*mconfig)->events[s_find_hyphen_vi] = find_hyphen_vi;
	(*mconfig)->events[s_line_room_hash_vi] = line_room_hash_vi;
	(*mconfig)->events[s_next_line_room_vi] = next_line_room_vi;
	(*mconfig)->events[s_isdigit_nline_vi] = isdigit_nline_vi;
	(*mconfig)->events[s_isdigit_space_vi] = isdigit_space_vi;
	(*mconfig)->events[s_isallnum_hyph_vi] = isallnum_hyph_vi;
	(*mconfig)->events[s_isallnum_space_vi] = isallnum_space_vi;
	(*mconfig)->events[s_isallnum_nline_vi] = isallnum_nline_vi;
	(*mconfig)->events[s_end_in_line_vi] = end_in_line_vi;
	(*mconfig)->events[s_start_in_line_vi] = start_in_line_vi;
	(*mconfig)->events[s_set_start_flag_vi] = set_start_flag_vi;
	(*mconfig)->events[s_set_end_flag_vi] = set_end_flag_vi;
	(*mconfig)->events[s_switch_link_flag_on_vi] = switch_link_flag_on_vi;
	(*mconfig)->events[s_skip_comm_line_vi] = skip_comm_line_vi;
	get_events2_vi(mconfig);
}
