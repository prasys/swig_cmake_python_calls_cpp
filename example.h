/*
	EXAMPLE.H
	---------
	Copyright (c) 2021 Andrew Trotman
	Released under the 2-clause BSD license (See:https://en.wikipedia.org/wiki/BSD_licenses)
*/
#pragma once

#include <string>

/*
	CLASS THANG_DATA
	----------------
	Used to demonstrate returning a class object from a method
*/
class thang_data
	{
	public:
		int x;
		int y;
	};

/*
	CLASS THANG
	-----------
*/
class thang
	{
	public:
		/*
			THANG::THANG()
			--------------
			Constructor
		*/
		thang();

		/*
			THANG::~THANG()
			--------------
			Destructor
		*/
		virtual ~thang();

		/*
			THANG::ONE()
			------------
			Always returns 1
		*/
		int one(void);

		/*
			THANG::ECHO()
			-------------
			Always returns its parameter
		*/
		std::string echo(std::string message);

		/*
			THANG::GET_DATA()
			-----------------
			Returns a thang_data object
		*/
		thang_data get_data(void);
	};

extern "C"
	{
	/*
		FACTORIAL()
		-----------
		Returns n factorial
	*/
	int factorial(int n);

	/*
		SIX()
		-----
		Always returns 6.
	*/
	int six(void);
	}
