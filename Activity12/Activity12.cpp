//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    12
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Activity12/Activity12.cpp
//Purpose: 	        Practice with while loops
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
    // continually ask for input until valid input is received
    do
    {
        cout << "Please enter an integer greater or equal to 2" << endl;
        cin >> userInput;
    }while(userInput < 2);
    // output display starting with userInput
    cout << "The Ulam Sequence starting from 10 is: " << userInput;
    // repeat while the number is greater than 1
    while(userInput > 1){
        // divide by 2 and display to user, while the value is even
        while(userInput % 2 == 0){
            userInput /= 2;
            cout << " " << userInput;
        }
        /* on final iteration, userInput will be 1, do not execute this statement in this scenario.
        Otherwise, we can assume the value is odd and execute the following arithmetic */
        if(userInput != 1){
            userInput *= 3;
            userInput += 1;
            cout << " " << userInput;
        }
    }
    return 0;
}
