/* P3:
 * File: calendar.cpp
 * ------------------
 * This file implements the p1calendar.h interface
 */

#include <string>
#include <iostream>
#include <sstream>
#include <map>
//#include "CSC3002OJActive/assignment2/lib.h" // for OJ test
//#include "CSC3002OJActive/assignment2/calendar.h" // for OJ test
//#include "lib.h" // For local test
#include "calendar.h" // For local test
using namespace std;

Month stringToMonth(string s) {
   if (s == "JANUARY") {
      return JANUARY;
   }
   if (s == "FEBRUARY") {
      return FEBRUARY;
   }
   if (s == "MARCH") {
      return MARCH;
   }
   if (s == "APRIL") {
      return APRIL;
   }
   if (s == "MAY") {
      return MAY;
   }
   if (s == "JUNE") {
      return JUNE;
   }
   if (s == "JULY") {
      return JULY;
   }
   if (s == "AUGUST") {
      return AUGUST;
   }
   if (s == "SEPTEMBER") {
      return SEPTEMBER;
   }
   if (s == "OCTOBER") {
      return OCTOBER;
   }
   if (s == "NOVEMBER") {
      return NOVEMBER;
   }
   if (s == "DECEMBER") {
      return DECEMBER;
   }
   return JANUARY; // return January by default
}

/* TODO PART:
 * Implementation notes: monthToString
 * -----------------------------------
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants.  Here, as in the Direction
 * type, the function returns ???.
 */
string monthToString(Month month) {
   map<Month, string> monthStringMap = {
       {JANUARY, "JANUARY"},
       {FEBRUARY, "FEBRUARY"},
       {MARCH, "MARCH"},
       {APRIL, "APRIL"},
       {MAY, "MAY"},
       {JUNE,"JUNE"},
       {JULY, "JULY"},
       {AUGUST, "AUGUST"},
       {SEPTEMBER, "SEPTEMBER"},
       {OCTOBER, "OCTOBER"},
       {NOVEMBER, "NOVEMBER"},
       {DECEMBER, "DECEMBER"}
   };

   if (monthStringMap.count(month)) {
      return monthStringMap[month];
   }
   return "???";
}

/* Implementation: Overloaded Postfix Increment Operator
 * Usage Example:
 *    int j = 3;
 *    int i = j++;
 * Note: i will be assigned the value of j, with j increased by one.
 */
Month operator++(Month &month, int) {
   const int MONTH_COUNT = 12;
   Month original = month;
   int monthTemp = month + 1;
   if (monthTemp == 12) {
      month = static_cast<Month>(monthTemp);
   }
   else {
      month = static_cast<Month>((monthTemp) % MONTH_COUNT);
   }
   return original;
}


Month operator--(Month &month, int) {
   const int MONTH_COUNT = 12;
   Month original = month;
   int monthTemp = month - 1;
   if (monthTemp == 12) {
      month = static_cast<Month>(monthTemp);
   }
   else {
      month = static_cast<Month>((monthTemp) % MONTH_COUNT);
   }
   return original;
}

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Date class.  The default
 * constructor creates a Date with a zero internal value that must
 * be assigned a new value before it is used.  The others initialize
 * the date from the arguments by calling the private initDate method.
 */

Date::Date() {
   initDate(1, JANUARY, 1900);
}

Date::Date(int day, Month month, int year) {
   initDate(day, month, year);
}

Date::Date(Month month, int day, int year) {
   initDate(day, month, year);
}

/*
 * TODO function
 * Implementation notes: getDay, getMonth
 * --------------------------------------
 * 
 */

int Date::getDay() {
   return day;
}

/*
 * TODO function
 * Method: getMonth
 * Usage: Month month = date.getMonth();
 * -------------------------------------
 * Returns the month.
 */

Month Date::getMonth() {
   return month;
}

int Date::getYear() {
   return year;
}


