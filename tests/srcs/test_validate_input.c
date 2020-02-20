/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_validate_input.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:35:37 by mgross         #+#    #+#                */
/*   Updated: 2020/02/20 18:28:23 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <criterion/criterion.h>

Test(input_eval, ants_test)
{
	t_bool boolean;
	boolean = check_num_ants("5");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = check_num_ants("1000");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);

	boolean = check_num_ants("9394");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = check_num_ants("0");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	boolean = check_num_ants("HF");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_num_ants("");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

	boolean = check_num_ants(NULL);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_num_ants("5h8G");
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

// Test(input_eval, isallnum_to_char_test)
// {
// 	char	valid_str[] = "JFh7YJHjdf84ir";
// 	char	valid_str1[] = "JFh7YJH\njdf84ir";
// 	char	invalid_str[] = "74784*3]8923458";
// 	char	*temp;

// 	temp = isallnum_to_char(valid_str, (int)'\0');
// 	cr_assert(temp == valid_str + 14, "The result was %s, expected %s\n", temp, "");
	
// 	temp = isallnum_to_char(valid_str1, (int)'\n');
// 	cr_assert(temp == valid_str1 + 7, "The result was %s, expected %s\n", temp, "\njdf84ir");
	
// 	temp = isallnum_to_char(invalid_str, (int)'\0');
// 	cr_assert(temp == NULL, "The result was %s, expected %s\n", temp, NULL);

// 	temp = isallnum_to_char(valid_str1, (int)'\0');
// 	cr_assert(temp == NULL, "The result was %s, expected %s\n", temp, NULL);
	
// }

Test(input_eval, sink_test)
{
	t_bool boolean;

	boolean = check_sink("##end");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = check_sink("## end");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_sink("#end");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_sink("##END");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_sink("");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_sink(NULL);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_sink("8dG");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_sink("end");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);

}

Test(input_eval, source_test)
{
	t_bool boolean;

	boolean = check_source("##start");
	cr_assert(boolean == SUCCESS, "The result was %d, expected %d\n", boolean, SUCCESS);
	
	boolean = check_source("## start");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_source("#start");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_source("##START");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_source("");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_source(NULL);
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_source("8dG");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
	boolean = check_source("start");
	cr_assert(boolean == FAIL, "The result was %d, expected %d\n", boolean, FAIL);
	
}

// Test(input_eval, check_rooms)
// {
// 	t_bool	boolean;

// 	boolean = check_rooms("hDk8g 46 0");
// }