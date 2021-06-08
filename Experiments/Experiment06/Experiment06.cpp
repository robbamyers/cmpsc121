//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        06
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment06/Experiment06.cpp
//Purpose: 	        This experiment is designed to develop confidence with loops
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
const string TRANSACTION_NUMBER = "Transaction #";

int main() {
    // variable declaration. clion recommends initializing variables
    int     unitsSold = 0, totalNumberOfTransactions = 0, counter = 1;
    float   unitPrice = 0, transactionTotal = 0, averageUnitsPerOrder = 0, averageRevenue = 0,
            largestTransaction = 0, smallestTransaction = 0, totalRevenue = 0;

    // prompt user
    cout << "Enter transactions -99 0 to stop" << endl;

    // continue until user enters -99 0
    do
    {
        // display transaction number and read in units sold and unit price from user
        cout << TRANSACTION_NUMBER << counter << ": ";
        cin >> unitsSold >> unitPrice;

        // arithmetic
        transactionTotal = unitsSold * unitPrice;
        totalRevenue += transactionTotal;
        totalNumberOfTransactions += unitsSold;

        // check if tx total is larger than previous iteration's largest Transaction
        if(transactionTotal > largestTransaction){
            largestTransaction = transactionTotal;
        }
        /*
            on first iteration (smallestTransaction == 0), set smallest tx
            then check on the next iteration if tx total is smaller than current
            smallest tx. Also ensure tx is not terminating tx
        */
        else if ((transactionTotal <= smallestTransaction || smallestTransaction == 0) && transactionTotal != -0.00){
            smallestTransaction = transactionTotal;
        }

        counter++;
    } while(unitsSold != 99 && unitPrice != 0);

    /*  calculate averages based on running totals, add 99 to cancel terminating tx
        and subtract 2 from counter due to counter initialized at 1 rather than 0 and
        terminating transaction counting as loop
    */
    averageUnitsPerOrder = (totalNumberOfTransactions + 99.0)/(counter - 2);
    averageRevenue = totalRevenue/(counter - 2);

    cout << "\n";
    cout << "TRANSACTION PROCESSING REPORT" << endl;
    cout << left << setw(25) << "Transactions Processed:"  << (counter - 2) << endl;
    cout << left << setw(25) << "Units Sold:" << (totalNumberOfTransactions + 99) << endl;
    cout << fixed << setprecision(2);
    cout << left << setw(25) << "Average Units per Order:" << averageUnitsPerOrder << endl;
    cout << left << setw(25) << "Largest Transaction:" << largestTransaction << endl;
    cout << left << setw(25) << "Smallest Transaction:" << smallestTransaction << endl;
    cout << left << setw(25) << "Total Revenue:" << "$" <<  totalRevenue << endl;
    cout << left << setw(25) << "Average Revenue:" << "$" << averageRevenue;


    return 0;
}
/* Sample Execution:
Enter transactions -99 0 to stop
Transaction #1: 30 9.75
Transaction #2: 22 8.50
Transaction #3: 15 7.95
Transaction #4: 12 9.00
Transaction #5: 16 8.55
Transaction #6: 36 7.99
Transaction #7: 100 10.75
Transaction #8: 43 9.99
Transaction #9: 14 6.95
Transaction #10: 13 8.98
Transaction #11: -99 0

TRANSACTION PROCESSING REPORT
Transactions Processed:  10
Units Sold:              301
Average Units per Order: 30.10
Largest Transaction:     1075.00
Smallest Transaction:    97.30
Total Revenue:           $2849.80
Average Revenue:         $284.98
Process finished with exit code 0
 */