//
// Created by Ryan Eisenbarth on 9/7/17.
//

#ifndef HW01_DATE_SIMPLEDATE_H
#define HW01_DATE_SIMPLEDATE_H


#include <stdexcept>
using namespace std;

class SimpleDate {
public:
    static const int MIN_YEAR;

    SimpleDate(int month, int day, int year);

    SimpleDate();

    int getMonth() const;

    int getDay() const;

    int getYear() const;

    int compareTo(SimpleDate other);

    int dayOfWeek();

    SimpleDate daysFromNow(int n);

    bool isLeapYear() ;

    static bool isLeapYear(int year);

    int ordinalDate();



private:
    static const int NUM_MONTHS;
    static const int DAYS_IN_MONTH[];
    static const int DAYS_THUS_FAR[];

    //month of date
    int month;

    //day of date
    int day;

    //year of date
    int year;

    int daysInYear(int year);

    static bool isValidDate(int month, int day, int year);

    static int daysInMonth(int month, int year);

    SimpleDate nextDate();


};


#endif //HW01_DATE_SIMPLEDATE_H
