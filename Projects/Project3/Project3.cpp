//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Project:   	    3
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Projects/Project3/Project3.cpp
//Purpose: 	        The Project focuses on the entirety of CMPSC 121
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
// Sources of logic assistance: Professor Yu for Shell Sort algorithm and binary search

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
struct inventory{
    string partNumber;
    char partClass;
    int partOhb;
    double partCost;
};
// fills vectors
bool get_data (vector<inventory> &v);
// Does a binary search
int bin_search(const string &key, const vector<inventory> &v);
// Asks user for a part number to search for
string get_target();
// gets remaining info to add a part number
void get_more_data(char& class_in,int& part_ohb_in,double& part_cost_in);
// Inserts part number data into vectors
void insert_data (vector<inventory> &v, string part_in, char class_in, int part_ohb_in, double part_cost_in);
// Displays info on part number
void display (const vector<inventory> &v, int finder);
// sorts vectors (Calls swapper)
void sort (vector<inventory> &v);
// prints search stats
void print_stats(int searches, int good, int bad);
// writes out file when program ends, so additions are saved to file
void put_data (const vector<inventory> &v);
// templated swap function – Swaps two items in a vector of any type
// Put this BEFORE main()  Called from sort function
template <class CType>
void swapper (CType& a, CType & b)
{
    CType temp;
    temp = a;
    a = b;
    b= temp;
}

