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
    // variable declaration
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
                    break;
    }

    // conditional statement to calculate amount due
    if(standardMinutes > STANDARDLIMIT){
        amountDue += (standardMinutes * STANDARDRATE);
    }
    else if ((premierDayMinutes > PREMIERDAYLIMIT) && (premierNightMinutes > PREMIERNIGHTLIMIT)){
        amountDue += ((premierDayMinutes - PREMIERDAYLIMIT) * PREMIERDAYRATE);
        amountDue += ((premierNightMinutes - PREMIERNIGHTLIMIT) * PREMIERNIGHTRATE);
    }
    else if (premierDayMinutes > PREMIERDAYLIMIT){
        amountDue += ((premierDayMinutes - PREMIERDAYLIMIT) * PREMIERDAYRATE);
    }
    else if (premierNightMinutes > PREMIERNIGHTLIMIT){
        amountDue += ((premierNightMinutes - PREMIERNIGHTLIMIT) * PREMIERNIGHTRATE);
    }

    // set precision of output to two decimal places
    cout << fixed << setprecision(2);

    // display output
    cout << "=========Zippy Sell Phone Company=========" << endl;
    cout << "Account Number: " << setw(15) << accountNumber << endl;
    cout << "Service Type: " << setw(17) << planNameExpanded << endl;

    // depending on plan selected display either daytime/nighttime minutes or just minutes
    switch(plan){
        case 'p':   cout << "Daytime Minutes:" << setw(15) << premierDayMinutes << endl;
                    cout << "Nighttime Minutes:" << setw(13) << premierNightMinutes << endl;
                    break;
        case 's':   cout << "Minutes" << setw(15) << standardMinutes << endl;
                    break;
    }
    cout << "Amount Due: $" << amountDue << endl;


    return 0;
}

/* Sample Execution:
Enter account number and service code <s or p>:
AG-2654 p
Enter daytime minutes:
85
Enter nighttime minutes:
110
=========Zippy Sell Phone Company=========
Account Number:         AG-2654
Service Type:           PREMIER
Daytime Minutes:             85
Nighttime Minutes:          110
Amount Due: $26.50

Process finished with exit code 0
 */
