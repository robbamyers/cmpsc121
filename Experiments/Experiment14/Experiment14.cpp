//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        14
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment14/Experiment14.cpp
//Purpose: 	        The experiment focuses upon the material on vectors covered in the text and in module.
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
#include <iomanip>
using namespace std;
const int CAPACITY = 5000;
// struct definition
struct Parts{
    string number;
    char cls;
    int ohb;
    double cost;
};
// funciton prototypes
bool readFile(vector <Parts> &pVector, int& size);
int displayMenu();
double totalCost(const vector <Parts> &pVector, int size);
void countByClass(const vector <Parts> &pVector, vector <int> &classCounts, int size);
double costForClass(char classIn, const vector <Parts> &pVector, int size);
string highestCost(const vector <Parts> &pVector, int size);
string lowestCost(const vector <Parts> &pVector, int size);
void displayCounts(const vector <int> & classCounts);
int main() {
    // variable declarations
    int size = CAPACITY, userInput;
    vector<Parts> lineItem(size);
    // set precision to 2 decimals
    cout << fixed << setprecision(2);
    // see if we are able to read file
    if(readFile(lineItem, size)){
        do{
            // variable declaration
            double total = 0, cost = 0;
            char cls;
            string highest, lowest;
            vector<int> classCounts{0,0,0,0,0,0}; // initialize vector to 0 for looping purposes
            displayMenu();
            // read in input from user
            cin >> userInput;
            // input validation
            if(userInput < 1 || userInput > 6){
                system("clear");
                cout << "Invalid Input" << endl;
            }
            else {
                // display results according to userinput
                switch (userInput) {
                    case 1:
                        system("clear");
                        cout << "Your choice was 1" << endl;
                        total = totalCost(lineItem, size);
                        cout << "Total cost of inventory: $" << total << endl;
                        break;
                    case 2:
                        system("clear");
                        cout << "Your choice was 2" << endl;
                        countByClass(lineItem, classCounts, size);
                        displayCounts(classCounts);
                        break;
                    case 3:
                        system("clear");
                        cout << "Your choice was 3" << endl;
                        cout << "Which class?" << endl;
                        cin >> cls;
                        cost = costForClass(cls, lineItem, size);
                        cout << "Cost of inventory for class " << cls << " is $" << cost << endl;
                        break;
                    case 4:
                        system("clear");
                        cout << "Your choice was 4" << endl;
                        highest = highestCost(lineItem, size);
                        cout << highest;
                        break;
                    case 5:
                        system("clear");
                        cout << "Your choice was 5" << endl;
                        lowest = lowestCost(lineItem, size);
                        cout << lowest;
                        break;
                }
            }
        }while(userInput != 6);
    }
    else{
        return 0;
    }
}
// reads file into vector of structs and returns true, else, notifies user and returns false
bool readFile(vector <Parts> &pVector, int& size){
    int i = 0;
    ifstream fin;
    fin.open("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment14/parts.txt");
    if(fin.fail()){
        cout << "Unable to read file!";
        return false;
    }
    else{
        while(fin >> pVector[i].number >> pVector[i].cls >> pVector[i].ohb >> pVector[i].cost){
            i++;
        }
        size = i;
        return true;
    }

}
// display menu to user
int displayMenu(){
    cout << "1. Total cost of inventory" << endl;
    cout << "2. A count of parts of each class" << endl;
    cout << "3. Cost of inventory for a class" << endl;
    cout << "4. Part with the highest cost of inventory" << endl;
    cout << "5. Part with the lowest cost of inventory" << endl;
    cout << "6. Exit" << endl;
}
// calculate total cost for each part class
double totalCost(const vector <Parts> &pVector, int size){
    double totalCost = 0;
    for(int i = 0; i < size; i++){
        totalCost += pVector[i].ohb * pVector[i].cost;
    }
    return totalCost;
}
// loop through each struct in vector and increment classCount vector accordingly, [0] = A, [1] = B, [2] = C, etc.
void countByClass(const vector <Parts> &pVector, vector <int> &classCounts, int size){
    for(int i = 0; i < size; i++){
        if(pVector[i].cls == 65){
            classCounts[0]++;
        }
        else if(pVector[i].cls == 66){
            classCounts[1]++;
        }
        else if(pVector[i].cls == 67){
            classCounts[2]++;
        }
        else if(pVector[i].cls == 68){
            classCounts[3]++;
        }
        else if(pVector[i].cls == 69){
            classCounts[4]++;
        }
        else if(pVector[i].cls == 70){
            classCounts[5]++;
        }
    }
}
double costForClass(char classIn, const vector <Parts> &pVector, int size){
    double cost = 0;
    for(int i = 0; i < size; i++){
        if(pVector[i].cls == classIn){
            cost += pVector[i].cost * pVector[i].ohb;
        }
    }
    return cost;
}
// set first part to highest cost and see if the next part is higher cost, if so, set next to highest
string highestCost(const vector <Parts> &pVector, int size){
    string partNo, output;
    double highestCost = pVector[0].ohb * pVector[0].cost;
    for(int i = 1; i < size; i++){
        if(pVector[i].ohb * pVector[i].cost > highestCost){
            partNo = pVector[i].number;
            highestCost = pVector[i].ohb * pVector[i].cost;
        }
    }
    output = "The part with the highest cost of inventory is " + partNo + "\n";
    return output;
}
// set first part to lowest cost and see if the next part in loop is lower cost, if so, set next to lowest
string lowestCost(const vector <Parts> &pVector, int size){
    string partNo, output;
    double lowestCost = pVector[0].ohb * pVector[0].cost;
    for(int i = 1; i < size; i++){
        if(pVector[i].ohb * pVector[i].cost < lowestCost){
            partNo = pVector[i].number;
            lowestCost = pVector[i].ohb * pVector[i].cost;
        }
    }
    output = "The part with the lowest cost of inventory is " + partNo + "\n";
    return output;
}
// display counts to user
void displayCounts(const vector <int> & classCounts){
    cout << "A" << setw(10) << classCounts[0] << endl;
    cout << "B" << setw(10) << classCounts[1] << endl;
    cout << "C" << setw(10) << classCounts[2] << endl;
    cout << "D" << setw(10) << classCounts[3] << endl;
    cout << "E" << setw(10) << classCounts[4] << endl;
    cout << "F" << setw(10) << classCounts[5] << endl;
}
/* Sample Execution:
1. Total cost of inventory
2. A count of parts of each class
3. Cost of inventory for a class
4. Part with the highest cost of inventory
5. Part with the lowest cost of inventory
6. Exit
0
Invalid Input
1. Total cost of inventory
2. A count of parts of each class
3. Cost of inventory for a class
4. Part with the highest cost of inventory
5. Part with the lowest cost of inventory
6. Exit
1
Your choice was 1
Total cost of inventory: $342965.70
1. Total cost of inventory
2. A count of parts of each class
3. Cost of inventory for a class
4. Part with the highest cost of inventory
5. Part with the lowest cost of inventory
6. Exit
2
Your choice was 2
A        85
B        69
C        77
D        60
E        17
F        14
1. Total cost of inventory
2. A count of parts of each class
3. Cost of inventory for a class
4. Part with the highest cost of inventory
5. Part with the lowest cost of inventory
6. Exit
3
Your choice was 3
Which class?
A
Cost of inventory for class A is $191180.07
1. Total cost of inventory
2. A count of parts of each class
3. Cost of inventory for a class
4. Part with the highest cost of inventory
5. Part with the lowest cost of inventory
6. Exit
4
Your choice was 4
The part with the highest cost of inventory is P-27850
1. Total cost of inventory
2. A count of parts of each class
3. Cost of inventory for a class
4. Part with the highest cost of inventory
5. Part with the lowest cost of inventory
6. Exit
5
Your choice was 5
The part with the lowest cost of inventory is P-30538
1. Total cost of inventory
2. A count of parts of each class
3. Cost of inventory for a class
4. Part with the highest cost of inventory
5. Part with the lowest cost of inventory
6. Exit
6

Process finished with exit code 0
*/
