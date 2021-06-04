//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        05
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment05-01/Experiment05-01cpp
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
#include <string>
using namespace std;

const double STANDARDPRICE = 12.00, PREMIERPRICE = 25.00,
             STANDARDRATE = 0.20, PREMIERDAYRATE = 0.10, PREMIERNIGHTRATE = 0.05;
const int STANDARDLIMIT = 60, PREMIERDAYLIMIT = 75, PREMIERNIGHTLIMIT = 100;

int main() {
    // variable delcaration
    string accountNumber;
    string planNameExpanded;
    char plan;
    int standardMinutes = 0, premierDayMinutes = 0, premierNightMinutes = 0;
    double amountDue = 0;

    // prompt and read in values from user
    cout << "Enter account number and service code <s or p>:" << endl;
    cin >> accountNumber >> plan;

    // validate user input
    while(!(plan == 'p' || plan == 's')){
        cout << "Not a valid plan. Please re-enter your service code <s or p>:" << endl;
        cin >> plan;
    }

    // conditionally assign the full name of the plan based on user input
    if(plan == 'p'){
        planNameExpanded = "PREMIER";
    }
    else if(plan == 's'){
        planNameExpanded = "STANDARD";
    }

    // prompt user conditionally based on plan type
    switch(plan){
        case 's':   cout << "Enter minutes used:" << endl;
                    cin >> standardMinutes;
                    amountDue = STANDARDPRICE;
                    break;
        case 'p':   cout << "Enter daytime minutes:" << endl;
                    cin >> premierDayMinutes;
                    cout << "Enter nighttime minutes:" << endl;
                    cin >> premierNightMinutes;
                    amountDue = PREMIERPRICE;
    }

    if(standardMinutes > STANDARDLIMIT){
        amountDue += (standardMinutes * STANDARDRATE);
    }
    else if (premierDayMinutes > PREMIERDAYLIMIT){
        amountDue += (premierDayMinutes * PREMIERDAYRATE);
    }
    else if (premierNightMinutes > PREMIERNIGHTLIMIT){
        amountDue += (premierNightMinutes * PREMIERNIGHTRATE);
    }

    cout << fixed << setprecision(2);
    cout << "=========Zippy Sell Phone Company=========" << endl;
    cout << "Account Number: " << accountNumber;
    cout << "Service Type: " << planNameExpanded << endl;
    switch(plan){
        case 'p':   cout << "Daytime Minutes:" << setw(15) << premierDayMinutes << endl;
                    cout << "Nighttime Minutes:" << setw(15) << premierNightMinutes << endl;
        case 's':   cout << "Minutes" << setw(15) << standardMinutes << endl;
    }
    cout << "Amount Due: $" << amountDue << endl;


    return 0;
}


