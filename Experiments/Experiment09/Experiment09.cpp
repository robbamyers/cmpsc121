//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        09
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment09/Experiment09.cpp
//Purpose: 	        This experiment is designed to develop confidence with functions.
/********************************************************************\
* Academic Integrity Affidavit:                                      *
*                                                                    *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me. I understand that submitting code which is totally  *
* or partially the product of other individuals is a violation of the*
* Academic Integrity Policy and accepted ethical precepts. Falsified *
* execution results are also results of improper activities. Such    *
* violations may result in zero credit for the assignment, reduced   *
* credit for the assignment, or course failure.                      *
\********************************************************************/
// Sources of logic assistance: None
#include <iostream>
using namespace std;

// function prototypes
bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
string convertDayOfWeek(int numericDayOfWeek);

int main() {
    // main scope variable declaration
    int month, day, year, numericDayOfWeek;
    string dayOfWeek;
    char continuation;
    do {
        // prompt user and read in values
        cout << "Please enter a date in the format MM DD YYYY" << endl;
        cin >> month >> day >> year;
        // calculate numeric day of the week 0-6
        numericDayOfWeek = (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7;
        // convert numeric day of the week to string day of week
        cout << month << "/" << day << "/" << year << " is a " << convertDayOfWeek(numericDayOfWeek) << endl;
        // prompt user to continue entering dates and read in decision
        cout << "Do you wish to enter another date? Y or N" << endl;
        cin >> continuation;
    }while(toupper(continuation) == 'Y');
    return 0;
}
// determine if year leap year
bool isLeapYear(int year){
    if((year % 400 == 0) || ((year % 4 == 0) && year % 100 != 0)){
        return true;
    }
    else {
        return false;
    }
}
// convert year to century value
int getCenturyValue(int year){
    int century = year/100;
    int remainder = century % 4;
    int centuryValue = (3 - remainder) * 2;
    return centuryValue;
}
// convert year to year value using last two digits
int getYearValue(int year){
    int lastTwoDigitsOfYear = year % 100;
    int yearValue = lastTwoDigitsOfYear / 4 + lastTwoDigitsOfYear;
    return yearValue;
}
// calculate month vsalue based on leap year
int getMonthValue(int month, int year){
    int monthValue;
    if(isLeapYear(year) == true){
        switch (month) {
            case 1: monthValue = 6; break;
            case 2: monthValue = 2; break;
            case 3: monthValue = 3; break;
            case 4: monthValue = 6; break;
            case 5: monthValue = 1; break;
            case 6: monthValue = 4; break;
            case 7: monthValue = 6; break;
            case 8: monthValue = 2; break;
            case 9: monthValue = 5; break;
            case 10: monthValue = 0; break;
            case 11: monthValue = 3; break;
            case 12: monthValue = 5; break;
        }
    }
    else{
        switch (month) {
            case 1: monthValue = 0; break;
            case 2: monthValue = 3; break;
            case 3: monthValue = 3; break;
            case 4: monthValue = 6; break;
            case 5: monthValue = 1; break;
            case 6: monthValue = 4; break;
            case 7: monthValue = 6; break;
            case 8: monthValue = 2; break;
            case 9: monthValue = 5; break;
            case 10: monthValue = 0; break;
            case 11: monthValue = 3; break;
            case 12: monthValue = 5; break;
        }
    }
    return monthValue;
}
// convert numeric day of the week to string weekday
string convertDayOfWeek(int numericDayOfWeek){
    switch (numericDayOfWeek) {
        case 0: return "Sunday"; break;
        case 1: return "Monday"; break;
        case 2: return "Tuesday"; break;
        case 3: return "Wednesday"; break;
        case 4: return "Thursday"; break;
        case 5: return "Friday"; break;
        case 6: return "Saturday"; break;
    }
}