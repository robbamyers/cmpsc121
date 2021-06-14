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
    int partACounter = 0, partBCounter = 0, partCCounter = 0, partDCounter = 0, unknownCounter = 0;
    int valueOfInventory = 0;

    // skip first value
    string readFileValue;
    int readPosition = 0;
    int stockReadPosition = 2;
    string stock;
    int priceReadPosition = 3;
    string price;
    string value;
    while(partsFile >> readFileValue){
        if(readFileValue == "A"){
            partACounter++;
        }
        else if(readFileValue == "B"){
            partBCounter++;
        }

        if(stockReadPosition == readPosition){
            cout << "Stock: " << readFileValue << endl;
            stock = readFileValue;
            stockReadPosition = readPosition + 4;
        }
        else if(priceReadPosition == readPosition){
            cout << "Price: " << readFileValue << endl;
            price = readFileValue;
            value = stock*price;
            priceReadPosition = readPosition + 4;
        }

        readPosition++;

    }
    cout << partACounter << endl;
    cout << partBCounter << endl;

    return 0;
}
