#include "tests.h"

Test(test2, hello1)
{
	int num;
	char *test;
	num = hello2(30);
	test = ft_itoa(10);
	cr_assert(num == 30);
	
}

Test(test2, hello2)
{
	cr_assert_str_eq(hello(), "Hello Worl7d");
}

Test(input_val, empty_file)
{

}