//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    24
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity24/Activity24.cpp
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
#include <vector>
#include <ctime>
using namespace std;
const int SIZE = 500;

int checkEven(const vector<int> setOne, const vector<int> setTwo);

int main() {
    srand(time(NULL));
    vector<int> setOne(SIZE);
    vector<int> setTwo(SIZE);
    for(int i = 0; i < SIZE; i++){
        setOne[i] = rand() % 100 + 1;
        setTwo[i] = rand() % 100 + 1;
    }
    int evenCount = checkEven(setOne,setTwo);
    cout << "The Vectors contain " << evenCount << " cells where both values are even";
    return 0;
}

int checkEven(const vector<int> setOne, const vector<int> setTwo){
    int evenCount = 0;
    for(int i = 0; i < SIZE; i++){
        if(setOne[i] % 2 == 0 && setTwo[i] % 2 == 0){
            evenCount++;
        }
    }
    return evenCount;
}

/* Sample Execution:
The Vectors contain 127 cells where both values are even
Process finished with exit code 0
 */