//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        13
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment13/Experiment13.cpp
//Purpose: 	        This experiment is designed to develop confidence with arrays and reading files.
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
#include <vector>
#include <ctime>
using namespace std;
const int CAPACITY = 25;
// create a struct to hold data on a presidential candidate
struct campaign{
    string candidate[CAPACITY];
    int votes[CAPACITY];
    double percent[CAPACITY];
};
// function prototypes
bool readFile(string c[], int &size);
void getVotes(int v[], int size);
void calculatePercents(int v[], double p[], int size);
void displayResults(string c[], int v[], double p[], int size);

int main() {
    // seed rand() with system time
    srand(time(NULL));
    // struct declaration
    campaign president;
    // temporarily assign capacity to size, this will be overwritten when readFile is called
    int size = CAPACITY;
    // call readFile and if it returns false, inform user of error, otherwise, read in candidates and assign new value to size
    if(!readFile(president.candidate, size)){
        cout << "The file failed to open";
    }
    else {
        getVotes(president.votes, size);
        calculatePercents(president.votes, president.percent, size);
        displayResults(president.candidate, president.votes, president.percent, size);
    }
    return 0;
}

bool readFile(string c[], int &size){
    // read in file
    ifstream fin;
    fin.open("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment13/candidates.txt");
    if(fin.fail()){
        return false;
    }
    else{
        // int variable to hold true size of file
        int i = 0;
        // read in values until the end of the file
        while(fin >> c[i]){
            i++;
        }
        // set size variable to the true size of file (passed by reference)
        size = i;
        fin.close();
        return true;
    }
}
void getVotes(int v[], int size){
    // loop through votes
    for(int i = 0; i < size; i++){
        // assign a random number of votes between 25000 and 1500 to each position in array
        v[i] = rand() % 25000 + 1500;
    }
}
void calculatePercents(int v[], double p[], int size){
    // aggregate total votes
    int totalVotes = 0;
    for(int i = 0; i < size; i++){
        totalVotes += v[i];
    }
    // calculate percent by dividing votes by totalVotes and assigning to percent array
    for(int i = 0; i < size; i++){
        p[i] = (double (v[i]) /  totalVotes * 100);
    }
}
void displayResults(string c[], int v[], double p[], int size){
    // header for output
    cout << setprecision(2);
    cout << setw(10) << "Candidate" << setw(10) << "Votes" << setw(11) << "Percent" << endl;
    // loop through and display output for candidate, votes and percents
    for(int i = 0; i < size; i++){
        cout << setw(10) << c[i] << setw(10) << v[i] << setw(10) << p[i] << "%" << endl;
    }
    // find highest vote count
    string winner;
    int highestVoteCount = 0;
    for(int i = 0; i < size; i++){
        if(v[i] > highestVoteCount){
            highestVoteCount = v[i];
            winner = c[i];
        }
    }
    cout << "The winner is " << winner << "!";
}

/* Sample Execution:
 Candidate     Votes    Percent
     Rubio     23935       8.5%
      Bush     14367       5.1%
  Christie      2505      0.88%
      Paul      4430       1.6%
  O'Malley     11852       4.2%
      Cruz     16530       5.8%
   Clinton     20791       7.3%
     Trump     20953       7.4%
    Kasich     11489       4.1%
   Sanders      9954       3.5%
    Carson     18482       6.5%
   Gilmore      8882       3.1%
   Fiorina     14005       4.9%
  Santorum     24050       8.5%
  Huckabee     25000       8.8%
    Graham     11771       4.2%
    Jindal      4949       1.7%
    Walker     14690       5.2%
     Perry     24435       8.6%
The winner is Huckabee!
Process finished with exit code 0
*/