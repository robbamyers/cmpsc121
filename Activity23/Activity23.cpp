//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    23
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity23/Activity23.cpp
//Purpose: 	        Practice with arrays
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
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    const int SIZE = 10;
    int nums[SIZE] = {5,4,2,7,6,8,5,2,8,14};

    // #1
    for(int i = 0; i < SIZE; i++){
        nums[i] = nums[i] * nums[i];
    }

    // #2
    for(int i = 0; i < SIZE; i++)
        nums[i] += rand() % 11;

    // #3
    for(int i = 0; i < (SIZE - 1); i++){
        nums[i] += nums[i+1];
    }

    // #4
    int sum = 0;
    for (int i = 0; i < SIZE; i++){
        sum +=  nums[i];
    }

    // #5
    int largest;
    for(int i = 0; i < (SIZE - 1); i++){
        if(nums[i] > nums[i+1]){
            largest = nums[i];
        }
    }
    cout << largest;
    return 0;
}
/* Sample Execution:
266
Process finished with exit code 0
*/