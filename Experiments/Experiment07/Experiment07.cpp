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
    // open file
    ifstream fin("/Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment07/FleetInput.txt");

    // ensure file is readable
    if(fin.fail()){
        cout << "File is unreadable.";
    }
    else{
        // variable declaration. set worstMPG to an unlikely value to calculate worst MPG easier
        string vin, bestMPGVin, worstMPGVin;
        float tripMiles, tripGallons, tripMPG, totalMiles, totalGallons, averageMPG, bestMPG, worstMPG = 999999999;
        int counter = 0;

        // set precision to one decimal place
        cout << fixed << setprecision(1);

        // display prompt
        cout << "-------------------AMSCO Fleet Report-----------------------" << endl;
        cout << setw(15) << "Vehicle ID" << setw(15) << "Miles" << setw(15) << "Gallons" << setw(15) << "MPG" << endl;
        cout << "------------------------------------------------------------" << endl;

        // read in three values at a time, until end of file
        while(fin >> vin >> tripMiles >> tripGallons){
            // calculate trip mpg
            tripMPG = tripMiles / tripGallons;

            // display vin, miles, gallons, mpg for line
            cout << setw(15) << vin << setw(15) << tripMiles << setw(15) << tripGallons << setw(15) << tripMPG << endl;

            // increment counter and keep running total of miles and gallons
            counter++;
            totalMiles += tripMiles;
            totalGallons += tripGallons;

            // conditional to calculate trip with best/worst mpg
            if(tripMPG > bestMPG){
                bestMPG = tripMPG;
                bestMPGVin = vin;
            }
            if(tripMPG < worstMPG){
                worstMPG = tripMPG;
                worstMPGVin = vin;
            }
        }
        // calculate average mpg
        averageMPG = totalMiles / totalGallons;

        // display output to user
        cout << "------------------------------------------------------------" << endl;
        cout << COUNT << setw(20-COUNT.length()) << counter << endl;
        cout << TOTAL_MILES << setw(20-TOTAL_MILES.length()) << totalMiles << endl;
        cout << AVERAGE_MPG << setw(20-AVERAGE_MPG.length()) << averageMPG << endl;
        cout << VIN_BEST_MPG << setw(40-VIN_BEST_MPG.length()) << bestMPGVin << endl;
        cout << VIN_WORST_MPG << setw(40-VIN_WORST_MPG.length()) << worstMPGVin << endl;
    }
    // close file
    fin.close();

    return 0;
}
/* Sample Execution:
-------------------AMSCO Fleet Report-----------------------
     Vehicle ID          Miles        Gallons            MPG
------------------------------------------------------------
     279BX6KY2Z          582.2           20.5           28.4
     802MX8BZ4Q          723.6           25.1           28.8
     671AY6DZ3N          756.9           27.5           27.5
     845DH6AJ3B          660.2           25.4           26.0
     566GJ6KV2U          510.2           30.8           16.6
     109QW2RP2Y          301.2            8.3           36.3
     135TR4YC6H          387.6           12.2           31.8
     122AC6UG7P          228.9           14.7           15.6
     136VW8TD2Z          331.2           19.1           17.3
     448WQ2DX1M          543.9           33.6           16.2
     721GZ1LJ5N          629.8           27.9           22.6
     779FS3MB4Y          651.2           28.4           22.9
     553SB5LK8O          444.4           26.8           16.6
------------------------------------------------------------
Count:            13
Total Miles:  6751.3
Average MPG:    22.5
Vehicle ID with Best MPG:     109QW2RP2Y
Vehicle ID with Worst MPG:    122AC6UG7P

Process finished with exit code 0
 */