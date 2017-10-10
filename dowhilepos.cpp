#include <iostream>
// Peter Woodward
// City University
// January 2017

/*
 ** file: dowhilepos.cpp
 ** week: 2
 ** compile: cl /EHsc dowhilepos.cpp
 ** demonstrates: form of the do...while iteration
 ** demonstrates: need to break, on sentinel input, within loop
 ** demonstrates: using && (and) operator
 ** demonstrates: (cin >> n) idiom, handles control-D, control-C, implicitly converted to true if successful read 
 ** demonstrates: conditional operator
 ** demonstrates: ++ post increment operator
 */
int main() {
    //   ** (1) initialization statements, for setting values on startup
    int n;
    long int nchars = 0;
    std::cout << "Enter -1 to exit: ";
    std::cin >> n;
    do {
        if (n == -1) break; // explicit break from loop
        nchars++; // ** (3) continuation (can change continuation status) AFTER
        std::cout << "Number read: " << n << ", enter number: ";
    } while ((std::cin >> n));
    // ** (2) conditional expression for continuation of loop (true / false )  ( 1 or 0 ) BEFORE

    std::cout << "Read: " << nchars
            << " number" << (nchars == 1 ? "" : "s") << std::endl;
}

