//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        05
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment05/Experiment05.cpp
//Purpose: 	        This experiment is designed to develop confidence with selection logic and debugging.
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
#include <iomanip>
using namespace std;
const int LT20 = 20;
const double LT20Charge = 0.10;
const int LT40 = 40;
const double LT40Charge = 0.08;
const int LT60 = 60;
const double LT60Charge = 0.06;
const double GTE60Charge = 0.04;
const double BALANCELIMIT = 400.00;
const double LOWBALANCECHARGE = 15.00;

int main() {
    // variable declaration
    int numberOfChecks;
    bool isUnder = false;
    double balance, serviceFee = 0;

    // set precision to two decimal places
    cout << fixed << setprecision(2);
    // prompt user
    cout << "Please enter beginning balance and number of checks written" << endl;
    // read in values from user
    cin >> balance >> numberOfChecks;

    // check if balance is under 400, if so incur a low balance charge
    if (balance < BALANCELIMIT) {
        serviceFee += LOWBALANCECHARGE;
        isUnder = true;
    }

    // check the number of checks written and add fees based on 20,40,60 thresholds to serviceFee var
    if (numberOfChecks < LT20){
        serviceFee += (LT20Charge * numberOfChecks);
    }
    else if (numberOfChecks < LT40){
        serviceFee += (LT40Charge * numberOfChecks);
    }
    else if (numberOfChecks < LT60){
        serviceFee += (LT60Charge *numberOfChecks);
    }
    else{
        serviceFee += (GTE60Charge * numberOfChecks);
    }

    // display balance to user
    cout << "MEGABUX Bancorp" << endl;
    cout << "Your balance was $" << balance << endl;

    // conditionally display the low balance portion of the receipt if balance was under 400
    if (isUnder){
        cout << "You did not maintain the minimum balance!"  << endl;
        cout << "You incurred a low balance fee of $" << LOWBALANCECHARGE << endl;
    }

    //display total service charge which is combination of check fees and low balance fees
    cout << "Total service Charge is $" << serviceFee << endl;
}

/* Sample Execution:
Please enter beginning balance and number of checks written
401 38
MEGABUX Bancorp
Your balance was $401.00
Total service Charge is $3.04

Process finished with exit code 0
 */