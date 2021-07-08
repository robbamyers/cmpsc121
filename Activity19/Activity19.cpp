//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:         19
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity19/Activity19.cpp
//Purpose: 	        Practice overloading functions
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
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
const double AREA_CONSTANT = 0.5;

// function prototypes
double triangleArea(int base, int height);
double triangleArea(int side1, int side2, int side3);

int main() {
    // variable declarations
    int base, height, side1, side2, side3;
    double area;
    char continuation;
    // seed random with ever changing value
    srand(time(NULL));
    // continue while user input is y
    do
    {
        // generate a random number between 0 and 1
        int random = rand() % 2;
        // conditionally display base height prompt or sides prompt
        if (random == 0) {
            // prompt and read in values from user
            cout << "Enter base and height of a triangle" << endl;
            cin >> base >> height;
            // calculate area by calling overloaded function triangleArea()
            area = triangleArea(base, height);
            cout << "The area is " << area << endl;
        } else {
            cout << "Enter the lengths of the sides of a triangle." << endl;
            cin >> side1 >> side2 >> side3;
            area = triangleArea(side1, side2, side3);
            cout << "The area is " << area << endl;
        }
        // prompt and read in values from user
        cout << "Run again? Y or N" << endl;
        cin >> continuation;
    }while(toupper(continuation) == 'Y');
}

double triangleArea(int base, int height){
    // calculate area (A = (1/2)bh)
    double area = (AREA_CONSTANT * base * height);
    return area;
}
double triangleArea(int side1, int side2, int side3){
    // calculate semi-perimeter
    double s = (side1 + side2 + side3) / 2.0;
    // calculate area by sqrt(s(s-side1)(s-side2)(s-side3))
    double area = pow((s*(s-side1)*(s-side2)*(s-side3)),0.5);
    return area;
}

/* Sample Execution:
Enter base and height of a triangle
24 18
The area is 216
Run again? Y or N
y
Enter base and height of a triangle
23 16
The area is 184
Run again? Y or N
Y
Enter base and height of a triangle
1 2
The area is 1
Run again? Y or N
Y
Enter the lengths of the sides of a triangle.
18 30 24
The area is 216
Run again? Y or N
Y
Enter base and height of a triangle
4 6
The area is 12
Run again? Y or N
Y
Enter base and height of a triangle
10 12
The area is 60
Run again? Y or N
Y
Enter base and height of a triangle
91234 284
The area is 1.29552e+07
Run again? Y or N
Y
Enter the lengths of the sides of a triangle.
20 28 34
The area is 279.912
Run again? Y or N
N

Process finished with exit code 0
 */


