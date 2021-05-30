//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        03
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment03/experiment03.cpp
//Purpose: 	        This experiment is designed to develop confidence with output manipulation, floating point arithmetic and strings
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
const double PI = 3.14159;

int main() {

    // variable declaration
    float R, r, V, SA;

    // prompt user
    cout << "Enter radius of ring and radius of cross section:" << endl;

    // read in values from user
    cin >> R >> r;

    // arithmetic
    V = 2*(PI*PI)*R*(r*r);
    SA = 4*(PI*PI)*R*r;

    // display arithmetic to user, precise to thousandths place
    cout << fixed << setprecision(3);
    cout << "For a ring with a radius " << R << " and cross section radius of " << r << endl;
    cout << left << setw(25) << "The volume is:" <<  V << endl;
    cout << left << setw(25) << "The surface areas is:"  << SA << endl;

    return 0;
}

/* Sample Execution:
Enter radius of ring and radius of cross section:
2345.2 45
For a ring with a radius 2345.200 and cross section radius of 45.000
The volume is:           93741936.000
The surface areas is:    4166308.250

Process finished with exit code 0
*/
