//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Project:   	    3
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
#include <vector>
#include <iomanip>
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
void sort (vector <string>& part_number, vector <char>& part_class, vector <int>& part_ohb, vector <double>& part_cost);

// prints search stats
void print_stats(int searches, int good, int bad);

// writes out file when program ends, so additions are saved to file
void put_data (const vector <string>& part_number, const vector <char>& part_class, const vector <int>& part_ohb,
               const vector <double>& part_cost);

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
    vector<inventory> lineItem;
    if(!get_data(lineItem)){
        cout << "Problem opening the file." << endl;
    }
    else{
        char continuation;
        int unsuccessfulSearch = 0, successfulSearch = 0;
        do{
            string target;
            cout << "What part number would you like to look for?" << endl;
            target = get_target();
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
                target = "";
                cout << "Would you like to do another search? <Y or N>" << endl;
                cin >> continuation;
                cin.ignore(1);
            }
        }while(toupper(continuation) == 'Y');
        cout << "There were " << (unsuccessfulSearch + successfulSearch) << " searched performed today." << endl;
        cout << successfulSearch << " of them were successful" << endl;
        cout << unsuccessfulSearch << " of them were not in the system" << endl;
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
    int location = -1;
    for(int i = 0; i < v.size(); i++){
        if(key == v[i].partNumber){
            location = i;
        }
    }
    return location;
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


