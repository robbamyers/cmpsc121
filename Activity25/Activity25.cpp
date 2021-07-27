//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    25
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity25/Activity25.cpp
//Purpose: 	        Practice with sorting/searching
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
// declare a constant for vector size
const int SIZE = 5000;
void shellSort(vector<int>& V);
void swapper(int &a, int &b);
void fillVector(vector<int>& V);
void smallest(vector<int> V, int& smallestValue);
void largest(vector<int> V, int& largestValue);
void odd(vector<int> V, int& oddCount);
void even(vector<int> V, int& evenCount);
void total(vector<int> V, long& totalValues);
void average(long totalValues, long& averageValues);
void findInt(vector<int> V, int userInput, int& foundPosition);
int main() {
    // seed random with truly random values
    srand(time(NULL));
    // vector declaration, variable declaration
    vector<int> V(SIZE);
    int smallestValue, largestValue,
        oddCount, evenCount,
        userInput, foundPosition = 0;
    long totalValues, averageValues;
    fillVector(V);
    shellSort(V);
    smallest(V, smallestValue);
    largest(V, largestValue);
    odd(V, oddCount);
    even(V, evenCount);
    total(V, totalValues);
    average(totalValues, averageValues);
    cout << "The smallest number is: " << smallestValue << endl;
    cout << "The largest number is: " << largestValue << endl;
    cout << "The number of odd values is: " << oddCount << endl;
    cout << "The number of even values is: " << evenCount << endl;
    cout << "The total of the values is: " << totalValues << endl;
    cout << "The average of the values is: " << averageValues << endl;
    // prompt and read in value from user
    cout << "Enter an integer: ";
    cin >> userInput;
    findInt(V, userInput, foundPosition);
    // see if found position was updated, if so, display found position to user
    if(foundPosition != 0){
        cout << userInput << " was found at position " << foundPosition;
    }
    else{
        cout << userInput << " was not found.";
    }
    return 0;
}
void shellSort(vector<int>& V)
{
	bool flag = true;
	int i, numLength = V.size();

	int d = numLength;
	while (flag || (d>1))    // bool flag
	{
		flag = false;  //reset flag to 0 to check for
		// future swaps�����
		d = (d + 1) / 2;
		for (i = 0; i < (numLength - d); i++)
		{
			if (V[i + d] < V[i])
			{
				swapper(V[i], V[i + d]);

				flag = true;     //tells swap has occurred
			}
		}
	}
}
void swapper(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
// fill the vector with 5000 random values
void fillVector(vector<int>& V){
    // loop through vector and assign position to a random number
    for(int i = 0; i < SIZE; i++){
        V[i] = rand();
    }
}
// because vector is already sorted by the time this function is called,
// assign the value of the first element in the vector to smallestValue
void smallest(const vector<int> V, int& smallestValue){
    smallestValue = V[0];
}
// because vector is already sorted by the time this function is called,
// assign the value of the last element in the vector to largestValue
void largest(const vector<int> V, int& largestValue){
    largestValue = V[SIZE - 1];
}
// loop through vector and see if number is not evenly divisible by 2 and doesn't end in a 0 (treat 0's as even)
void odd(const vector<int> V, int& oddCount){
    oddCount = 0;
    for(int i = 0; i < SIZE; i++){
        if(V[i] % 2 != 0 && V[i] % 10 != 0){
            oddCount++;
        }
    }
}
// loop through vector and see if number is divisible by 2
void even(const vector<int> V, int& evenCount){
    evenCount = 0;
    for(int i = 0; i < SIZE; i++){
        if(V[i] % 2 == 0){
            evenCount++;
        }
    }
}
// loop through vector and add each value to totalValues, store in long to ensure it can all fit
void total(const vector<int> V, long& totalValues){
    totalValues = 0;
    for(int i = 0; i < SIZE; i++){
        totalValues += V[i];
    }
}
// divide totalValues by size to calculate averageValues
void average(const long totalValues, long& averageValues){
    averageValues = totalValues/SIZE;
}
// once a user indicates which number they want to search for,
// look through array and see if the number was generated in the array
void findInt(const vector<int> V, const int userInput, int& foundPosition){
    for(int i = 0; i < SIZE; i++){
        if(V[i] == userInput){
            foundPosition = i;
        }
    }
}
/* Sample Execution:
The smallest number is: 582093
The largest number is: 2147416999
The number of odd values is: 2527
The number of even values is: 2473
The total of the values is: 5438351113167
The average of the values is: 1087670222
Enter an integer: 238423452
238423452 was not found.
Process finished with exit code 0
*/

