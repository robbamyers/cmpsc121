//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:              10
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment10/Experiment10.cpp
//Purpose: 	        This experiment is designed to develop confidence with functions.
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
#include <iomanip>
#include <string>
using namespace std;
const double INCHESINLINEARFOOT = 12.0;
const double INCHESINONESQUAREFOOT = 144.0;
const double PINECOST = 0.89;
const double FIRCOST = 1.09;
const double CEDARCOST = 2.26;
const double MAPLECOST = 4.40;
const double OAKCOST = 3.10;

bool validateType(char t);
// Return true if t represents a valid wood type or false otherwise
double calcBoardFeet(double th, double wid, double len);
// calculate board feet where th = thickness in inches,
// wid = width in inches and len = length in feet
double calcCost(char type, int numP, double bf);
// calculate cost based on type, number of pieces and board feet
string getTypeName(char type);
// return name of wood type based on char representing type, eg P = Pine
void getData(char & woodType, int & numPieces, double &thickness,
             double & width,  double & length);
// Get data on sale
int main()
{
    char woodType, reply;
    int numPieces;
    double thickness, width, length;
    double cost, totalCost, boardFeet;
    string woodTypeName;
    cout << fixed << setprecision(2);
    do
    {
        totalCost = 0;
        do
        {
            getData(woodType, numPieces, thickness, width, length);
            if (woodType != 'T')
            {
                boardFeet = calcBoardFeet(thickness, width, length);
                cost = calcCost(woodType, numPieces, boardFeet);
                woodTypeName = getTypeName(woodType) + ", cost: $";
                cout << setw(3) << numPieces << setw(6) << thickness << " X " << setw(6) << width << " X " << setw(6) << length << " " << setw(14)<< woodTypeName << cost << endl;
                totalCost+= cost;
            }
        }while (toupper(woodType) != 'T');
        cout << "Total cost: $" << totalCost << endl;
        cout << "More purchases?" << endl;
        cin >> reply;
    }while (toupper(reply) == 'Y');
}


bool validateType(char t){
    if(t != 'P' && t != 'F' && t != 'C' && t != 'M' && t != 'O' && t != 'T'){
        cout << t << " is not valid. Reenter:" << endl;
        return false;
    }
    return true;
}
double calcBoardFeet(double th, double wid, double len){
    double boardFeet = (th * wid * len)/INCHESINLINEARFOOT;
    return boardFeet;
}
double calcCost(char type, int numP, double bf){
    double cost = 0;
    switch (type) {
        case 'P': cost = (PINECOST * numP * bf); break;
        case 'F': cost = (FIRCOST * numP * bf); break;
        case 'C': cost = (CEDARCOST * numP * bf); break;
        case 'M': cost = (MAPLECOST * numP * bf); break;
        case 'O': cost = (OAKCOST * numP * bf); break;
    }
    return cost;
}
string getTypeName(char type){
    string name;
    switch (type) {
        case 'P': name = "Pine"; break;
        case 'F': name = "Fir"; break;
        case 'C': name = "Cedar"; break;
        case 'M': name = "Maple"; break;
        case 'O': name = "Oak"; break;
    }
    return name;
}
void getData(char & woodType, int & numPieces, double &thickness,
             double & width,  double & length) {
    cout << "Enter item: ";
    do {
        cin >> woodType;
        woodType = toupper(woodType);
    } while (validateType(woodType) == false);
    if (woodType != 'T') {
        cout << "Enter number of pieces and thickness, width, and length:" << endl;
        cin >> numPieces >> thickness >> width >> length;
    }
}

/* Sample Execution:

Enter item: i
I is not valid. Reeneter
o
Enter numer of pieces and thickness width and length
100 2.5 3 20
100  2.50 X   3.00 X  20.00   Oak, cost: $3875.00
Enter item: p
Enter numer of pieces and thickness width and length
150 3 3.5 22
150  3.00 X   3.50 X  22.00  Pine, cost: $2569.88
Enter item: t
Total cost: $6444.88
More purchases?
n

Process finished with exit code 0
 */

