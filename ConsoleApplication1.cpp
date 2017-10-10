// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iostream>




int main()
{
	using std::cout;
	using std::cin;
	using std::endl; // end of line
	using std::string;

	

	int a = 1 ;
	size_t b = sizeof(a);
	cout << "\n" << "Size of int is = " << b << endl;


	string arrMonths[12] = {"Jan","Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	cout << "\n" << endl;
	for (int i = 0; i < 12; i++) {
		cout << arrMonths[i] << " = " << i + 1 << endl;
	}

    return 0;
}

