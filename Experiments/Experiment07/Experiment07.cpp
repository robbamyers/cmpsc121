//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        07
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment07/Experiment07.cpp
//Purpose: 	        This experiment is designed to develop confidence with loops and reading text files.
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
using namespace std;
const string COUNT = "Count:", TOTAL_MILES = "Total Miles:", AVERAGE_MPG = "Average MPG:", VIN_BEST_MPG = "Vehicle ID with Best MPG:", VIN_WORST_MPG = "Vehicle ID with Worst MPG:";

int main() {
    // OPEN FILE
    ifstream fin("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment07/FleetInput.txt");
    // CHECK IF FILE IS READABLE
    if(fin.fail()){
        cout << "File is unreadable.";
    }
    else{
        // DECLARE VARIABLES TO HOLD VEHICLE ID, TRIP MILES, TRIP GALLONS, TRIP MPG, COUNTER, TOTAL MILES, TOTAL MPG, BEST MPG, WORST MPG
        string vin, bestMPGVin, worstMPGVin;
        float tripMiles, tripGallons, tripMPG, totalMiles, totalGallons, totalMPG, bestMPG, worstMPG = 999999999;
        int counter = 0;
        cout << fixed << setprecision(1);
        cout << "-------------------AMSCO Fleet Report-----------------------" << endl;
        cout << setw(15) << "Vehicle ID" << setw(15) << "Miles" << setw(15) << "Gallons" << setw(15) << "MPG" << endl;
        cout << "------------------------------------------------------------" << endl;
        // READ IN THREE VALUES UNTIL END OF FILE
        while(fin >> vin >> tripMiles >> tripGallons){
            tripMPG = tripMiles / tripGallons;
            cout << setw(15) << vin << setw(15) << tripMiles << setw(15) << tripGallons << setw(15) << tripMPG << endl;
            counter++;
            totalMiles += tripMiles;
            totalGallons += tripGallons;
            if(tripMPG > bestMPG){
                bestMPG = tripMPG;
                bestMPGVin = vin;
            }
            if(tripMPG < worstMPG){
                worstMPG = tripMPG;
                worstMPGVin = vin;
            }
        }
        totalMPG = totalMiles / totalGallons;

        cout << "------------------------------------------------------------" << endl;
        cout << COUNT << setw(20-COUNT.length()) << counter << endl;
        cout << TOTAL_MILES << setw(20-TOTAL_MILES.length()) << totalMiles << endl;
        cout << AVERAGE_MPG << setw(20-AVERAGE_MPG.length()) << totalMPG << endl;
        cout << VIN_BEST_MPG << setw(40-VIN_BEST_MPG.length()) << bestMPGVin << endl;
        cout << VIN_WORST_MPG << setw(40-VIN_WORST_MPG.length()) << worstMPGVin << endl;
    }
    // IN WHILE LOOP ITERATE COUNTER STARTING AT 1
    // ADD
    // CLOSE FILE
    return 0;
}
