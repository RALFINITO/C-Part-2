#include <iostream>
#include <cstdlib>
/*
** January 2017
** Week: 1
** File: conversion.cpp
**       convert between inches and centimetres
**       input number, followed by 'i' for inch (to cent. conversion)
**       or by 'c' for centimetre (to inch conversion)
**
**       based on Stroustrup (C++ Prog Language, 2nd Ed.) 
**
** g++ build:
** g++ -std=c++11 conversion-2.cpp -o conv
**
** demonstrates: 
** mac version, uses char array, cin.get, isalpha function, extract conversion character (i or c)
** then truncates string, at character and converts to float using atof
** 
** declaration of float and boolean types
** introducing selection (if) 
** logical operators: negation unary operator ! and binary OR operator || 
** reading input from input stream (cin channel)
**
*/

int main(int argc, char* argv[])
{
  using std::cin;
  using std::cerr;
  using std::cout;
  using std::endl;

  double fac{ 2.54 }; // or use auto conversion factor
  // prompt user
  cout << "Input number followed by i for inch input, c for centimetres input\n";
  cout << "Enter length: ";

  char conv{'i'}; 
  double x;
  char inp[32];

  cin.get(inp,32,'\n'); // read off array, terminated by newline

  if(cin) {
    int count=cin.gcount();
    cerr << "READ: " << count << " CHARS: " << inp << "\n";
    for(int i=0; i < count ; i++ ) {
      if(isalpha(inp[i])) {// found alpha char
	if(inp[i] == 'c' || inp[i] == 'C')
	  conv = 'c';
	else if(inp[i] == 'i' || inp[i] == 'I')
	  conv = 'i';
	else
	  return(EXIT_FAILURE); //return -1;
		
	// terminate string
	inp[i]='\0';
	x = atof(inp); // convert
	      
      }else{ // ignore
	; 
      }
	    
    }// for loop
  }else{ // error on cin
    cerr << "Error reading input\n";
    return(EXIT_FAILURE);
  }
	
  // do calculations
  double in{ 0.0 }, cm{ 0.0 }; // closest to point of use
  switch (conv) { // try for upper case, try with an if
  case('i') :  // inch, convert to centimetres
    in = x;
    cm = x * fac;
    cout << in << " inches = " << cm << " centimetres\n";
    break;
  case('c') :  // centimetres, convert to inch
    in = x / fac;
    cm = x;
    cout << cm << " centimetres = " << in << " inches\n";
    break;
  }
  return(EXIT_SUCCESS);
}