string abbrMonth(Month month) {
   map<Month, string> abbrMonthMap = {
       {JANUARY, "Jan"},
       {FEBRUARY, "Feb"},
       {MARCH, "Mar"},
       {APRIL, "Apr"},
       {MAY, "May"},
       {JUNE, "Jun"},
       {JULY, "Jul"},
       {AUGUST, "Aug"},
       {SEPTEMBER, "Sep"},
       {OCTOBER, "Oct"},
       {NOVEMBER, "Nov"},
       {DECEMBER, "Dec"}
   };

   if (abbrMonthMap.count(month)) {
      return abbrMonthMap[month];
   }
   return "???";
}

/*
 * TODO function
 * Implementation notes: toString
 * ------------------------------
 * The toString method uses the getters to perform the translation into
 * day/month/year values.
 */
string Date::toString() {
   string dateStr;
   dateStr = to_string(getDay()) + "-" + abbrMonth(getMonth()) + "-" + to_string(getYear());
   return dateStr;
}



void Date::initDate(int day, Month month, int yyyy) {
   this->day = day;
   this->month = month;
   this->year = yyyy;
   this->dayInYear = isLeapYear(yyyy) ? 366 : 365;
}

/* Reminder for debugging:
 * The implemetation order of the operator_1:
 * +n, −n, d1−d2, +=, -=, ++, −−
 */

Date operator+(Date date, int delta) {
   // initialize the changing date
   int yearTemp = date.getYear();
   Month monthTemp = date.getMonth();
   int dayTemp = date.getDay();

   if (delta == 0) {
      return date;
   }
   else if (delta > 0) {
      dayTemp += delta;

      // deal with date overflow
      while (dayTemp > daysInMonth(monthTemp, yearTemp)) {
          dayTemp -= daysInMonth(monthTemp, yearTemp);
          monthTemp++;
          if (monthTemp == JANUARY) {
              yearTemp++;
          }
      }
   }
   else {
      throw "Delta should be non-negative.";
      exit(-1);
   }
   return Date(dayTemp, monthTemp, yearTemp);
}


Date operator-(Date date, int delta) {
   // initialize the changing date
   int yearTemp = date.getYear();
   Month monthTemp = date.getMonth();
   int dayTemp = date.getDay();

   if (delta == 0) {
      return date;
   }
   else if (delta > 0) {
      dayTemp -= delta;

      // deal with date overflow
      while (dayTemp < 1) {
          dayTemp -= daysInMonth(monthTemp, yearTemp);
          monthTemp--;
          if (monthTemp < 1) {
              yearTemp--;
              monthTemp = DECEMBER;
          }
          dayTemp += daysInMonth(monthTemp, yearTemp);
      }
   }
   else {
      throw "Delta should be non-negative.";
      exit(-1);
   }
   return Date(dayTemp, monthTemp, yearTemp);
}

