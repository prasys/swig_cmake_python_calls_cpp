#include <stdio.h>

#include <string>

#include "example.h"
thang::thang()
	{
//	puts("thang::thang()");
	}

thang::~thang()
	{
//	puts("thang::~thang()");
	}

int thang::one(void)
	{
//	puts("thang::one()");
	return 1;
	}

std::string thang::echo(std::string message)
	{
//	puts("thang::echo()");
	return message;
	}

thang_data thang::get_data(void)
	{
//	puts("thang::data()");
	thang_data pair;

	pair.x = 2;
	pair.y = 3;

	return pair;
	}

extern "C"
	{
	int factorial(int n)
		{
		if (n <= 1)
			return 1;
		else
			return n * factorial(n - 1);
		}

	int six(void)
		{
		return 6;
		}
	}
