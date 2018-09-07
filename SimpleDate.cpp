//
// Created by Ryan Eisenbarth on 9/7/17.
//

#include <stdexcept>
#include "SimpleDate.h"
#include <string>
#include<iostream>


const int SimpleDate::MIN_YEAR = 1753;
const int SimpleDate::NUM_MONTHS = 12;
const int SimpleDate::DAYS_IN_MONTH[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int SimpleDate::DAYS_THUS_FAR[] ={0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};



SimpleDate::SimpleDate(int month, int day, int year){
    this->month = month;
    this->day = day;
    this->year = year;

    if(!isValidDate(month, day, year)){
        throw std::invalid_argument("invalid values for fields");
    }
}

SimpleDate::SimpleDate(){
}

int SimpleDate::getMonth() const {
    return this->month;
}
int SimpleDate::getDay() const {
    return this->day;
}
int SimpleDate::getYear() const {
    return this->year;
}

int SimpleDate::compareTo(SimpleDate other) {
    if (this->year != other.getYear()){
        return this->year - other.getYear();
    }
    if (this->month != other.getMonth()){
        return this->month - other.getMonth();
    }
    return this->day - other.getDay();
}

int SimpleDate::dayOfWeek(){
    int daysElapsed = 0;
    for (int year = MIN_YEAR; year < this->year; year++)
        daysElapsed += daysInYear(year);
    daysElapsed += ordinalDate();

    return daysElapsed % 7;
}
int SimpleDate::daysInYear(int year) {
    return isLeapYear(year) ? 366 : 365;
}
SimpleDate SimpleDate::daysFromNow(int n) {
    if (n == 0) {
        std::cout<< month + " month / " + day;
        std::cout<<" day / " + year << endl;
        return SimpleDate(month, day, year);
    }

    SimpleDate date;// = SimpleDate(month, day, year);

    if (n < 0) {
        throw std::invalid_argument("n can't be negative");
    } else {
        date = nextDate();
        for (int i = 1; i < n; i++)
            SimpleDate(month, day, year) = date.nextDate();
    }
    if (date.getYear() < MIN_YEAR)
        throw std::invalid_argument("Resulting date is before 1/1/1753");
    std::cout<< month + " / " ;
    std::cout<< day + " / " + year << endl;
    return SimpleDate(month, day, year);
}
bool SimpleDate::isLeapYear() {
    return isLeapYear(year);
}
bool SimpleDate::isLeapYear(int year) {
    bool leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    return leap;
}
int SimpleDate::ordinalDate() {
    int answer = DAYS_THUS_FAR[month] + day;
    if (isLeapYear() && month > 2)
        answer++;
    return answer;
}
bool SimpleDate::isValidDate(int month, int day, int year) {
    if (month < 1 || month > NUM_MONTHS)
        return false;
    if (day < 1 || day > daysInMonth(month, year))
        return false;
    return year >= MIN_YEAR;
}
int SimpleDate::daysInMonth(int month, int year) {
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return DAYS_IN_MONTH[month];
}
SimpleDate SimpleDate::nextDate() {
    SimpleDate next;

    // handle 31-day months
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10) {
        if (day < 31) {
            next = SimpleDate(month, day + 1, year);
        } else {
            next = SimpleDate(month + 1, 1, year);
        }
    }

    // handle 30-day month
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 30) {
            next = SimpleDate(month, day + 1, year);
        } else {
            next = SimpleDate(month + 1, 1, year);
        }
    }

    // handle February month
    if (month == 2) {
        if (day < 28) {
            next = SimpleDate(month, day + 1, year);
        } else {
            if (isLeapYear()) {
                next = SimpleDate(month, day + 1, year);
            } else {
                next = SimpleDate(month + 1, 1, year);
            }
        }
    }

    // handle December month
    if (month == 12) {
        if (day < 31) {
            next = SimpleDate(month, day + 1, year);
        } else {
            next = SimpleDate(1, 1, year + 1);
        }
    }

    return next;
}