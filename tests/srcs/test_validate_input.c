/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_validate_input.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:35:37 by mgross         #+#    #+#                */
/*   Updated: 2020/02/20 18:52:33 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <criterion/criterion.h>

Test(input_eval, check_line_ants_test)
{
	t_bool boolean;
	boolean = check_line_ants("5\n");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = check_line_ants("1000\n");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	boolean = check_line_ants("9394\n");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = check_line_ants("0\n");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	boolean = check_line_ants("HF\n");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_line_ants("5h8G\n");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
}

Test(input_eval, isdigit_to_char_test)
{
	char	*valid_str1;
	char	*invalid_str;
	char	*valid_str;
	t_bool	boolean;

	valid_str = ft_strdup("7478489\n234558");
	valid_str1 = ft_strdup("747848923458");
	invalid_str = ft_strdup("747848H923458");

	boolean = isdigit_to_char(&valid_str, (int)'\n');
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = isdigit_to_char(&valid_str1, (int)'\0');
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = isdigit_to_char(&valid_str, (int)'\0');
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", SUCCESS, FAIL);
	
	boolean = isdigit_to_char(&invalid_str, (int)'\0');
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, SUCCESS);

}

Test(input_eval, isallnum_to_char_test)
{
	char	*valid_str1;
	char	*invalid_str;
	char	*valid_str;
	t_bool	boolean;

	valid_str = ft_strdup("74HF97854h89\n2jfH34558");
	valid_str1 = ft_strdup("7FHG848hd92345r58");
	invalid_str = ft_strdup("74$7848H9]2345[8");

	boolean = isallnum_to_char(&valid_str, (int)'\n');
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = isallnum_to_char(&valid_str1, (int)'\0');
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = isallnum_to_char(&valid_str, (int)'\0');
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", SUCCESS, FAIL);
	
	boolean = isallnum_to_char(&invalid_str, (int)'\0');
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, SUCCESS);

}

Test(input_eval, sink_test)
{
	t_bool boolean;

	boolean = check_link_sink_command("##end");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = check_link_sink_command("## end");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_sink_command("#end");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_sink_command("##END");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_sink_command("");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_sink_command(NULL);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_sink_command("8dG");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_sink_command("end");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

}

Test(input_eval, source_test)
{
	t_bool boolean;

	boolean = check_link_source_command("##start");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = check_link_source_command("## start");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_source_command("#start");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_source_command("##START");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_source_command("");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_source_command(NULL);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_source_command("8dG");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_link_source_command("start");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
}

Test(input_eval, check_line_rooms_test)
{
	t_bool	boolean;

	boolean = check_line_rooms("hDk8g 46 0\n");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	boolean = check_line_rooms("10 43456 848\n");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = check_line_rooms("Jd7Thj 0 674\n");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
}