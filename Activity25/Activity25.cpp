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
const int SIZE = 10;

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
    srand(time(NULL));
    vector<int> V(SIZE);
    int smallestValue, largestValue,
        oddCount, evenCount,
        userInput, foundPosition;
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
    cout << "Enter an integer: ";
    cin >> userInput;
    findInt(V, userInput, foundPosition);
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
void fillVector(vector<int>& V){
    for(int i = 0; i < SIZE; i++){
        V[i] = rand();
    }
}
void smallest(const vector<int> V, int& smallestValue){
    smallestValue = V[0];
}
void largest(const vector<int> V, int& largestValue){
    largestValue = V[SIZE - 1];
}
void odd(const vector<int> V, int& oddCount){
    oddCount = 0;
    for(int i = 0; i < SIZE; i++){
        if(V[i] % 2 != 0 && V[i] % 10 != 0){
            oddCount++;
        }
    }
}
void even(const vector<int> V, int& evenCount){
    evenCount = 0;
    for(int i = 0; i < SIZE; i++){
        if(V[i] % 2 == 0){
            evenCount++;
        }
    }
}
void total(const vector<int> V, long& totalValues){
    totalValues = 0;
    for(int i = 0; i < SIZE; i++){
        totalValues += V[i];
    }
}
void average(const long totalValues, long& averageValues){
    averageValues = totalValues/SIZE;
}
void findInt(const vector<int> V, const int userInput, int& foundPosition){
    for(int i = 0; i < SIZE; i++){
        if(V[i] == userInput){
            foundPosition = i;
        }
    }
}

