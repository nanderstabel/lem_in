// #include <criterion/criterion.h>
#include "tests.h"
// #include <stdio.h>

// int		hello2(int num);

Test(test2, hello1)
{
	int num;
	char *test;
	num = hello2(30);
	test = ft_itoa(10);
	// printf("%s", test);
	// printf("%i", num);
	cr_assert(num == 30);
}

Test(test2, hello2)
{
	// char *test;

	// test = hello();
	cr_assert_str_eq(hello(), "Hello Worl7d");
}