// Peter Woodward
// City University
// Week 2
// January 2017
/*
 ** arrayptr.cpp
 ** program to demonstrate use of arrays and pointers
 ** uses two functions to show passing via array and via pointer
 **
 ** build commands
 ** (a) for C style strlen() using #define 
 ** g++ -std=c++11 -D_DO_C_ arrayptr.cpp -o apc && ./apc 
 ** 
 ** (b) for CPP style char_traits::length() using #undef 
 ** g++ -std=c++11 -U_DO_C_ arrayptr.cpp -o apcpp && ./apcpp
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstddef>

void printArrayPtr(const double* p, const int size);
void printArray(const double a[3]);

void printArray(const char*, const int size=0);// overloaded, with char can use null ptr for end
void arraypointers(void);

int main() {
    using std::cout; using std::endl; using std::hex; using std::dec; using std::setw; using std::left;
    double myarray[3], *pa; // three doubles and a pointer to double
    pa = myarray;

    cout << "\tAddress of array, same values\n\t=============================\n";
    cout << setw(32) << left << "Value of myarray: ";
    cout << hex << myarray << endl;

    cout << setw(32) << left << "Value of &myarray: ";
    cout << hex << &myarray << endl;

    cout << setw(32) << left << "Value of &myarray[0]: ";
    cout << hex << &myarray[0] << dec << endl << endl;

    cout << "\tSizes\n\t=====\n";
    cout << setw(16) << left << "sizeof pa:" << '\t' << sizeof (pa) << '\n';
    cout << setw(16) << left << "sizeof &myarray:" << '\t' << sizeof (&myarray) << '\n';
    cout << setw(16) << left << "sizeof myarray[0]:" << '\t' << sizeof (myarray[0]) << '\n';
    cout << setw(16) << left << "sizeof myarray:" << '\t' << sizeof (myarray) << '\n' << '\n';

    myarray[0] = 3.1415926535897932384626433832795; // pi
    myarray[1] = myarray[0] * 2; // pi * 2
    myarray[2] = myarray[0] * myarray[0]; // pi squared

    cout << "\t" << "Access array object through [] and * (show address)\n";
    cout << "\t" << "===================================================\n";

    cout << setw(16) << left << "myarray[0] = " << myarray[0] << '\t'
            << "*(pa + 0) = " << setw(8) << *(pa + 0) << "\t" << hex << pa << endl; /* add one element (8bytes) */
    cout << setw(16) << left << "myarray[1] = " << myarray[1] << '\t'
            << "*(pa + 1) = " << setw(8) << *(pa + 1) << '\t' << hex << pa + 1 << endl; /* add two elements (16bytes) */
    cout << setw(16) << left << "myarray[2] = " << myarray[2] << '\t'
            << "*(pa + 2) = " << setw(8) << *(pa + 2) << '\t' << hex << pa + 2 << endl; /* add one element (8bytes) */

    cout << '\n';
    cout << "\t" << "Change and display array object through * (show address)\n";
    cout << "\t" << "========================================================\n";
    
    *pa++ = 0.0; // change and (post) increment item zero
    *pa = 1.0; // (item 1)
    *++pa = 2.0; // change (pre) increment, (item2) 

    --pa; // reset back 1
    pa--; // reset back 2
   
    cout << setw(16) << left << "myarray[0] = " << myarray[0] << '\t'
            << "*(pa + 0) = " << setw(8) << *(pa + 0) << '\t' << hex << pa << endl; /* add one element (8bytes) */
    cout << setw(16) << left << "myarray[1] = " << myarray[1] << '\t'
            << "*(pa + 1) = " << setw(8) << *(pa + 1) << '\t' << hex << pa + 1 << endl; /* add two elements (16bytes) */
    cout << setw(16) << left << "myarray[2] = " << myarray[2] << '\t'
            << "*(pa + 2) = " << setw(8) << *(pa + 2) << '\t' << hex << pa + 2 << endl; /* add one element (8bytes) */

    myarray[0]=10.11;myarray[1]=20.22;myarray[2]=30.33;

    printArrayPtr(pa,3);
    printArray(myarray);

    // C / C++ char arrays/pointers
    // #define _DO_C_
    cout << "\nManipulating character arrays and pointers"
            "\n==========================================\n";
    arraypointers();
}


void printArrayPtr(const double* p, const int size)
{
  std::cerr << '\n';
  for( int i = 0 ; i < size ; ++i) {
    std::cerr << "element: " << i+1 << ' ' << p[i] << '\n';
  }
}
void printArray(const double a[3])
{
  std::cerr << '\n';
  int i{3};
  while( i-- ) 
    std::cerr << "element: " << i+1 << ' ' << a[i] << '\n';
}

// overloaded, with char can use null ptr for end
void printArray(const char* n, const int size)
{
  std::cerr << "Printing implicitly using null marker: " << n << '\n';
  std::cerr << "Printing explicitly char array, using size: ";
  for(int i=0; i<=size; i++)
    std::cerr << n[i];
  std::cerr << '\n';
}

void arraypointers(void)
{

  char name[6]={'P','e','t','e','r', '\0'};
  char surname[]="Woodward";
  const char* initial=name; // implicit conversion char[] to char*
#ifdef _DO_C_  
  std::cerr << name << ' ' << surname << "\nC-style length: " << strlen(initial) << '\n' ;
#else
  std::cerr << name << ' ' << surname << "\nC++ style length: " << std::char_traits<char>::length(initial)  << '\n' ;
#endif
  char *pname=nullptr;
  //see http://en.cppreference.com/w/cpp/language/value_category

  /* cannot assign to array */
  /* name = pname ; // error unlike conversion of char[] to char*  */

  int len{0};
#ifdef _DO_C_  
  len = strlen(name);
#else
  len = std::char_traits<char>::length(name);
#endif
  printArray(name,len);
}
