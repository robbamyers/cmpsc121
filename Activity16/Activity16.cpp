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

int calcBalance(int tx);

int main() {
    char continuation;
    do{
        double tx = 0;
        cout << "Enter your transaction. Positive for deposit. Negative for withdrawals" << endl;
        cin >> tx;
        calcBalance(tx);

        cout << "Do you have more transactions to enter? y/n" << endl;
        cin >> continuation;
    }while(toupper(continuation) == 'Y');
    return 0;
}

int calcBalance(int tx){
    static int currentBalance = 0;
    currentBalance += tx;
    if(currentBalance >= 0){
        cout << "Current balance = $" << currentBalance << endl;
        return 0;
    }
    else {
        cout << "You've overdraw your account" << endl;
        return 1;
    }
}


// enter transaction, validate to be positive
// ask if you want to enter additional tx
// enter transaction, calculate balance, if negative force addtl tx and require it to be positive, continue until currentBalance is positive
// ask if you want to enter additional tx


