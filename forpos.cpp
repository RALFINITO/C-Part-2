#include <iostream>
// Peter Woodward
// City University
// January 2017

/*
 ** file: forpos.cpp
 ** week: 2
 ** compile: cl /EHsc forpos.cpp
 ** compile: g++ -std=c++11 forpos.cpp 
 ** demonstrates: : the syntaxx of the for iteration
 ** demonstrates: using && (and) operator, and not equal operator
 ** demonstrates: (cin >> n) idiom, handles control-D, control-C, implicitly converted to true if successful read 
 ** demonstrates
 ** demonstrates: conditional operator
 ** demonstrates: ++ post increment operator
 */
int main() {
    using std::cout;
    int n;
    long int nchars = 0;
    /*
     ** (1) initialization statement (or null), for setting values on startup
     ** (2) conditional expression for continuation of loop (true / false )  ( 1 or 0 ) BEFORE
     ** (3) continuation (can change continuation status) AFTER
     */
    for (std::cout << "Enter -1 to exit: "; (std::cin >> n) && (n != -1); nchars++) {
        std::cout << "Number read: " << n << ", enter number: ";
    }
    std::cout << "Read: " << nchars << " number" << (nchars == 1 ? "" : "s") << std::endl;
}

