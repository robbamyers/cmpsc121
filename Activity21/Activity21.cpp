//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    21
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity21/Activity21.cpp
//Purpose: 	        Using nested for loops
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
#include <string>
#include <fstream>
using namespace std;

// structure declaration
struct PartInfo {
    string number;
    string name;
    char pclass;
    int numberInStock;
    double unitPrice;
};

// function prototype
void writeOutput(const PartInfo& p);

// create fout file
ofstream fout("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity21/Output.txt");

int main() {
    // define a PartInfo structure
    PartInfo part;
    char continuation;
    do
    {
        cout << "Enter part information" << endl;
        cin >> part.number >> part.name >> part.pclass >> part.numberInStock >> part.unitPrice;
        writeOutput(part);
        cout << "Enter more parts? Y/N" << endl;
        cin >> continuation;
    }while(toupper(continuation) == 'Y');

    // close file
    fout.close();
    return 0;
}

// write partInfo to file
void writeOutput(const PartInfo& p){
    fout << p.number << " " << p.name << " " << p.pclass << " " << p.numberInStock << " " << p.unitPrice << endl;
}
