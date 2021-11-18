/*
	EXAMPLE.H
	---------
	Copyright (c) 2021 Andrew Trotman
	Released under the 2-clause BSD license (See:https://en.wikipedia.org/wiki/BSD_licenses)
*/
/*!
@file
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
/*!
	@class thang
	@brief Example C++ class showing SWIG, cmake and C++ integration.
*/
class thang
	{
	public:
		/*
			THANG::THANG()
			--------------
		*/
		/*!
			@brief Constructor
		*/
		thang();

		/*
			THANG::~THANG()
			--------------
		*/
		/*!
			@brief Destructor
		*/
		virtual ~thang();

		/*
			THANG::ONE()
			------------
		*/
		/*!
			@brief Always return 1.
			@return 1
		*/
		int one(void);

		/*
			THANG::ECHO()
			-------------
			Always returns its parameter
		*/
		/*!
			@brief Always return the parameter (example of string handling)
			@param message [in] The string to return
			@return Returns a copy of the parameter
		*/
		std::string echo(std::string message);

		/*
			THANG::GET_DATA()
			-----------------
			Returns a thang_data object
		*/
		/*!
			@brief Example method that returns an object
			@return a thang_data object
		*/
		thang_data get_data(void);
	};

extern "C"
	{
	/*
		FACTORIAL()
		-----------
	*/
	/*!
		@brief Factorial of n
		@param n [in] The number from which to compute n!
		@return n!
	*/
	int factorial(int n);

	/*
		SIX()
		-----
	*/
	/*!
		@brief Always return 6.
		@return 6
	*/
	int six(void);
	}
