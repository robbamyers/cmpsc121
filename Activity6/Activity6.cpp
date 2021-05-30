//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    06
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Activity6.cpp
//Purpose: 	        Magic date
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

int main() {
    // variable declaration
    int month, day, year;
    // prompt user
    cout << "Please enter a numeric, month, day and two digit year, separated by spaces:" << endl;

    // read in values from user
    cin >> month >> day >> year;

    // arithmetic
    if (month * day == year){
        cout << "It's a MAGIC date!";
    } else {
        cout << "Sorry! Not a magic date.";
    }

    return 0;
}
