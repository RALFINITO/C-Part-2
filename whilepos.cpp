#include <iostream>
// Peter Woodward
// City University
// January 2017
/*
** file: whilepos.cpp
** week: 2/3
** compile: cl /EHsc whilepos.cpp
** demonstrates: form of while iteration
** demonstrates: using && (and) operator
** demonstrates: (cin >> n) idiom, handles control-D, control-C, implicitly converted to T if successful read 
** demonstrates: conditional operator
** demonstrates: ++ post increment operator
*/
int main()
{
  using std::cout;
  using std::cin;
  using std::endl;
  // ** (1) initialization statement (or null), for setting values on startup
  int n;
  long int nchars=0;

  cout << "Enter -1 to exit: ";
  while( (cin >> n) && ( n != -1)   ) { // (2) conditional expression for continuation of loop (true / false )  ( 1 or 0 ) BEFORE
    nchars++;  // ** (3) continuation (can change continuation status) AFTER
    cout << "Number read: " << n << ", enter number: ";
  }
  cout << "Read: " << nchars << " number" << ( nchars == 1 ? "" : "s" ) << endl;
}