int operator-(Date d1, Date d2) {
   if (d1 < d2) {
      throw "The minuend must be larger than subtrahend.";
      exit(-1);
   }
   else if (d1 == d2) {
      return 0;
   }
   else {
      // restore how many days before the specific month, if not leap year
      const int DAYS_OF_MONTH[] =
          {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
      int years = d1.getYear() - d2.getYear();
      int months = DAYS_OF_MONTH[d1.getMonth()] - DAYS_OF_MONTH[d2.getMonth()];
      int days = d1.getDay() - d2.getDay() - 1;

      int totalDays = years*365 + years/4 - years/100 + years/400 + months + days;
      return totalDays;
   }
}

Date &operator+=(Date &date, int delta) {
   date = date + delta; // modify date with overloaded +
   return date;
}

Date &operator-=(Date &date, int delta) {
   date = date - delta; // modify date with overloaded -
   return date;
}

Date operator++(Date &date) {
   date = date + 1;
   return date;
}

Date operator++(Date &date, int) {
   Date originDate = date;
   date = date + 1;
   return originDate;
}

Date operator--(Date &date) {
   date = date - 1;
   return date;
}

Date operator--(Date &date, int) {
   Date originDate = date;
   date = date - 1;
   return originDate;
}

/* Reminder for debugging:
 * The implemetation order of the operator_2:
 * ==, !=, <, <=, >, >=
 */

bool operator==(Date d1, Date d2) {
   if (d1.getYear() == d2.getYear() &&
       d1.getMonth() == d2.getMonth() &&
       d1.getDay() == d2.getDay() ) {
      return true;
   }
   return false;
}

bool operator!=(Date d1, Date d2) {
   if (!(d1 == d2)) {
      return true;
   }
   return false;
}

bool operator<(Date d1, Date d2) {
   // Compare the dates by year, by month and by day.
   if (d1.getYear() < d2.getYear()) {
      return true;
   }
   if (d1.getYear() == d2.getYear() && d1.getMonth() < d2.getMonth()) {
      return true;
   }
   if (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() < d2.getDay()) {
      return true;
   }

   return false;
}

bool operator<=(Date d1, Date d2) {
   if (d1 < d2 || d1 == d2) {
        return true;
   }
   return false;
}

bool operator>(Date d1, Date d2) {
   if (!(d1 == d2) && !(d1 < d2)) {
        return true;
   }
   return false;
}

bool operator>=(Date d1, Date d2) {
    if (d1 > d2 || d1 == d2) {
      return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, Date date){
    os << date.toString(); // output the date in a friendly way
    return os;
}

/*
 * TODO function
 * Implementation notes: daysInMonth
 * ---------------------------------
 * This function is a reasonably literal translation of the old rhyme:
 *
 *    Thirty days has September
 *    April, June, and November
 *    All the rest have 31
 *    Excepting February alone
 *    Which has 28 in fine
 *    And each leap year 29
 */

int daysInMonth(Month month, int year) {
    switch (month) {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return 31;
            break;

        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
            break;

        case FEBRUARY:
            if (isLeapYear(year)) {
                return 29;
            }
            return 28;
      };
    return 0;
}

/* TODO PART:
 * Implementation notes: isLeapYear
 * --------------------------------
 * This function simply encodes the rule for determining leap years:
 * a leap year is any year divisible by 4, except for years ending in 00,
 * in which case the year must be divisible by 400.
 */

bool isLeapYear(int year) {
   // For the ending with 00 case, divisible by 400
   if (year % 100 == 0) {
      if (year % 400 == 0) {
          return true;
      }
      return false;
   }

   // For others, divisible by 4
   else {
      if (year % 4 == 0) {
          return true;
      }
      return false;
   }
}

/* DO NOT modify this main() part */
int main()
{
   int id;
   cin >> id;
   int day, year;
   string mon;
   cin >> day >> mon >> year;

   if (id == 1)
   {
      for (Month month = JANUARY; month <= DECEMBER; month = Month(month + 1))
      {
         cout << monthToString(month) << " has " << daysInMonth(month, year)
              << " days." << endl;
      }
   }
   else if (id == 2)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding.toString() << endl;
   }
   else if (id == 3)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cin >> mon >> day >> year;
      Date kennedyAssassination(stringToMonth(mon), day, year);
      cin >> mon >> day >> year;
      Date newYearsEve(stringToMonth(mon), day, year);
      cin >> day >> mon >> year;
      Date inaugurationDay(day, stringToMonth(mon), year);
      cin >> day >> mon >> year;
      Date electionDay(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding << endl;
      cout << "kennedyAssassination = " << kennedyAssassination << endl;
      cout << boolalpha;
      cout << "moonLanding < kennedyAssassination = "
           << (moonLanding < kennedyAssassination) << endl;
      cout << "moonLanding > kennedyAssassination = "
           << (moonLanding > kennedyAssassination) << endl;
      cout << "moonLanding == kennedyAssassination = "
           << (moonLanding == kennedyAssassination) << endl;
      cout << "moonLanding == moonLanding = "
           << (moonLanding == moonLanding) << endl;
      cout << "inaugurationDay - electionDay = "
           << (inaugurationDay - electionDay) << endl;
      Date day = newYearsEve;
      cout << "New Year's Eve = " << day++ << endl;
      cout << "New Year's Day = " << day << endl;
      for (Date d = electionDay; d <= inaugurationDay; d++)
      {
         cout << d << endl;
      }
   }
   return 0;
}
