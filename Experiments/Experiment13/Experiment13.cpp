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
#include <ctime>
using namespace std;
const int CAPACITY = 25;
struct campaign{
    string candidate[CAPACITY];
    int votes[CAPACITY];
    double percent[CAPACITY];
};
bool readFile(string c[], int &size);
void getVotes(int v[], int size);
void calculatePercents(int v[], double p[], int size);
int main() {
    srand(time(NULL));
    int size = CAPACITY;
    ifstream fin;
    fin.open("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment13/candidates.txt");
    if(fin.fail()){
        cout << "File failed to open!";
    }
    else{
        campaign president;
        for(int i = 0; i < size; i++){
            fin >> president.candidate[i];
        }
        getVotes(president.votes, size);
        calculatePercents(president.votes, president.percent,size);
        for(int i = 0; i < size; i++){
            cout << president.candidate[i] << endl;
            cout << president.votes[i] << endl;
            cout << president.percent[i] << endl;
        }
    }
    return 0;
}

bool readFile(string c[], int &size){

}
void getVotes(int v[], int size){
    for(int i = 0; i < size; i++){
        v[i] = rand() % 25000 + 1500;
    }
}
void calculatePercents(int v[], double p[], int size){
    int totalVotes = 0;
    for(int i = 0; i < size; i++){
        totalVotes += v[i];
    }
    for(int i = 0; i < size; i++){
        p[i] = (double (v[i]) /  totalVotes * 100);
    }
}

