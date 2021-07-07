//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    17
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Activity17/Activity17.cpp
//Purpose: 	        Practice using reference variables
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
#include <cmath>
#include <iomanip>
using namespace std;

// function prototype
void getLwh(int& length, int& width, int& height);
void calculateAndDisplay(int length, int width, int height);

int main() {
    // local variable declaration
    int length, width, height;
    cout << "Enter the length, width, and height in meters" << endl;
    // read in these values from the user and store in existing memory location of l, w, and h.
    getLwh(length, width, height);
    // calculate the diagonal length and display it to the user
    calculateAndDisplay(length, width, height);
    return 0;
}

// function definitions
void getLwh(int& length, int& width, int& height){
    cin >> length >> width >> height;
}
void calculateAndDisplay(int length, int width, int height){
    double result = pow((pow(length,2)+pow(width, 2)+pow(height, 2)),.5);
    cout << "The longest pole that can fit in this room is " << fixed << setprecision(2) << result << " meters";
}

/* Sample Execution:
Enter the length, width, and height in meters
10 8 5
The longest pole that can fit in this room is 13.75 meters
Process finished with exit code 0
 */