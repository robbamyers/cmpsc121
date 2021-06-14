//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    11
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Activity11/Activity11.cpp
//Purpose: 	        Practice reading files
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
#include <fstream>
#include <string>
using namespace std;

int main() {
    // open file
    ifstream partsFile("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity11/parts.txt");

    // variable declarations
    string partNumber;
    char partClass;
    int stock;
    float price;
    int partACounter = 0, partBCounter = 0, partCCounter = 0, partDCounter = 0, unknownCounter = 0;
    double lineItemValue = 0;
    double partAInvTotal, partBInvTotal, partCInvTotal, partDInvTotal, unknownTotal;

    // ensure file can be read
    if(partsFile.fail()){
        cout << "Unable to open file.";
    }
    else {
        // read values until the end of the document is reached
        while (partsFile >> partNumber >> partClass >> stock >> price) {
            // conditional expression to check what class the part is
            if (partClass == 'A'){
                partACounter++;
                // arithmetic to calculate the value of that line
                lineItemValue = stock * price;
                // add to running total
                partAInvTotal += lineItemValue;
            } else if (partClass == 'B'){
                partBCounter++;
                lineItemValue = stock * price;
                partBInvTotal += lineItemValue;
            } else if (partClass == 'C'){
                partCCounter++;
                lineItemValue = stock * price;
                partCInvTotal += lineItemValue;
            } else if (partClass == 'D') {
                partDCounter++;
                lineItemValue = stock * price;
                partDInvTotal += lineItemValue;
            } else {
                unknownCounter++;
                lineItemValue = stock * price;
                unknownTotal += lineItemValue;
            }
        }
    }
    // close file
    partsFile.close();

    cout << fixed << setprecision(2);
    cout << "==================Inventory Reports===================" << endl;
    cout << "A-Parts" << setw(10) << "Count: " << partACounter << setw(25) << "Value of Inventory: " << setw(10) << partAInvTotal << endl;
    cout << "B-Parts" << setw(10) << "Count: " << partBCounter << setw(25) << "Value of Inventory: " << setw(10) <<  partBInvTotal << endl;
    cout << "C-Parts" << setw(10) << "Count: " << partCCounter << setw(25) << "Value of Inventory: " << setw(10) <<  partCInvTotal << endl;
    cout << "D-Parts" << setw(10) << "Count: " << partDCounter << setw(25) << "Value of Inventory: " << setw(10) <<  partDInvTotal << endl;
    cout << "Unknown" << setw(10) << "Count: " << unknownCounter << setw(25) << "Value of Inventory: " << setw(10) <<  unknownTotal << endl;
    return 0;
}
/* Sample Execution:
==================Inventory Reports===================
A-Parts   Count: 85     Value of Inventory:  191180.07
B-Parts   Count: 69     Value of Inventory:   74764.16
C-Parts   Count: 77     Value of Inventory:   50322.30
D-Parts   Count: 60     Value of Inventory:   22416.49
Unknown   Count: 13     Value of Inventory:    4282.68

Process finished with exit code 0
 */
