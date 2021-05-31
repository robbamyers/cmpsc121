//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        03-01
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment03/experiment03-01.cpp
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
#include <cmath>

using namespace std;
const int TORQUECONSTANT = 63000;
const int DIAMETERCONSTANT = 16;
const int SPACING = 18;


int main() {

    // variable delcaration
    int p, n, s;
    float T, D;

    // prompt user
    cout << "Enter values for horsepower(p), rpm(n) and shear strength(s):" << endl;

    // read in values from user
    cin >> p >> n >> s;

    // arithmetic
    T = TORQUECONSTANT * (p/static_cast<double>(n));
    D = pow((DIAMETERCONSTANT*T)/s,0.333);

    // return calculated values to user
    cout << fixed << setprecision(3);
    cout << setw(SPACING) << "p(HP)" << setw(SPACING) << "n(rpm)" << setw(SPACING) << "s(psi)" << setw(SPACING) << "T(torque)" << setw(SPACING) << "D(diameter)" << endl;
    cout << setw(SPACING) << p << setw(SPACING) << n << setw(SPACING) << s << setw(SPACING) << T << setw(14) << D << " inches";

    return 0;
}

/* Sample Execution:
Enter values for horsepower(p), rpm(n) and shear strength(s):
300 3000 6000
             p(HP)            n(rpm)            s(psi)         T(torque)       D(diameter)
               300              3000              6000          6300.000         2.559 inches
Process finished with exit code 0
*/
