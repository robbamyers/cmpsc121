//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Experiment:   	02
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Experiments/experiment02
//Purpose: 	        Division modulo division.
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

int main() {
    // variable declaration
    double tendered;
    double cost;
    double changeInCents;
    int change;
    int fifties, twenties, tens, fives, dollars, quarters, dimes, nickels, pennies;

    cout << "Enter amount of purchase and amount tendered: ";
    // read in amount of purchase and amount tendered
    cin >> cost >> tendered;

    // remove scientific notation for large numbers by setting precision and fixed
    cout << fixed << setprecision(2);

    // confirm amounts with user
    cout << "For your purchase of $" << cost << " you tendered $" << tendered << endl;

    // check if tendered is more than cost
    if (tendered > cost) {
        // calculate change and store in integer variable cents
        change = (tendered - cost) * 100;

        // calculate change and store in double variable changeInCents
        changeInCents = change / 100.00;
        cout << "Your change is $" << changeInCents << endl;

        // see how many whole number fifties the change can be divided by
        fifties = change / 5000;
        cout << setw(15) << "Fifties: "  << fifties << endl;

        // update the amount of change due by subtracting the dollar amount in fifties from the previous statement
        change = change - (5000 * fifties);

        // repeat the steps from above with all lower denominations
        twenties = change / 2000;
        cout << setw(15) << "Twenties: " << twenties << endl;

        change = change - (2000 * twenties);

        tens = change / 1000;
        cout << setw(15) << "Tens: " << tens << endl;

        change = change - (1000 * tens);

        fives = change / 500;
        cout << setw(15) << "Fives: " << fives << endl;

        change = change - (500 * fives);

        dollars = change / 100;
        cout << setw(15) << "Ones: " << dollars << endl;

        change = change - (100 * dollars);

        quarters = change / 25;
        cout << setw(15) << "Quarters: " << quarters << endl;

        change = change - (25 * quarters);

        dimes = change / 10;
        cout << setw(15) << "Dimes: " << dimes << endl;

        change = change - (10 * dimes);

        nickels = change / 5;
        cout << setw(15) << "Nickels: " << nickels << endl;

        change = change - (5 * nickels);

        pennies = change / 1;
        cout << setw(15) << "Pennies: " << pennies << endl;
    } else {
        // if cost is greater than amount tendered, inform user
        cout << "You need more money!";
    }

    return 0;
}

/*Sample Execution:

Enter amount of purchase and amount tendered: 2.08 100.00
For your purchase of $2.08 you tendered $100.00
Your change is $97.92
    Fifties: 1
    Twenties: 2
    Tens: 0
    Fives: 1
    Ones: 2
    Quarters: 3
    Dimes: 1
    Nickels: 1
    Pennies: 2

Process finished with exit code 0
*/