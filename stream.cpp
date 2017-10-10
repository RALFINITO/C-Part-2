#include <iostream>
#include <iomanip>
/*
 ** file: stream.cpp
 ** January 2017
 ** 
 ** demonstrates: cout format flags setting as functions (width,precision,fill etc.)
 ** demonstrates: fill / width DOES revert
 ** demonstrates: precision DOES NOT revert
 ** demonstrates: saving and restoring flags using flags (stored in type) 
 **               get with flags() and set with setf()
 ** demonstrates: using decimal  / hexadecimal formatting manipulators as global functions hex / dec
 **               see io manipulators (iomanip)
 ** demonstrates: cin to reading numbers and rdstate, test for failing
 **               use control-c or control-d to interrupt
 ** 
 ** demonstrates: endl, and ios base formatting, and showbase
 **
 */

int main(int argc, char* argv[])
{
  using std::cout;
  using std::cin;
  using std::endl; // end of line
  using std::oct; // base 8
  using std::dec; // base 10
 
  cout << "Display stored stream settings" << endl;

  int w = 25; // c++98 style intialisation
  
  cout << "std::cout.width()      = " << cout.width() << endl; cout.width(w);
  cout << "std::cout.precision()  = " << cout.precision() << endl; cout.width(w);
  cout << "std::cout.fill()       = " << '[' << cout.fill() << ']' << endl; cout.width(w);
  if(cout.good()) { // stream has goodbit set
    cout << "cout is good: cout.flags()      = " << oct << cout.flags() << endl;
  }
    

  // filling and field width
  cout << "\n\nDisplay fill characters and field width, then revert" << endl;
  cout.fill('#'); // set fill character to # 
  cout.width(40); // set field width to 40
  cout << "Hello World." << endl;
  cout << "Hello World." << endl; // note fill/width are reverted

  // precision
  cout << "\n\nDisplay double precision, then explicitly reset" << endl;
  double pi = 3.14159265358979323846; // to 20 dp
  cout.precision(2); // shows maximum number of digits displayed for float/doubles
  /*
  ** using floating point format, write fixed-point notation
  */
  cout.setf(std::ios::fixed, std::ios::floatfield); // specify fixed precision
  cout << "pi = " << pi << endl;

  cout.precision(15); // shows maximum number of digits displayed for float/doubles
  cout << "pi = " << pi << endl;

  cout.precision(20); // shows maximum number of digits displayed for float/doubles
  cout << "pi = " << pi << endl;
  cout << "pi = " << pi << endl; // note precision not reverted
  cout.precision(6);
  cout << "pi = " << pi << endl;

  cout.precision(2);
  /*
  ** using floating point format, write scientific notation
  */
  cout.setf(std::ios::scientific, std::ios::floatfield); // specify scientific format
  cout << "pi = " << pi << endl;

  //  set and restore
  cout << "\n\nStore specific format settings (octal and uppercase)" << endl;
  int n = 16;
  /*
  ** store specific format setting here ( using format flags )
  */
  std::ios_base::fmtflags formatf =
    std::cout.flags(std::ios::oct | std::ios::uppercase); // save, a specific setting (OCTAL / UPPERCASE)

  // send output proceeded as base 10 (dec)
  cout << "Showing output in 3 different formats: denary, hexadecimal and octal\n";
  cout.fill(' '); // set fill back to space character 
  cout.width(10);
  cout << "base 10: ";
  cout << std::showbase << dec << n << endl;
  /*
  ** use hexadecimal format, and preceed with base 
  */
  cout.flags(std::ios::hex | std::ios::showbase); // set flags
  cout.width(10);
  cout << "base 16: ";
  cout << std::showbase << n << endl;

  cout.flags(formatf); // apply stored flag (octal)
  cout.width(10);
  cout << "base 8: ";
  cout << std::showbase << n << endl;

  cout << "\n\nShow left and right justification" << endl;
  // left/right justify
  cout.fill('~'); // set fill character to ~
  cout.width(40); // set field width to 40
  cout.flags(std::ios::left); //left padded to 40, with fill chars, appended to end 

  cout << "Hello World" << endl;

  cout.fill('_'); // set fill character to _
  cout.width(40); // set field width to 40
  cout.flags(std::ios::right); //right pad to 40, with fill added at beginning

  cout << "Hello World" << endl;

  // use put output
  cout << "\nDemonstrate ostream put member function\n";
  cout.put(65); // convert 65 int from ascii into char value
  cout.put('B'); // produce as char

  // test read state
  cout << "\n\nTest stream input field state" << endl;
  cout << "Enter Integer (pass) or Interrupt (fail) " << endl;
  cout << "cin.rdstate()  = " << cin.rdstate() << endl;
  /* int n = -1 ; // old style */

  int p{-1}; // c++-11 style, initialisation 

  long double d{0.0};
    
  if( cin.good() ) {
    cout << "cin state is good to read, now enter integer: " ;
    cin >> p;
    if (!cin.fail()) {
      cout << "Successfull read of (integer) Value Read: " << p << endl;

      { // no read off float
     
	cout.precision(4);
	cout << "Testing reading a double\nEnter a double precision floating point number: ";
	if (cin >> d) { // 
	  cout << "Success, you entered: " << d << endl;
	} else {
	  cout << "Error on read : " << d << endl;
	}
      }
	
    } else {
      cout << "Unsuccessfull read" << endl;
    }
  }

  d = 3.1415926535; // assign to pi value, prior to truncate
  int i = d; // truncate without warning

  cout << "Demonstrate truncation (double d: " << d << ")\n(integer i: " << i << ")" << endl;
}
