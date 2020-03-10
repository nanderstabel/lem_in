/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_validate_input.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:35:37 by mgross         #+#    #+#                */
/*   Updated: 2020/03/10 12:40:54 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(input_validation, validate_input_test)
{
	int				fd;
	t_project		*lem_in;
	t_bool			boolean;
	t_list			*temp;

	lem_in = (t_project*)malloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/map1.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	// FLAGS |= DEBUG_O;
	boolean = validate_input(lem_in);
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			ft_printf("-- Function that failed: %s\n\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// free(lem_in);
	
	// lem_in = (t_project*)malloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/map2.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	boolean = validate_input(lem_in);
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			ft_printf("-- Function that failed: %s\n\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// free(lem_in);

	
	// lem_in = (t_project*)malloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/map3.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	boolean = validate_input(lem_in);
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			ft_printf("-- Function that failed: %s\n\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// free(lem_in);

	// lem_in = (t_project*)malloc(sizeof(t_project));
	close(0);
	fd = open("../maps/invalid_maps/invalid_map1.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	boolean = validate_input(lem_in);
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			// ft_printf("-- Function that failed: %s\n\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// free(lem_in);

	// lem_in = (t_project*)malloc(sizeof(t_project));
	close(0);
	fd = open("../maps/invalid_maps/no_room_after_start_map.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	// FLAGS |= DEBUG_O;
	boolean = validate_input(lem_in);
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			// ft_printf("-- Function that failed: %s\n\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// free(lem_in);

	// lem_in = (t_project*)malloc(sizeof(t_project));
	close(0);
	fd = open("../maps/invalid_maps/no_room_after_start_map2.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	// FLAGS |= DEBUG_O;
	boolean = validate_input(lem_in);
	if (lem_in->error)
	{
		temp = lem_in->error;
		while(temp != NULL)
		{
			// ft_printf("-- Function that failed: %s\n\n", (char*)temp->content);
			temp = temp->next;
		}
	}
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// free(lem_in);

}

Test(input_validation, num_of_ants_links_rooms_test)
{
	int				fd;
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/map1.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	// FLAGS |= DEBUG_O;
	NANTS = 0;
	NLINKS = 0;
	NROOMS = 0;
	INPUT_CPY = NULL;
	lem_in->input_string = NULL;
	boolean = validate_input(lem_in);
	cr_assert(NANTS == 3, "The result was %zu, expected %d\n", NANTS, 3);
	cr_assert(NROOMS == 4, "The result was %zu, expected %d\n", NROOMS, 4);
	cr_assert(NLINKS == 3, "The result was %zu, expected %d\n", NLINKS, 3);
	// free(lem_in);

	// lem_in = (t_project*)malloc(sizeof(t_project));
	close(0);
	fd = open("../maps/valid_maps/map2.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	// FLAGS |= DEBUG_O;
	NANTS = 0;
	NLINKS = 0;
	NROOMS = 0;
	INPUT_CPY = NULL;
	lem_in->input_string = NULL;
	boolean = validate_input(lem_in);
	cr_assert(NANTS == 4, "The result was %zu, expected %d\n", NANTS, 4);
	cr_assert(NROOMS == 8, "The result was %zu, expected %d\n", NROOMS, 8);
	cr_assert(NLINKS == 9, "The result was %zu, expected %d\n", NLINKS, 9);
	// free(lem_in);

	// lem_in = (t_project*)malloc(sizeof(t_project));	
	close(0);
	fd = open("../maps/valid_maps/map3.map", O_RDONLY);
	ERROR = NULL;
	FLAGS = 0;
	// FLAGS |= DEBUG_O;
	NANTS = 0;
	NLINKS = 0;
	NROOMS = 0;
	INPUT_CPY = NULL;
	lem_in->input_string = NULL;
	boolean = validate_input(lem_in);
	cr_assert(NANTS == 4, "The result was %zu, expected %d\n", NANTS, 4);
	cr_assert(NROOMS == 8, "The result was %zu, expected %d\n", NROOMS, 8);
	cr_assert(NLINKS == 9, "The result was %zu, expected %d\n", NLINKS, 9);

}

Test(input_validation, first_char_delim_vi_test)
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
	FLAGS = 0;
	ERROR = NULL;
	
	INPUT_CPY = ft_strdup("\0");
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
		INPUT_CPY = new;
		boolean = first_char_delim_vi(lem_in);
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	}
	close(fd);
	
	INPUT_CPY = ft_strdup("");
	boolean = first_char_delim_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	INPUT_CPY = ft_strdup(" ");
	boolean = first_char_delim_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("\n");
	boolean = first_char_delim_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("hallo");
	while (1)
	{
		boolean = first_char_delim_vi(lem_in);
		if (boolean == 1)
			break;
		index++;
		INPUT_CPY++;
	}
	if (index == 5)
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	else
		cr_expect(0 == 1, "Test failed because");
	free(lem_in);
}

Test(input_validation, first_char_newline_vi_test)
{
	t_project 		*lem_in;
	t_bool			boolean;
	int				index;

	index = 0;
	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

	INPUT_CPY = ft_strdup("\n");
	boolean = first_char_newline_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	INPUT_CPY = ft_strdup("d");
	boolean = first_char_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("");
	boolean = first_char_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("hallo\n");
	while (1)
	{
		boolean = first_char_newline_vi(lem_in);
		if (boolean == 1)
			break;
		index++;
		INPUT_CPY++;
	}
	if (index == 5)
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	else
		cr_expect(0 == 1, "Test failed because");
	free(lem_in);
}

Test(input_validation, first_char_zero_vi_test)
{
	t_project 		*lem_in;
	t_bool			boolean;
	int				index;

	index = 0;
	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

	INPUT_CPY = ft_strdup("0");
	boolean = first_char_zero_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	INPUT_CPY = ft_strdup("d");
	boolean = first_char_zero_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("");
	boolean = first_char_zero_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("hallo0");
	while (1)
	{
		boolean = first_char_zero_vi(lem_in);
		if (boolean == 1)
			break;
		index++;
		INPUT_CPY++;
	}
	if (index == 5)
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	else
		cr_expect(0 == 1, "Test failed because");
	free(lem_in);
}

Test(input_validation, first_char_hash_vi_test)
{
	t_project 		*lem_in;
	t_bool			boolean;
	int				index;

	index = 0;
	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

	INPUT_CPY = ft_strdup("#");
	boolean = first_char_hash_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	INPUT_CPY = ft_strdup("d");
	boolean = first_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("\n");
	boolean = first_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("");
	boolean = first_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	INPUT_CPY = ft_strdup("hallo#");
	while (1)
	{
		boolean = first_char_hash_vi(lem_in);
		if (boolean == 1)
			break;
		index++;
		INPUT_CPY++;
	}
	if (index == 5)
		cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	else
		cr_expect(0 == 1, "Test failed because");
	free(lem_in);
}

Test(input_validation, second_char_hash_vi_test)
{
	t_project 		*lem_in;
	t_bool			boolean;
	int				index;

	index = 0;
	lem_in = (t_project*)ft_memalloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

	INPUT_CPY = ft_strdup("##start\n");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	INPUT_CPY = ft_strdup("##end\n");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	INPUT_CPY = ft_strdup("##hfskdj\n");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	INPUT_CPY = ft_strdup("#dfsdfsdf\nsdfds");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", INPUT_CPY);

	INPUT_CPY = ft_strdup("#sdfsdf");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("");
	boolean = second_char_hash_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	free(lem_in);
}

Test(input_validation, isdigit_to_newline_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	char			*temp;
	
	lem_in = (t_project*)malloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;
	
	INPUT_CPY = ft_strdup("7478489\n234558");
	temp = INPUT_CPY;
	boolean = isdigit_to_newline_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	free(temp);

	INPUT_CPY = ft_strdup("7478489234558");
	temp = INPUT_CPY;
	boolean = isdigit_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	INPUT_CPY = ft_strdup("747848h9234558");
	temp = INPUT_CPY;
	boolean = isdigit_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	INPUT_CPY = ft_strdup("747848h92\n34558");
	temp = INPUT_CPY;
	boolean = isdigit_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	free(lem_in);
}

Test(input_validation, isdigit_to_space_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	char			*temp;
	
	lem_in = (t_project*)malloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;
	
	INPUT_CPY = ft_strdup("7478489 234558\n");
	temp = INPUT_CPY;
	boolean = isdigit_to_space_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	free(temp);

	INPUT_CPY = ft_strdup("7478489234558");
	temp = INPUT_CPY;
	boolean = isdigit_to_space_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	INPUT_CPY = ft_strdup("fsd");
	temp = INPUT_CPY;
	boolean = isdigit_to_space_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	INPUT_CPY = ft_strdup("747848h92\n34558");
	temp = INPUT_CPY;
	boolean = isdigit_to_space_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	free(temp);
	
	free(lem_in);
}

Test(input_validation, isallnum_to_hyphen_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	
	lem_in = (t_project*)malloc(sizeof(t_project));
	ERROR = NULL;
	FLAGS = 0;

	INPUT_CPY = ft_strdup("hD6*&23734-38djkUI\n");
	boolean = isallnum_to_hyphen_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", INPUT_CPY);

	INPUT_CPY = ft_strdup("hD6&7343-8djkUI");
	boolean = isallnum_to_hyphen_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", INPUT_CPY);

	INPUT_CPY = ft_strdup("hD673438djkUI");
	boolean = isallnum_to_hyphen_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", INPUT_CPY);

	free(lem_in);
}

Test(input_validation, isallnum_to_newline_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	
	lem_in = (t_project*)malloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

	INPUT_CPY = ft_strdup("38d(@jkUI\nsdjhfkjsdh-jshdfkjs");
	boolean = isallnum_to_newline_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", INPUT_CPY);

	INPUT_CPY = ft_strdup("hD6&7343\n8djkUI");
	boolean = isallnum_to_newline_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", INPUT_CPY);
	
	INPUT_CPY = ft_strdup("LD6&7343\n8djkUI");
	boolean = isallnum_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", INPUT_CPY);

	INPUT_CPY = ft_strdup("hD6734-38djkUI");
	boolean = isallnum_to_newline_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", INPUT_CPY);

	free(lem_in);
}

Test(input_validation, isallnum_to_space_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;
	
	lem_in = (t_project*)malloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

	INPUT_CPY = ft_strdup("38&3+djkUI 383 45");
	boolean = isallnum_to_space_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", INPUT_CPY);

	INPUT_CPY = ft_strdup("hD6&7343 49 893");
	boolean = isallnum_to_space_vi(lem_in);
	cr_expect(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", INPUT_CPY);

	INPUT_CPY = ft_strdup("hD673438djkUI");
	boolean = isallnum_to_space_vi(lem_in);
	cr_expect(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	// ft_printf("string: %s\n", INPUT_CPY);

	free(lem_in);
}


Test(input_validation, all_flags_on_vi_test)
{
	t_project	*lem_in;
	t_bool	boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

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

Test(input_validation, input_file_done_vi_test)
{
	t_project	*lem_in;
	t_bool		boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

	INPUT_CPY = ft_strdup("6");
	boolean = input_file_done_vi(lem_in);
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY++;
	boolean = input_file_done_vi(lem_in);
	cr_assert(boolean == SUCCESS,  "The result was %d, expected %d\n", boolean, SUCCESS);
	
	free(lem_in);
}

Test(input_validation, check_if_start_command_line_vi_test)
{
	t_project	*lem_in;
	t_bool		boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

	INPUT_CPY = ft_strdup("##start\nkjsdhfksfj");
	boolean = check_if_start_command_line_vi(lem_in);	
	cr_assert(boolean == SUCCESS,  "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("string: %s\n", INPUT_CPY);

	INPUT_CPY = ft_strdup("##stsdfart\nkjsdhfksfj");
	boolean = check_if_start_command_line_vi(lem_in);	
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("##startk\njsdhfksfj");
	boolean = check_if_start_command_line_vi(lem_in);	
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);
	
	free(lem_in);
}

Test(input_validation, check_if_end_command_line_vi_test)
{
	t_project	*lem_in;
	t_bool	boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	FLAGS = 0;
	ERROR = NULL;

	INPUT_CPY = ft_strdup("##end\nkjsdhfksfj");
	boolean = check_if_end_command_line_vi(lem_in);	
	cr_assert(boolean == SUCCESS,  "The result was %d, expected %d\n", boolean, SUCCESS);

	INPUT_CPY = ft_strdup("##stsdfart\nkjsdhfksfj");
	boolean = check_if_end_command_line_vi(lem_in);	
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);

	INPUT_CPY = ft_strdup("##endf\njsdhfksfj");
	boolean = check_if_end_command_line_vi(lem_in);	
	cr_assert(boolean == FAIL,  "The result was %d, expected %d\n", boolean, FAIL);

	free(INPUT_CPY);
}

Test(input_validation, switch_start_flag_on_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	ERROR = NULL;

	FLAGS = 0;
	boolean = switch_start_flag_on_vi(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	FLAGS = 0;
	FLAGS = FLAGS |= START;
	boolean = switch_start_flag_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	free(lem_in);
}

Test(input_validation, switch_end_flag_on_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	ERROR = NULL;

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

Test(input_validation, check_link_flag_on_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	ERROR = NULL;

	FLAGS = 0;
	FLAGS = FLAGS |= LINK;
	boolean = check_link_flag_on_vi(lem_in);
	
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	FLAGS = 0;
	boolean = check_link_flag_on_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	free(lem_in);
}

Test(input_validation, switch_link_flag_on_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	ERROR = NULL;

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

Test(input_validation, find_hyphen_vi_test)
{
	t_project		*lem_in;
	t_bool			boolean;

	lem_in = (t_project*)malloc(sizeof(t_project));
	ERROR = NULL;
	
	FLAGS = 0;
	INPUT_CPY = ft_strdup("hfs88G-jfids9\n");
	boolean = find_hyphen_vi(lem_in);
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	// ft_printf("FLAG: %d, STRING: %s\n", FLAGS, INPUT_CPY);

	INPUT_CPY = ft_strdup("hfs88Gjfids9 849 029\n");
	boolean = find_hyphen_vi(lem_in);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	free(lem_in);
}
