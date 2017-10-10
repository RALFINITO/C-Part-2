#include <iostream>
// Peter Woodward
// January 2017

/* 
 ** week 2
 ** program to demonstrate use of selections
 ** (a) conditional 3 way operator
 ** (b) if
 ** (c) switch
 */

int main() {
    using std::cout;
    using std::cin;

    // j(31),f(28),m(31),a(30),m(31),j(30),j(31),a(31),s(30),o(31),n(30),d(31)
    int month;
    cout << "Enter month number (1..12): ";
    cin >> month;

    bool valid = (month <= 12 && month >= 1 ? true : false); // ternary selection operator

    if (valid) {
        int days_in_month = 28;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            days_in_month = 31;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            days_in_month = 30;
        } else {
            ; // not required as month is valid here
        }
        std::cout << "There are " << days_in_month << " days in ";

        // switch routing block
        switch (month) { // condition is not boolean, but an integral or enumeration or promotion to either 
            case 1: std::cout << "January";
                break; // note (1) case itself does not alter flow of control, break is required
            case 2: std::cout << "February";
                break; // note (2) case part requires a constant (integral) value or specified promotion
            case 3: std::cout << "March";
                break;
            case 4: std::cout << "April";
                break;
            case 5: std::cout << "May";
                break;
            case 6: std::cout << "June";
                break;
            case 7: std::cout << "July";
                break;
            case 8: std::cout << "August";
                break;
            case 9: std::cout << "September";
                break;
            case 10: std::cout << "October";
                break;
            case 11: std::cout << "November";
                break;
            case 12: std::cout << "December";
                break;
            default:
                ; // not required as month is valid
        }// end of switch
        // break to here, print new line
        cout << "\n";
    } else {
        cout << "Invalid month entered " << month << "\n";
    }
}
