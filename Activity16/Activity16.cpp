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
using namespace std;

double calculateBalance(double tx);
void displayTotal(double runningTotal);

int main() {
    char continuation;
    double finalBalance;
    do {
        cout << "Please enter your transaction:" << endl << "$";
        double tx;
        cin >> tx;
        finalBalance = calculateBalance(tx);
        cout << "Enter another transaction? y/n" << endl;
        cin >> continuation;
    }while(toupper(continuation) == 'Y');
    cout << "Your final balance is: $" << finalBalance;
    return 0;
}

double calculateBalance(double tx){
    static double runningTotal = 0;
    runningTotal += tx;
    if(runningTotal >= 0){
        displayTotal(runningTotal);
    }
    else{
        runningTotal -= tx;
        cout << "DANGER WILL ROBINSON! You're trying to overdraft your account. This transaction was not recorded." << endl;
        cout << "You cannot spend more than $" << runningTotal << ". Please re-enter your transaction." << endl;
        displayTotal(runningTotal);
    }
    return runningTotal;
}

void displayTotal(double runningTotal){
    cout << "Your balance is: $" << runningTotal << endl;
}




// enter transaction, validate to be positive
// ask if you want to enter additional tx
// enter transaction, calculate balance, if negative force addtl tx and require it to be positive, continue until currentBalance is positive
// ask if you want to enter additional tx


