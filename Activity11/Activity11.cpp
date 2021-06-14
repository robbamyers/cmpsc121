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

    // variable declaration
    string partNumber;
    char partClass;
    int stock;
    float price;
    int partACounter = 0, partBCounter = 0, partCCounter = 0, partDCounter = 0, unknownCounter = 0;
    double lineItemValue = 0;
    double partAInvTotal, partBInvTotal, partCInvTotal, partDInvTotal, unknownTotal;

    while(partsFile >> partNumber >> partClass >> stock >> price){
        if (partClass == 'A'){
            partACounter++;
            lineItemValue = stock * price;
            partAInvTotal += lineItemValue;
        }
        else if(partClass == 'B'){
            partBCounter++;
            lineItemValue = stock * price;
            partBInvTotal += lineItemValue;
        }
        else if(partClass == 'C'){
            partCCounter++;
            lineItemValue = stock * price;
            partCInvTotal += lineItemValue;
        }
        else if(partClass == 'D'){
            partDCounter++;
            lineItemValue = stock * price;
            partDInvTotal += lineItemValue;
        }
        else{
            unknownCounter++;
            lineItemValue = stock * price;
            unknownTotal += lineItemValue;
        }

    }
    cout << fixed << setprecision(2);
    cout << "===============Inventory Reports==============" << endl;
    return 0;
}
