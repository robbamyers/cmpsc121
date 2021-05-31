//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    07
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity7/Activity7.cpp
//Purpose: 	        Using if/else statements to display conditional results
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
const double PACKAGE_A_RATE = 39.99, PACKAGE_B_RATE = 59.99, PACKAGE_C_RATE = 69.99,
             PACKAGE_A_PER_MINUTE = 0.45, PACKAGE_B_PER_MINUTE = 0.40;
const int PACKAGE_A_LIMIT = 450, PACKAGE_B_LIMIT = 900;

int main() {
    // variable declaration
    char planSelection;
    double minutesUsed;
    double minuteOverageCharge = 0;
    double total;

    cout << fixed << setprecision(2);
    // prompt user
    cout << "Enter Plan <A, B or C> and number of minutes used this month." << endl;

    // read in values
    cin >> planSelection >> minutesUsed;

    // conditional based on user selection
    if (planSelection == 'A') {
        cout << "For Package A with " << minutesUsed << " minutes of usage, your bill is:" << endl;
        if (minutesUsed > PACKAGE_A_LIMIT) {
            minuteOverageCharge = (minutesUsed - PACKAGE_A_LIMIT) * PACKAGE_A_PER_MINUTE;
        }
        total = minuteOverageCharge + PACKAGE_A_RATE;
        cout << "$" << total;
    }
    else if (planSelection == 'B') {
        cout << "For Package B with " << minutesUsed << " minutes of usage, your bill is:" << endl;
        if (minutesUsed > PACKAGE_B_LIMIT) {
            minuteOverageCharge = (minutesUsed - PACKAGE_B_LIMIT) * PACKAGE_B_PER_MINUTE;
        }
        total = minuteOverageCharge + PACKAGE_B_RATE;
        cout << "$" << total;
    }
    else if (planSelection == 'C') {
        cout << "For Package C with " << minutesUsed << " minutes of usage, your bill is:" << endl;
        cout << "$69.99";
    } else {
        cout << "Please enter a valid package option -- A, B or C";
    }

    return 0;
}
/*
Sample Execution 1:
Enter Plan <A, B or C> and number of minutes used this month.
Z 1000
Please enter a valid package option -- A, B or C
Process finished with exit code 0

Sample Execution 2:
Enter Plan <A, B or C> and number of minutes used this month.
C 1000
For Package C with 1000.00 minutes of usage, your bill is:
$69.99
Process finished with exit code 0

Sample Execution 3:
Enter Plan <A, B or C> and number of minutes used this month.
B 1000
For Package B with 1000.00 minutes of usage, your bill is:
$99.99
Process finished with exit code 0

Sample Execution 4:
Enter Plan <A, B or C> and number of minutes used this month.
A 1000
For Package A with 1000.00 minutes of usage, your bill is:
$287.49
Process finished with exit code 0
*/
