/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_validate_input.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:35:37 by mgross         #+#    #+#                */
/*   Updated: 2020/02/19 17:35:39 by mgross        ########   odam.nl         */
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