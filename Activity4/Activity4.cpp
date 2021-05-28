//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    04
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Activity4.cpp
//Purpose: 	        Integer Division
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
    float fahrenheitOne, fahrenheitTwo, fahrenheitThree, fahrenheitFour, fahrenheitFive;
    float celsiusOne, celsiusTwo, celsiusThree, celsiusFour, celsiusFive;
    // literal declaration
    float CONVERSIONFACTOR = 5.0 / 9.0;

    // user prompt
    cout << "Enter five temperature values in Fahrenheit:" << endl;
    cin >> fahrenheitOne >> fahrenheitTwo >> fahrenheitThree >> fahrenheitFour >> fahrenheitFive;
    cout << endl;

    // arithmetic
    celsiusOne = (fahrenheitOne - 32)*CONVERSIONFACTOR;
    celsiusTwo = (fahrenheitTwo - 32)*CONVERSIONFACTOR;
    celsiusThree = (fahrenheitThree - 32)*CONVERSIONFACTOR;
    celsiusFour = (fahrenheitFour - 32)*CONVERSIONFACTOR;
    celsiusFive = (fahrenheitFive - 32)*CONVERSIONFACTOR;

    // display converted value prompt
    cout << setw(15) << "Fahrenheit" << setw(15) << "Celsius" << endl;
    // set precision of 2 decimal points for all returned values
    cout << fixed << setprecision(2);

    // adjust layout by setting right adjusted padding 15 spaces
    cout << setw(15) << fahrenheitOne << setw(15) << celsiusOne << endl;
    cout << setw(15) << fahrenheitTwo << setw(15) << celsiusTwo << endl;
    cout << setw(15) << fahrenheitThree << setw(15) << celsiusThree << endl;
    cout << setw(15) << fahrenheitFour << setw(15) << celsiusFour << endl;
    cout << setw(15) << fahrenheitFive << setw(15) << celsiusFive << endl;
    return 0;
}

/* Sample Execution:
Enter five temperature values in Fahrenheit:
100 0 32 70 85

     Fahrenheit        Celsius
         100.00          37.78
           0.00         -17.78
          32.00           0.00
          70.00          21.11
          85.00          29.44

*/
