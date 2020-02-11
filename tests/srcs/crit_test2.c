#include "tests.h"

Test(test1, hello1)
{
	int num;
	char *test;
	num = hello2(10);
	test = ft_itoa(10);
	cr_assert(num == 30);
}

Test(test1, hello2)
{
	char *test;

	test = hello();
	cr_assert_str_eq(hello(), "Hello World");
}