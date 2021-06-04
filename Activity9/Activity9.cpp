//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    09
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity9/Activity9.cpp
//Purpose: 	        Practice with parsing an integer value using while loops, conditionals, and modulo/division operators
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

int main() {
    // variable declaration
    int userInput;
    int sum = 0;
    int userInputFinalOutput;

    // prompt user
    cout << "Enter an integer greater than 10000: ";

    // read in integer from user
    cin >> userInput;

    // store original user input in second variable
    userInputFinalOutput = userInput;

    // input validation
    while(userInput < 10000){
        cout << userInput << " is not greater than 10000" << endl;
        cout << "Enter an integer greater than 10000: ";
        cin >> userInput;
    }

    // get the tens place value, check if it's even and if so add it to the sum, stop when all digits have been checked
    while(userInput != 0){
        int tensPlaceValue = 0;
        tensPlaceValue = userInput % 10;
        if(tensPlaceValue % 2 == 0){
            sum += tensPlaceValue;
        }
        userInput /= 10;
    }
    // display output to user
    cout << "The sum of the even digits of " << userInputFinalOutput << " is " << sum;


    return 0;
}
/* Sample Execution:
Enter an integer greater than 10000: 248970158
The sum of the even digits of 248970158 is 22
Process finished with exit code 0
 */