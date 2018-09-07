#include <iostream>
#include "Simpledate.h"
using namespace std;

int main() {

    SimpleDate s = SimpleDate(1, 1, 1885);
    cout << "This is the day of the week in int form: ";
    cout << s.dayOfWeek() << endl;
    cout << "This is a leap year 1 is true and 0 is false: ";
    cout << s.isLeapYear() << endl;
    cout << "How many days since Jan 1: ";
    cout << s.ordinalDate() << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}