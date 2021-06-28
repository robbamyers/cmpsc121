//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    16
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity16/Activity16.cpp
//Purpose: 	        Write a program with function which uses a static variable to keep track of the current balance of a bank account.
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

// function prototypes
double calculateBalance(double tx);
void displayTotal(double runningTotal);

int main() {
    // main scoped variables to hold user choice for continuation and final balance
    char continuation;
    double finalBalance;
    // continue this until the user specifies no more transaction are being recorded
    do{
        // do scoped variable to hold transaction amount input by user
        double tx = 0;
        // prompt user and read in input
        cout << "Please enter your transaction:" << endl << "$";
        cin >> tx;
        // store returned value from calculateBalance function in final balance
        cout << fixed << setprecision(2);
        finalBalance = calculateBalance(tx);
        // prompt user to continue and read in input
        cout << "Enter another transaction? y/n" << endl;
        cin >> continuation;
    }while(toupper(continuation) == 'Y');
    // display final balance
    cout << "Your final balance is: $" << finalBalance;
    return 0;
}
// function to handle the running calculation of the transactions
// also handles validating the input does not result in a negative value
double calculateBalance(double tx){
    // static variable to retain value on each function call
    static double runningTotal = 0;
    // add transaction to running total
    runningTotal += tx;
    // check if running total is positive
    if(runningTotal >= 0){
        // show total
        displayTotal(runningTotal);
    }
    // if running total is not positive remove the transaction and alert the user
    else{
        runningTotal -= tx;
        cout << "DANGER WILL ROBINSON! You're trying to overdraft your account. This transaction was not recorded." << endl;
        cout << "You cannot spend more than $" << runningTotal << ". Please re-enter your transaction." << endl;
        displayTotal(runningTotal);
    }
    return runningTotal;
}

// function definition to display balance
void displayTotal(double runningTotal){
    cout << "Your balance is: $" << runningTotal << endl;
}

/* Sample Execution:
Please enter your transaction:
$5
Your balance is: $5.00
Enter another transaction? y/n
y
Please enter your transaction:
$10.25
Your balance is: $15.25
Enter another transaction? y/n
y
Please enter your transaction:
$-16
DANGER WILL ROBINSON! You're trying to overdraft your account. This transaction was not recorded.
You cannot spend more than $15.25. Please re-enter your transaction.
Your balance is: $15.25
Enter another transaction? y/n
y
Please enter your transaction:
$-20.23
DANGER WILL ROBINSON! You're trying to overdraft your account. This transaction was not recorded.
You cannot spend more than $15.25. Please re-enter your transaction.
Your balance is: $15.25
Enter another transaction? y/n
y
Please enter your transaction:
$-15
Your balance is: $0.25
Enter another transaction? y/n
n
Your final balance is: $0.25
Process finished with exit code 0
 */

