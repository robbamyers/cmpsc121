//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    13
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity13/Activity13.cpp
//Purpose: 	        Practice using random numbers
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
#include <cmath>
using namespace std;

int main() {
    // seed rand
    srand(time(NULL));
    // variable declaration
    int counter = 0, n = 0, headsOrTails, roundPayout, totalPayoutCopy;
    double averagePayout;
    string result;
    // do 10 times
    do{
        // generate heads (1) or tails (0) until a heads is flipped
        do{
            headsOrTails = rand() % 2;
            // increment the number of flips for this turn
            n++;
            // conditional to check if a tails was flipped
            if(headsOrTails == 0){
                result += "T";
            }
        }while(headsOrTails != 1);
        // when a heads is flipped, add "H" to the running string of coin flips and display to user
        result += "H";
        cout << result;
        // calculate the total payout for that round and display to user
        roundPayout += pow(2, n);
        cout << fixed << setprecision(2);
        cout << setw(20 - result.length()) << "You win: $" << roundPayout << endl;
        // reset flip counter
        n = 0;
        // reset running string of flips
        result = "";
        // add round payout to copy variable for average calculation. reset roundPayout for next round
        totalPayoutCopy += roundPayout;
        roundPayout = 0;
        // increment round counter
        counter++;
    } while(counter < 10);

    // calculate average payout
    averagePayout = totalPayoutCopy / 10;
    cout << endl <<  "The average payout was " << averagePayout;

    return 0;
}

/* Sample Execution:
TH        You win: $4
TH        You win: $4
TH        You win: $4
H         You win: $2
TTTTTTH   You win: $128
TTTTH     You win: $32
H         You win: $2
TTH       You win: $8
TTTTTTH   You win: $128
TH        You win: $4

The average payout was 31.00
Process finished with exit code 0
 */