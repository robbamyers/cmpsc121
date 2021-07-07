//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    18
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Activity18/Activity18.cpp
//Purpose: 	        Practice manipulating strings
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
#include <string>
using namespace std;

// function prototypes
void getFirstMidLast(string& name);
void findSpaces(string& name, int& spacePosition1, int& spacePosition2);
void capitalize(string& name, int spacePosition1, int spacePosition2);
string reorder(string name, int spacePosition1, int spacePosition2);
void continuation(char& continuation);

int main(){
    char continueInput;
    do {
        string name, stylizedName;
        int spacePosition1, spacePosition2;
        getFirstMidLast(name);
        findSpaces(name, spacePosition1, spacePosition2);
        capitalize(name, spacePosition1, spacePosition2);
        stylizedName = reorder(name, spacePosition1, spacePosition2);
        cout << " it was converted to: " << stylizedName << endl;
        continuation(continueInput);
    }while(toupper(continueInput) == 'Y');
}

// read in name from user
void getFirstMidLast(string& name){
    cout << "Enter first, mi, last:" << endl;
    getline(cin, name);
    cout << "You entered " << name;
}

// assume there will only be two total spaces in user input between the three words. use string find to find those positions
void findSpaces(string& name, int& spacePosition1, int& spacePosition2){
    int pos = 0;
        for(int i = 0; i < 2; i++){
            pos = name.find(' ',pos + 1);
            if(i == 0){
                spacePosition1 = pos;
            }
            else if(i == 1){
                spacePosition2 = pos;
            }
        }
}

// capitalize the characters that occur at the first char position in name and after each space
void capitalize(string& name, int spacePosition1, int spacePosition2){
    name[0] = toupper(name[0]);
    name[spacePosition1 + 1] = toupper(name[spacePosition1 + 1]);
    name[spacePosition2 + 1] = toupper(name[spacePosition2 + 1]);
}

// find the length of each name part using the space position to determine where the part starts/stops
string reorder(string name, int spacePosition1, int spacePosition2){
    int firstNameLength = spacePosition1;
    int middleInitialLength = spacePosition2 - spacePosition1;
    int lastNameLength = name.length() - spacePosition2;
    string stylizedName;

    string firstName =  name.substr(0, firstNameLength),
    lastName = name.substr(spacePosition2 + 1, lastNameLength),
    middleInitial = name.substr(spacePosition1 + 1, middleInitialLength);
    stylizedName = lastName + ", " + firstName + " " + middleInitial;
    return stylizedName;
}

// ask the user if they would like to continue entering names
void continuation(char& continuation){
    cout << "Would you like to enter another name? Y/N" << endl;
    cin >> continuation;
    cin.ignore();
}

/* Sample Execution:
Enter first, mi, last:
robbie a myers
You entered robbie a myers it was converted to: Myers, Robbie A
Would you like to enter another name? Y/N
Y
Enter first, mi, last:
jessica s. ortiz
You entered jessica s. ortiz it was converted to: Ortiz, Jessica S.
Would you like to enter another name? Y/N
N

Process finished with exit code 0
 */




