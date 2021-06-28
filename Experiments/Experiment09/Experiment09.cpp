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

int main() {
    int month, date, year, dayOfTheWeek;
    cout << "Enter a month, date, and year in MM DD YYYY format:" << endl;
    cin >> month >> date >> year;
    isLeapYear(year);
    getCenturyValue(year);
    return 0;
}
bool isLeapYear(int year){
    if((year % 400 == 0) || ((year % 4 == 0) && year % 100 != 0)){
        cout << true;
    }
    else {
        cout << false;
    }
}

int getCenturyValue(int year){
    int century = year/100;
    return (3 - (century % 4)) * 2;
}
int getYearValue(int year){
    int lastTwoDigitsOfYear = year % 100;
    return (lastTwoDigitsOfYear/4 + lastTwoDigitsOfYear);
}

int getMonthValue(int month, int year){
    if(isLeapYear(year) == true){
        switch (month) {
            case 1: return 6; break;
            case 2: return 2; break;
            case 3: return 3; break;
            case 4: return 6; break;
            case 5: return 1; break;
            case 6: return 4; break;
            case 7: return 6; break;
            case 8: return 2; break;
            case 9: return 5; break;
            case 10: return 0; break;
            case 11: return 3; break;
            case 12: return 5; break;
        }
    }
    else{
        switch (month) {
            case 1: return 0; break;
            case 2: return 3; break;
            case 3: return 3; break;
            case 4: return 6; break;
            case 5: return 1; break;
            case 6: return 4; break;
            case 7: return 6; break;
            case 8: return 2; break;
            case 9: return 5; break;
            case 10: return 0; break;
            case 11: return 3; break;
            case 12: return 5; break;
        }
    }
}