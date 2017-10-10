/*
** 
** Peter Woodward
** City University
** 
** week 1 and 2
** January 2017
**
** sizing.cpp - program to print of sizes of built-ins
** c++ 11: auto variable, initialisation and narrowing 
** 
** Demonstrates:
**  using namespace
**  declaring, calling and defining functions
**  functions return void  
**  returning value from main
**  using sizeof operator keyword
**
** build and run on cygwin or g++ (mac / linux) with:  
** g++ -std=c++11 -Wno-narrowing sizing.cpp -o sizing && ./sizing
** or 
** build on windows vs2013/15 with : cl sizing.cpp
** 
** To turn off warnings from compiler under g++ use
** -Wno-narrowing
** See discussion at
** https://gcc.gnu.org/wiki/FAQ#Wnarrowing
*/
#include <iostream>
#include <cstdlib> // for exit 
#include <iomanip> // for setw

void run_print_sizes(); // forward declare function
int main()
{
  run_print_sizes();
  return EXIT_SUCCESS;
}

void test_initialisations() // define
{
  // intialialize some stuff, universal initialiser with {}
  bool b{false}; 
  char c{'a'};
  int i{7.2}; 
  // compile error with g++ -Werror
  // as double (7.2) is narrowed into an integer
  int j=7.2;
  auto b2 = true ;
  // auto initialization - can be uses when type can be deduced by initializer.
  // use assignment rather than initialiser (narrowing warnings)
  // see discussion at http://www.stroustrup.com/C++11FAQ.html#auto
  // and at http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n1984.pdf
}
void run_print_sizes() // implementation
{
  using std::cout;
  using std::setfill;
  using std::setw;
  using std::endl;
  using std::left;

  test_initialisations();

  cout << "run_print_sizes()" << endl;

  cout << "One byte objects\n================" << endl;
  
  cout << "\tsizeof " << setfill('.') ;
  cout << setw(22) << left << "bool is " << sizeof(bool) << " byte" << endl;
  cout << "\tsizeof " << setw(22) << left << "signed char is " << sizeof(signed char) << " byte" << endl;
    
  cout << "Two byte objects\n===============" << endl;
  cout << "\tsizeof " << setw(22) << left << "short int is " << sizeof(short int) << " bytes" << endl;

  cout << "Four byte objects\n==================" << endl;
  cout << "\tsizeof " << setw(22) << left << "int is " << sizeof(int) << " bytes" << endl;
  cout << "\tsizeof " << setw(22) << left << "float is " << sizeof(float) << " bytes" << endl;

  cout << "Eight byte objects\n==================" << endl;
  cout << "\tsizeof " << setw(22) << left << "long int is " << sizeof(long int) << " bytes" << endl;
  cout << "\tsizeof " << setw(22) << left << "long long int is " << sizeof(long long int) << " bytes" << endl;
  cout << "\tsizeof " << setw(22) << left << "double is " << sizeof(double) << " bytes" << endl;

  auto ul = 42l; 
  // ul is unsigned long (int)
  // ull is unsigned long long (int)
  // l
  cout << "\tsizeof " << setw(22) << left << "auto ul variable is " << sizeof(ul) << " bytes" << endl;
  auto f = 3.1; 
  // no suffix is plain double = 8 bytes
  // f is float = 4 bytes
  // l is long double = 16 bytes
  cout << "\tsizeof " << setw(22) << left << "auto f variable is " << sizeof(f) << " bytes" << endl;

  cout << "Sixteen byte objects\n====================\n";
  cout << "\tsizeof " << setw(22) << left << "long double is " << sizeof(long double) << " bytes" << endl;
}