int main() {
    // declare vector of structs
    vector<inventory> lineItem;
    // check for file open failure, else get data
    if(!get_data(lineItem)){
        cout << "Problem opening the file." << endl;
    }
    else{
        char continuation;
        int unsuccessfulSearch = 0, successfulSearch = 0;
        // continuation loop
        do{
            string target;
            cout << "What part number would you like to look for?" << endl;
            target = get_target();
            // sort prior to binary search
            sort(lineItem);
            int finder = bin_search(target,lineItem);
            if(finder == -1){
                unsuccessfulSearch++;
                char addPartDecision;
                do{
                    cout << "Add this part?" << endl;
                    cin >> addPartDecision;
                    if(toupper(addPartDecision) != 'Y' && toupper(addPartDecision) != 'N'){
                        cout << "Invalid input!" << endl;
                    }
                }while(toupper(addPartDecision) != 'Y' && toupper(addPartDecision) != 'N');
                if(toupper(addPartDecision) == 'Y'){
                    char class_in;
                    int part_ohb_in;
                    double part_cost_in;
                    get_more_data(class_in,part_ohb_in,part_cost_in);
                    insert_data(lineItem, target, class_in, part_ohb_in, part_cost_in);
                }
                cout << "Would you like to do another search? <Y or N>" << endl;
                cin >> continuation;
                cin.ignore(1);
            }
            else{
                successfulSearch++;
                display(lineItem, finder);
                // clear target value
                target = "";
                cout << "Would you like to do another search? <Y or N>" << endl;
                cin >> continuation;
                cin.ignore(1);
            }
        }while(toupper(continuation) == 'Y');
        int total = unsuccessfulSearch + successfulSearch;
        print_stats(total, successfulSearch, unsuccessfulSearch);
        sort(lineItem);
        put_data(lineItem);
        cout << "Files were updated";
    }
    return 0;
}
bool get_data (vector<inventory> &v){
    fstream fin;
    fin.open("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Projects/Project3/parts.txt");
    if(fin.fail()){
        return false;
    }
    else{
        inventory temp;
        while(fin >> temp.partNumber >> temp.partClass >> temp.partOhb >> temp.partCost){
            v.push_back(temp);
        }
        fin.close();
        return true;
    }
}
string get_target(){
    string target;
    getline(cin, target);
    cin.ignore(0,'\n');
    return target;
}
int bin_search(const string &key, const vector<inventory> &v){
    bool found = false;
    int first, mid, last, return_val;
    first = 0;
    last = v.size()-1;
    while((first <= last) && (!found)){
        mid = (first + last) / 2;
        if (key == v[mid].partNumber)
            found = true;
        else
            if (key < v[mid].partNumber)
                last = mid - 1;
            else
                first = mid + 1;
    }
    if(found)
        return_val = mid;
    else
        return_val = -1;
    return return_val;
}
void display (const vector<inventory> &v, int finder){
    cout << "There are " << v[finder].partOhb << " of Part Number " << v[finder].partNumber << " in inventory. It is a class " << v[finder].partClass << " part.\n";
    cout << "The cost is $" << v[finder].partCost << endl;
    cout << "The value is $" << double(v[finder].partOhb * v[finder].partCost) << endl;
}
void get_more_data(char& class_in,int& part_ohb_in,double& part_cost_in){
    cout << "What class is this part number in?" << endl;
    cin >> class_in;
    cout << "What is the on hand balance of this part?" << endl;
    cin >> part_ohb_in;
    cout << "What is the cost of this part?" << endl;
    cin >> part_cost_in;
}
void insert_data (vector<inventory> &v, string part_in, char class_in, int part_ohb_in, double part_cost_in){
    inventory temp;
    temp.partNumber = part_in;
    temp.partClass = class_in;
    temp.partOhb = part_ohb_in;
    temp.partCost = part_cost_in;
    v.push_back(temp);
}
void print_stats(int searches, int good, int bad){
    cout << "There were " << searches << " searched performed today." << endl;
    cout << good << " of them were successful" << endl;
    cout << bad << " of them were not in the system" << endl;
}
void sort (vector<inventory> &v){
    bool flag = true;
    int i;
    int d = v.size();
    while(flag ||(d>1)) // bool flag
        {
        flag = false;  //set flag to false
        d = (d+1) / 2;
        for (i = 0; i < (v.size() - d); i++){
            if (v[i+d].partNumber < v[i].partNumber){
                swapper(v[i+d].partNumber, v[i].partNumber);
                swapper(v[i+d].partClass, v[i].partClass);
                swapper(v[i+d].partOhb, v[i].partOhb);
                swapper(v[i+d].partCost, v[i].partCost);
                flag = true; //tells swap has occurred
            }
        }
        }
}
void put_data (const vector<inventory> &v){
    for(int i = 0; i < v.size(); i++){
        ofstream fileOut;
        fileOut.open("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Projects/Project3/parts.txt");
        for(int i = 0; i < v.size(); i++){
            fileOut << v[i].partNumber << " " << v[i].partClass << " " << v[i].partOhb << " " << v[i].partCost << endl;
        }
    }
}

/* Sample Execution:
What part number would you like to look for?
P-13682
There are 14 of Part Number P-13682 in inventory. It is a class D part.
The cost is $25.56
The value is $357.84
Would you like to do another search? <Y or N>
y
What part number would you like to look for?
P-14702
There are 38 of Part Number P-14702 in inventory. It is a class A part.
The cost is $92.06
The value is $3498.28
Would you like to do another search? <Y or N>
y
What part number would you like to look for?
P-38806
There are 42 of Part Number P-38806 in inventory. It is a class C part.
The cost is $31.39
The value is $1318.38
Would you like to do another search? <Y or N>
y
What part number would you like to look for?
P-00008
Add this part?
y
What class is this part number in?
A
What is the on hand balance of this part?
12
What is the cost of this part?
3.4
Would you like to do another search? <Y or N>
y
What part number would you like to look for?
P-00007
Add this part?
y
What class is this part number in?
B
What is the on hand balance of this part?
56
What is the cost of this part?
7.8
Would you like to do another search? <Y or N>
y
What part number would you like to look for?
P-00001
Add this part?
y
What class is this part number in?
C
What is the on hand balance of this part?
99
What is the cost of this part?
99.99
Would you like to do another search? <Y or N>
n
There were 6 searched performed today.
3 of them were successful
3 of them were not in the system

Process finished with exit code 0
 */