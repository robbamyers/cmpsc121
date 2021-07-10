//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:              11
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment11/Experiment11.cpp
//Purpose: 	        This experiment is designed to develop confidence with string functions.
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
#include <fstream>
using namespace std;

string fixName (string n);
//takes in the name and returns it in the right format
string fixSSN (string ss);
//Fixes SSN
string fixPhone(string ph);
// Fixes phone number
string fixAddress(string addr);
//Fixes address
string fixCity(string cty);
// Fixes city
string fixState(string st);
// Fixes state
string extractField(string &s);
//Extracts a field eg name from the input string and then deletes
// it and the octothorpe (#) that follows it. Notice string s is
// passed by reference
void buildLine(string &s, string field);
// Concatenates field and a comma to string s


int main() {
    // open file
    ifstream inputFile;
    inputFile.open("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment11/badnames.txt");
    // local scope variable declaration
    string field, n, ss, ph, addr, cty, st, s;
    // read in one line of the file as a string until the end of the file
    while(getline(inputFile,s)){
        buildLine(s, fixName(extractField(s)));
        buildLine(s, fixSSN(extractField(s)));
        buildLine(s, fixPhone(extractField(s)));
        buildLine(s, fixAddress(extractField(s)));
        buildLine(s, fixCity(extractField(s)));
        buildLine(s, fixState(extractField(s)));
        buildLine(s, extractField(s));
        // erase the comma at the end of the line
        s.erase(s.length()-1,1);
        cout << s << endl;
    }
    // close file
    inputFile.close();
    return 0;
}

string fixName (string n){
    int nameLength = n.length();
    int spaceLocation = n.find(" ",0);
    string firstName = n.substr(spaceLocation+1,nameLength);
    string lastName = n.substr(0,spaceLocation);
    firstName[0] = toupper(firstName[0]);
    lastName[0] = toupper(lastName[0]);
    string formattedName = lastName + "," + firstName;
    return formattedName;
}
string fixSSN (string ss){
    ss.insert(3,"-");
    ss.insert(6,"-");
    return ss;
}
string fixPhone(string ph){
    ph.insert(3,"-");
    ph.insert(7,"-");
    return ph;
}
string fixAddress(string addr){
    string formattedAddress;
    for(int i = 0; i < addr.length(); i++){
        if(addr[i] == ' '){
            formattedAddress += addr[i];
            addr[i+1] = toupper(addr[i+1]);
        }
        else{
            formattedAddress += addr[i];
        }
    }
    return formattedAddress;
}
string fixCity(string cty){
    cty[0] = toupper(cty[0]);
    return cty;
}
string fixState(string st){
    st[0] = toupper(st[0]);
    st[1] = toupper(st[1]);
    return st;
}
string extractField(string &s){
    string getField;
    if(s.find('#',0) != -1) {
        int firstPoundSign = s.find('#', 0);
        getField = s.substr(0, firstPoundSign);
        s.erase(0, firstPoundSign + 1);
    }
    else{
        getField = s.substr(0, 5);
        s.erase(0,5);
    }
    return getField;
}
void buildLine(string &s, string field){
    s += field + ",";
}
