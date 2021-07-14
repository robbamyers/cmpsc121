//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    22
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity22/Activity22.cpp
//Purpose: 	        Practice using arrays
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
#include <ctime>
#include <cstdlib>
using namespace std;
const int SIZE = 50;

int main() {
    // seed rand() with truly random number
    srand(time(NULL));
    // declare an integer type array of length SIZE
    int arr[SIZE];
    // loop through array
    for (int i = 0; i < SIZE; i++){
        // assign current item in array a random number
        arr[i] = rand();
        // display current item in array
        cout << arr[i] << " ";
        // enter a line break at the end of the 9th item in the list
        if(i%10 != 0 && (i%10) % 9 == 0){
            cout << endl;
        }
    }
    return 0;
}
