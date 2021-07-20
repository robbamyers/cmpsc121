//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        13
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment13/Experiment13.cpp
//Purpose: 	        Practice with vectors
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
#include <vector>
using namespace std;
const int SIZE = 25;
struct campaign{
    string candidate[SIZE];
    int votes[SIZE];
    double percent[SIZE];
};


int main() {
    ifstream fin;
    fin.open("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment13/candidates.txt");

    if(fin.fail()){
        cout << "File failed to open!";
    }
    else{
        campaign president;
        for(int i = 0; i < SIZE; i++){
            fin >> president.candidate[i];
        }
    }


    return 0;
}
