//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Project:   	    02
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Projects/Project2/Project2.cpp
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
#include <iomanip>
#include <fstream>
using namespace std;

double calcCost(int quantity, double unitCost);
double accTotal(double totalCost, double itemCost);
void printLine(string itemNo, string name, int quantity, double unitCost, double itemCost);
void printInvoiceHeader(string date);
void printReportHeader();
void printTotal(double invoiceTotal);

// create a file to write results to
ofstream fout("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Projects/Project2/output.txt");

int main() {
    // create input file stream and open file
    ifstream fin;
    fin.open("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Projects/Project2/input.txt");
    // test if file is open
    if (fin.fail()){
        cout << "File open failure!";
    }
    else {
        // main scope variable declarations
        int count, quantity;
        double unitCost, itemCost = 0;
        string invoiceNumber, date, partName;
        // print the "Erie Industriial.." report header
        printReportHeader();
        // read in the first two values (number of items and date respectively), until the end of the file
        while (fin >> count >> date) {
            // defined inside while statement to reset the invoice total on the start of each invoice
            double invoiceCost = 0;
            printInvoiceHeader(date);
            for (int i = 0; i < count; i++) {
                fin >> invoiceNumber >> partName >> quantity >> unitCost;
                itemCost = calcCost(quantity, unitCost);
                invoiceCost = accTotal(invoiceCost, itemCost);
                printLine(invoiceNumber, partName, quantity, unitCost, itemCost);
            }
            printTotal(invoiceCost);
            cout << endl;
        };
        fin.close();
        fout.close();
        return 0;
    }
}

double calcCost(int quantity, double unitCost){
    double totalCost = quantity * unitCost;
    return totalCost;
}
double accTotal(double invoiceCost, double totalCost){
    double newTotalCost = invoiceCost + totalCost;
    return newTotalCost;
}
void printLine(string itemNo, string name, int quantity, double unitCost, double itemCost){
    fout << fixed << setprecision(2);
    fout << itemNo << setw(15) << name << setw(8) << quantity << setw(8) << unitCost << setw(8) << itemCost << endl;
}
void printInvoiceHeader(string date){
    fout << "Invoice date:" << setw(10) << date << endl;
}
void printReportHeader(){
    fout << "Erie Industrial Supply Corporation" << endl;
}
void printTotal(double invoiceTotal){
    fout << "Total ....................." << invoiceTotal << endl;
}


