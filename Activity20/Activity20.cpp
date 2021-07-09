//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:         20
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity20/Activity20.cpp
//Purpose: 	        Practice with recursive functions
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
// function prototype
void reverse(string s, int i);

int main() {
    // variable declaration and read in string value
    string strIn;
    cout << "Enter a string" << endl;
    getline(cin, strIn);
    // function call to reverse string
    reverse(strIn, strIn.length());
    return 0;
}

void reverse(string s, int i){
    // base case
    if (i != 0){
        // display the character one less than length. .length() member function counts from 1
        cout << s[i-1];
        // call reverse again but pass in the character prior to this run to display
        reverse(s,i-1);
    }
}