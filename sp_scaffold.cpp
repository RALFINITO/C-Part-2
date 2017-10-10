/*
** sp_scaffold.cpp - scaffolding program to test pointers, arrays, loops and selections
**
** student (development) version
**
** peter woodward
** City University
** week 2 
** January 2017
*/
#include <iostream>

using namespace std;

int countChar(const char*, const char ch=' ');
int sizeString(const char*); // count number of chars, upto but not including null char
int wordString(const char*, const bool debug=true);
bool lowercase(const char c); // return if character is in range 'a' - 'z'
bool uppercase(const char c); // return if character is in range 'A' - 'Z'
int main()
{
  using std::cout;

  char search=' ';
  char mytext[]={" The Quick Brown Fox jumped over the Lazy Cat "};
  cout << "Processing string: \'" << mytext << "\'\n" ;
  cout << "Identified: "  << countChar(mytext) 
       << " count of characters, with value: \'"  << search << "\'\n"; 
  cout << "\nIdentified: " << wordString(mytext,false) << " words\n";

  int lower{0};
  int upper{0};

  for( auto c : mytext ) {
    if( lowercase(c) ) 
      lower++;
    if( uppercase(c) )
      upper++;
  }
  cout << "Identified: " << lower << " lowercase characters\n";
  cout << "Identified: " << upper << " uppercase characters\n";

  return 0;
}

// no function body
int countChar(const char* string, const char ch)
{
  return 0;
}

// no function body
int sizeString(const char* string)
{
  return 0 ;
}



int wordString(const char* string, const bool debug)
{
  return 0;
}

// no function body
// character is in range 'a' - 'z' ?
bool lowercase(const char c)
{
  return true;
}

// no function body
// character is in range 'A' - 'Z' ?
bool uppercase(const char c)
{
  return true;
}
