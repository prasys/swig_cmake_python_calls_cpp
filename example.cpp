/*
	EXAMPLE.CPP
	-----------
	Copyright (c) 2021 Andrew Trotman
	Released under the 2-clause BSD license (See:https://en.wikipedia.org/wiki/BSD_licenses)
*/
#include <stdio.h>

#include <string>

#include "example.h"

/*
	THANG::THANG()
	--------------
*/
thang::thang()
	{
//	puts("thang::thang()");
	}

/*
	THANG::~THANG()
	---------------
*/
thang::~thang()
	{
//	puts("thang::~thang()");
	}

/*
	THANG::ONE()
	------------
*/
int thang::one(void)
	{
//	puts("thang::one()");
	return 1;
	}

/*
	THANG::ECHO()
	-------------
*/
std::string thang::echo(std::string message)
	{
//	puts("thang::echo()");
	return message;
	}

/*
	THANG::GET_DATA()
	-----------------
*/
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
	/*
		FACTORIAL()
		-----------
	*/
	int factorial(int n)
		{
		if (n <= 1)
			return 1;
		else
			return n * factorial(n - 1);
		}

	/*
		SIX()
		-----
	*/
	int six(void)
		{
		return 6;
		}
	}
