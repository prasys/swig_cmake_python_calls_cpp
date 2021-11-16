/* File : example.i */
%module example
%include "std_string.i"
%{
	#include "example.h"
%}

class thang_data
	{
	public:
		int x;
		int y;
	};

class thang
	{
	public:
		thang();
		virtual ~thang();

		int one(void);
		std::string echo(std::string message);
		thang_data get_data(void);
	};

extern "C"
	{
	int factorial(int n);
	int six(void);
	}
