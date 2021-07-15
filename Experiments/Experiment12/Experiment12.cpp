//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        12
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment12/Experiment12.cpp
//Purpose: 	        Practice usinig arrays
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

// constant declaration
const string CAPEQUIP = "Capital Equipment";
const string EXPEQUIP = "Expenses Equipment";
const string SMLPARTS = "Small Parts";
const string TOTAL = "Total Sales";
// struct definition
struct SalesRecord {
    string invoiceNumber;
    char equipmentCode;
    double cost;
};

// function prototypes
void accumulate(const SalesRecord &s, double & capSales, double &eqpSales, double & prtSales);
void writeReport(double capSales, double eqpSales, double prtSales, double total, double capPercent, double expPercent, double prtsPercent);

// create a file called inventoryReport to write output to
ofstream fout("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment12/inventoryReport.txt");

int main() {
    // open txt file
    ifstream fin;
    fin.open("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment12/sales.txt");
    // check file opens successfully
    if (fin.fail()){
        cout << "File open failure!";
    }
    else {
        // variable declaration
        double capSales, eqpSales, prtSales, total, capPercent, expPercent, prtsPercent;
        // struct declaration
        SalesRecord lineItem;
        // read in data from txt file to struct
        while (fin >> lineItem.invoiceNumber >> lineItem.equipmentCode >> lineItem.cost) {
            // after each line, accumulate sales
            accumulate(lineItem, capSales, eqpSales, prtSales);
        }
        // arithmetic to calculate total and percents
        total = capSales + eqpSales + prtSales;
        capPercent = (capSales / total) * 100;
        expPercent = (eqpSales / total) * 100;
        prtsPercent = (prtSales / total) * 100;
        // call function to write report
        writeReport(capSales, eqpSales, prtSales, total, capPercent, expPercent, prtsPercent);

    }
    return 0;
}

// depending on the equipment code, add cost to accumulation variable via reference
void accumulate(const SalesRecord &s, double &capSales, double &eqpSales, double &prtSales){
    if(s.equipmentCode == 'A'){
        capSales += s.cost;
    }
    else if(s.equipmentCode == 'B'){
        eqpSales += s.cost;
    }
    else{
        prtSales += s.cost;
    }
}
// generates report to output file
void writeReport(double capSales, double eqpSales, double prtSales, double total, double capPercent, double expPercent, double prtsPercent){
    fout << fixed << setprecision(2);
    fout << "       S A L E S   R E P O R T" << endl;
    fout << CAPEQUIP << setw(25 - CAPEQUIP.length()) << "$" << capSales << setw(10) << capPercent << "%" <<  endl;
    fout << EXPEQUIP << setw(25 - EXPEQUIP.length()) << "$" << eqpSales << setw(10) << expPercent << "%" << endl;
    fout << SMLPARTS << setw(25 - SMLPARTS.length()) << "$" << prtSales << setw(10) << prtsPercent << "%" << endl;
    fout << setw(33) << "---------" << endl;
    fout << TOTAL << setw(25-TOTAL.length()) << "$" << total << endl;

}