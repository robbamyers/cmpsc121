//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    15
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity15/Activity15.cpp
//Purpose: 	        Practice using functions
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

// function prototype
double calculateValue(int,double);

// global variable for continuation
char continuation;

int main() {
    do{
        // local scope declaration
        int items;
        double cost;

        // set precision to two decimal places
        cout << fixed << setprecision(2);

        // prompt user and read in values from user
        cout << "Enter the number of items and cost: ";
        cin >> items >> cost;

        // call calculateValue function and pass in local scope variables as arguments
        cout << "The extended amount is $" << calculateValue(items,cost) << endl;

        // prompt user to enter another calculation and read in decision
        cout << "Do you have another purchase to enter? Y or N" << endl;
        cin >> continuation;
    }while(toupper(continuation) == 'Y');
}

// function definition
double calculateValue(int items, double cost){
    return (items * cost);
}
/* Sample Execution:
Enter the number of items and cost: 10 5.25
The extended amount is $52.50
Do you have another purchase to enter? Y or N
Y
Enter the number of items and cost: 8 43.19
The extended amount is $345.52
Do you have another purchase to enter? Y or N
N

Process finished with exit code 0
 */