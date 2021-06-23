//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        08
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment08/Experiment08.cpp
//Purpose: 	        This experiment is designed to develop confidence with random numbers.
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
#include <ctime>
using namespace std;
// function prototype
void simulateAtBat();

// global variables
int     thousandPossibilities;
double  out = 0, walk = 0,
        singleScore = 0, doubleScore = 0, tripleScore = 0,
        homeRun = 0,
        battingAverage = 0;
char    continuation;

int main() {
    // seed random numbers on each iteration
    srand(time(NULL));
    // continue program until user says otherwise
    do{
        cout << "Simulation of the mighty Casey at-bat 1000 times:" << endl;
        // run 1000 iterations
        for(int i = 0; i < 1000; i++){
            // function call
            simulateAtBat();
        }
        // calculate battingAverage
        battingAverage = (singleScore + doubleScore + tripleScore + homeRun)/(1000 - walk);
        cout << fixed << setprecision(1);
        // display results to user
        cout << setw(10) << "Out:" << setw(10) << out/10 << "%" << endl;
        cout << setw(10) << "Walk:" << setw(10) << walk/10 << "%" << endl;
        cout << setw(10) << "Single:" << setw(10) << singleScore/10 << "%" << endl;
        cout << setw(10) << "Double:" << setw(10) << doubleScore/10 << "%" << endl;
        cout << setw(10) << "Triple:" << setw(10) << tripleScore/10 << "%" << endl;
        cout << setw(10) << "Home Run:" << setw(10) << homeRun/10 << "%" << endl << endl;
        cout << setprecision(3);
        cout << "Casey's batting average was " << battingAverage << endl << endl;
        // prompt for continuation and read in user decision
        cout << "Would you like to run another simulation (Y/N)? ";
        cin >> continuation;
        // reset results for next iteration
        out = 0, walk = 0, singleScore = 0, doubleScore = 0, tripleScore = 0, homeRun = 0;
    }while(toupper(continuation) == 'Y');
    cout << "Thanks for playing!";
    return 0;
}
// function definition
void simulateAtBat(){
    // generate a random number between 1 and 1000
    thousandPossibilities = rand() % 1000 + 1;
    // simulate probability of an out at 58%
    if(thousandPossibilities <= 580){
        out++;
    }
    // simulate probability of walking at 9.7%
    if(thousandPossibilities <= 97){
        walk++;
    }
    // simulate probability of single at 22%
    if(thousandPossibilities <= 220){
        singleScore++;
    }
    // simulate probability of double at 6.1%
    if(thousandPossibilities <= 61){
        doubleScore++;
    }
    // simulate probability of triple at 2.5%
    if(thousandPossibilities <= 25){
        tripleScore++;
    }
    // simulate probability of home run at 1.7%
    if(thousandPossibilities <= 17){
        homeRun++;
    }
}
/* Sample Execution:
Simulation of the mighty Casey at-bat 1000 times:
      Out:      58.9%
     Walk:      10.7%
   Single:      23.3%
   Double:       7.3%
   Triple:       3.6%
 Home Run:       2.9%

Casey's batting average was 0.415

Would you like to run another simulation (Y/N)? Y
Simulation of the mighty Casey at-bat 1000 times:
      Out:      58.7%
     Walk:       9.1%
   Single:      22.2%
   Double:       5.9%
   Triple:       2.8%
 Home Run:       1.9%

Casey's batting average was 0.361

Would you like to run another simulation (Y/N)? Y
Simulation of the mighty Casey at-bat 1000 times:
      Out:      59.2%
     Walk:      10.4%
   Single:      22.7%
   Double:       5.6%
   Triple:       2.3%
 Home Run:       1.8%

Casey's batting average was 0.362

Would you like to run another simulation (Y/N)? Y
Simulation of the mighty Casey at-bat 1000 times:
      Out:      55.3%
     Walk:       9.4%
   Single:      21.6%
   Double:       5.3%
   Triple:       2.0%
 Home Run:       1.1%

Casey's batting average was 0.331

Would you like to run another simulation (Y/N)? N
Thanks for playing!
Process finished with exit code 0
*/