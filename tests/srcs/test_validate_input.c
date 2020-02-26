/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_validate_input.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:35:37 by mgross         #+#    #+#                */
/*   Updated: 2020/02/26 13:21:23 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <criterion/criterion.h>

Test(input_eval, first_char_delim_vi_test)
{
	t_project 		*lem_in;
	t_bool			boolean;
	int				index;
	char			*temp;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*new;
	int				fd;

	index = 0;
	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	lem_in->input_eval_string = ft_strdup("\0");
	
	boolean = first_char_delim_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	fd =  open("../maps/invalid_maps/map_empty.map", O_RDONLY);
	ret = 1;
	new = ft_strnew(0);
	while (ret != 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			break;
		buf[ret] = '\0';
		temp = new;
		new = ft_strjoin(new, buf);
		free(temp);
	}
	if (ret == -1)
		ft_printf("FAIL open file");
	else
	{
		lem_in->input_eval_string = new;
		boolean = first_char_delim_vi(lem_in);
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	}
	close(fd);
	
	lem_in->input_eval_string = ft_strdup("");
	boolean = first_char_delim_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	lem_in->input_eval_string = ft_strdup(" ");
	boolean = first_char_delim_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	lem_in->input_eval_string = ft_strdup("\n");
	boolean = first_char_delim_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	lem_in->input_eval_string = ft_strdup("hallo");
	while (1)
	{
		boolean = first_char_delim_vi(lem_in);
		if (boolean == 1)
			break;
		index++;
		EVAL_STR++;
	}
	if (index == 5)
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	else
		cr_expect(0 == 1, "Test failed because");
	free(lem_in);
}

Test(input_eval, first_char_newline_vi_test)
{
	t_project 		*lem_in;
	t_bool			boolean;
	int				index;

	index = 0;
	lem_in = (t_project*)ft_memalloc(sizeof(t_project));

	EVAL_STR = ft_strdup("\n");
	boolean = first_char_newline_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	EVAL_STR = ft_strdup("d");
	boolean = first_char_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR = ft_strdup("");
	boolean = first_char_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR = ft_strdup("hallo\n");
	while (1)
	{
		boolean = first_char_newline_vi(lem_in);
		if (boolean == 1)
			break;
		index++;
		EVAL_STR++;
	}
	if (index == 5)
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	else
		cr_expect(0 == 1, "Test failed because");
	free(lem_in);
}

Test(input_eval, first_char_zero_vi_test)
{
	t_project 		*lem_in;
	t_bool			boolean;
	int				index;

	index = 0;
	lem_in = (t_project*)ft_memalloc(sizeof(t_project));

	EVAL_STR = ft_strdup("0");
	boolean = first_char_zero_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	EVAL_STR = ft_strdup("d");
	boolean = first_char_zero_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR = ft_strdup("");
	boolean = first_char_zero_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR = ft_strdup("hallo0");
	while (1)
	{
		boolean = first_char_zero_vi(lem_in);
		if (boolean == 1)
			break;
		index++;
		EVAL_STR++;
	}
	if (index == 5)
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	else
		cr_expect(0 == 1, "Test failed because");
	free(lem_in);
}

Test(input_eval, first_char_hash_vi_test)
{
	t_project 		*lem_in;
	t_bool			boolean;
	int				index;

	index = 0;
	lem_in = (t_project*)ft_memalloc(sizeof(t_project));

	lem_in->input_eval_string = ft_strdup("#");
	boolean = first_char_hash_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	EVAL_STR = ft_strdup("d");
	boolean = first_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR = ft_strdup("\n");
	boolean = first_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR = ft_strdup("");
	boolean = first_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	EVAL_STR = ft_strdup("hallo#");
	while (1)
	{
		boolean = first_char_hash_vi(lem_in);
		if (boolean == 1)
			break;
		index++;
		EVAL_STR++;
	}
	if (index == 5)
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	else
		cr_expect(0 == 1, "Test failed because");
	free(lem_in);
}

Test(input_eval, second_char_hash_vi_test)
{
	t_project 		*lem_in;
	t_bool			boolean;
	int				index;

	index = 0;
	lem_in = (t_project*)ft_memalloc(sizeof(t_project));

	lem_in->input_eval_string = ft_strdup("##start\n");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	lem_in->input_eval_string = ft_strdup("##end\n");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	lem_in->input_eval_string = ft_strdup("##hfskdj\n");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	EVAL_STR = ft_strdup("#dfsdfsdf\nsdfds");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", EVAL_STR);

	EVAL_STR = ft_strdup("#sdfsdf");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR = ft_strdup("");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	free(lem_in);
}

Test(input_eval, isdigit_to_newline_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	char			*temp;
	
	lem_in = (t_project*)malloc(sizeof(t_project));

	EVAL_STR = ft_strdup("7478489\n234558");
	temp = EVAL_STR;
	boolean = isdigit_to_newline_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	free(temp);

	EVAL_STR = ft_strdup("7478489234558");
	temp = EVAL_STR;
	boolean = isdigit_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	EVAL_STR = ft_strdup("747848h9234558");
	temp = EVAL_STR;
	boolean = isdigit_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	EVAL_STR = ft_strdup("747848h92\n34558");
	temp = EVAL_STR;
	boolean = isdigit_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	free(lem_in);
}

Test(input_eval, isdigit_to_space_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	char			*temp;
	
	lem_in = (t_project*)malloc(sizeof(t_project));

	EVAL_STR = ft_strdup("7478489 234558\n");
	temp = EVAL_STR;
	boolean = isdigit_to_space_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	free(temp);

	EVAL_STR = ft_strdup("7478489234558");
	temp = EVAL_STR;
	boolean = isdigit_to_space_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	EVAL_STR = ft_strdup("fsd");
	temp = EVAL_STR;
	boolean = isdigit_to_space_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	EVAL_STR = ft_strdup("747848h92\n34558");
	temp = EVAL_STR;
	boolean = isdigit_to_space_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	free(lem_in);
}

Test(input_eval, isallnum_to_hyphen_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	
	lem_in = (t_project*)malloc(sizeof(t_project));

	EVAL_STR = ft_strdup("hD6734-38djkUI\n");
	boolean = isallnum_to_hyphen_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", EVAL_STR);

	EVAL_STR = ft_strdup("hD6&7343-8djkUI");
	boolean = isallnum_to_hyphen_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", EVAL_STR);

	EVAL_STR = ft_strdup("hD673438djkUI");
	boolean = isallnum_to_hyphen_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", EVAL_STR);

	free(lem_in);
}

Test(input_eval, isallnum_to_newline_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	
	lem_in = (t_project*)malloc(sizeof(t_project));

	EVAL_STR = ft_strdup("38djkUI\nsdjhfkjsdh-jshdfkjs");
	boolean = isallnum_to_newline_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", EVAL_STR);

	EVAL_STR = ft_strdup("hD6&7343\n8djkUI");
	boolean = isallnum_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", EVAL_STR);

	EVAL_STR = ft_strdup("hD673438djkUI");
	boolean = isallnum_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", EVAL_STR);

	free(lem_in);
}

Test(input_eval, isallnum_to_space_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	
	lem_in = (t_project*)malloc(sizeof(t_project));

	EVAL_STR = ft_strdup("38djkUI 383 45");
	boolean = isallnum_to_space_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", EVAL_STR);

	EVAL_STR = ft_strdup("hD6&7343 49 893");
	boolean = isallnum_to_space_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", EVAL_STR);

	EVAL_STR = ft_strdup("hD673438djkUI");
	boolean = isallnum_to_space_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", EVAL_STR);

	free(lem_in);
}


Test(input_eval, all_flags_on_vi_test)
{
	t_project	*lem_in;
	t_bool	boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));

	FLAGS = FLAGS |= START;
	FLAGS = FLAGS |= END;
	FLAGS = FLAGS |= LINK;
	boolean = all_flags_on_vi(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	FLAGS = 0;
	FLAGS = FLAGS |= END;
	boolean = all_flags_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	FLAGS = 0;
	FLAGS = FLAGS |= START;
	boolean = all_flags_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	FLAGS = 0;
	FLAGS = FLAGS |= LINK;
	boolean = all_flags_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	FLAGS = 0;
	boolean = all_flags_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	free(lem_in);
}

Test(input_eval, input_file_done_vi_test)
{
	t_project	*lem_in;
	t_bool		boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));

	EVAL_STR = ft_strdup("6");
	boolean = input_file_done_vi(lem_in);
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR++;
	boolean = input_file_done_vi(lem_in);
	cr_assert(boolean == SUCCESS,  "The result was %d, expected %d\n", boolean, SUCCESS);
	
	free(lem_in);
}

Test(input_eval, check_if_start_command_line_vi_test)
{
	t_project	*lem_in;

	lem_in = (t_project*)malloc(sizeof(t_project));
	t_bool	boolean;

	EVAL_STR = ft_strdup("##start\nkjsdhfksfj");
	boolean = check_if_start_command_line_vi(lem_in);	
	cr_assert(boolean == SUCCESS,  "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", EVAL_STR);

	EVAL_STR = ft_strdup("##stsdfart\nkjsdhfksfj");
	boolean = check_if_start_command_line_vi(lem_in);	
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR = ft_strdup("##startk\njsdhfksfj");
	boolean = check_if_start_command_line_vi(lem_in);	
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);
	
	free(lem_in);
}

Test(input_eval, check_if_end_command_line_vi_test)
{
	t_project	*lem_in;
	t_bool	boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));

	EVAL_STR = ft_strdup("##end\nkjsdhfksfj");
	boolean = check_if_end_command_line_vi(lem_in);	
	cr_assert(boolean == SUCCESS,  "The result was %d, expected %d\n", boolean, SUCCESS);

	EVAL_STR = ft_strdup("##stsdfart\nkjsdhfksfj");
	boolean = check_if_end_command_line_vi(lem_in);	
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);

	EVAL_STR = ft_strdup("##endf\njsdhfksfj");
	boolean = check_if_end_command_line_vi(lem_in);	
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);

	free(EVAL_STR);
}

Test(input_eval, switch_start_flag_on_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	
	FLAGS = 0;
	boolean = switch_start_flag_on_vi(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	FLAGS = 0;
	FLAGS = FLAGS |= START;
	boolean = switch_start_flag_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	free(lem_in);
}

Test(input_eval, switch_end_flag_on_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	
	FLAGS = 0;
	boolean = switch_end_flag_on_vi(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("FLAG: %d\n", FLAGS);


	FLAGS = 0;
	FLAGS = FLAGS |= END;
	boolean = switch_end_flag_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	free(lem_in);
}

Test(input_eval, check_link_flag_on_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	
	FLAGS = 0;
	FLAGS = FLAGS |= LINK;
	boolean = check_link_flag_on_vi(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	FLAGS = 0;
	boolean = check_link_flag_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	free(lem_in);
}

Test(input_eval, switch_link_flag_on_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	
	FLAGS = 0;
	boolean = switch_link_flag_on_vi(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("FLAG: %d\n", FLAGS);

	FLAGS = 0;
	FLAGS = FLAGS |= LINK;
	boolean = switch_link_flag_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	free(lem_in);
}

Test(input_eval, find_hyphen_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	
	FLAGS = 0;
	EVAL_STR = ft_strdup("hfs88G-jfids9\n");
	boolean = find_hyphen_vi(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("FLAG: %d, STRING: %s\n", FLAGS, EVAL_STR);

	EVAL_STR = ft_strdup("hfs88Gjfids9 849 029\n");
	boolean = find_hyphen_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	free(lem_in);
}
