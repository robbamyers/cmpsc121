//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Lab:   	        04
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Experiments/Experiment04/experiment04.cpp
//Purpose: 	        Using if/else statements to display conditional results
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
using namespace std;
const double CAR_FIRST_RATE = 1.25, CAR_SECOND_RATE = 1.50, TRUCK_FIRST_RATE = 2.75,
             TRUCK_SECOND_RATE = 3.75, BUS_FIRST_RATE = 9.50, BUS_SECOND_RATE = 6.75;
const int CAR_RATE_LIMIT = 2, TRUCK_RATE_LIMIT = 2, BUS_RATE_LIMIT = 1;

int main() {

    // variable declaration
    char vehicleType;
    int hoursParked;
    double amountDue = 0;
    string invoice = "Crunchum Parking Lots, Inc.\n\"We usually find your vehicle!\"\n================================\n";


    // prompt user for type
    cout << "Please enter your vehicle type <Car = C, Truck = T, Bus = B>" << endl;

    // read in car type
    cin >> vehicleType;

    // prompt user for hours parked
    cout << "Thank you. Now, how many hours were you parked?" << endl;

    // read in hoursParked
    cin >> hoursParked;

    // display ticket header
    cout << invoice;


    // conditional
    cout << fixed << setprecision(2);
    if (vehicleType == 'C') {
        cout << setw(15) << "Vehicle Type:" << setw(12) << "Car" << endl;
        if(hoursParked <= 2){
            amountDue = hoursParked * CAR_FIRST_RATE;
            cout << setw(15) << "Time:" << setw(10) << hoursParked << " Hour(s)" << endl;
            cout << setw(15) << "Amount Due:" << setw(10) << "$" << amountDue << endl;
            cout << "================================";
        }
        else {
            amountDue = (CAR_FIRST_RATE * 2) + ((hoursParked - 2) * CAR_SECOND_RATE);
            cout << setw(15) << "Time:" << setw(10) << hoursParked << " Hour(s)" << endl;
            cout << setw(15) << "Amount Due:" << setw(10) << "$" << amountDue << endl;
            cout << "================================";
        }
    }
    else if (vehicleType == 'T') {
        cout << setw(15) << "Vehicle Type:" << setw(15) << "Truck" << endl;
        if(hoursParked <= 2){
            amountDue = hoursParked * TRUCK_FIRST_RATE;
            cout << setw(15) << "Time:" << setw(12) << hoursParked << " Hour(s)" << endl;
            cout << setw(15) << "Amount Due:" << setw(11) << "$" << amountDue << endl;
            cout << "================================";
        }
        else {
            amountDue = (TRUCK_FIRST_RATE * 2) + ((hoursParked - 2) * TRUCK_SECOND_RATE);
            cout << setw(15) << "Time:" << setw(12) << hoursParked << " Hour(s)" << endl;
            cout << setw(15) << "Amount Due:" << setw(11) << "$" << amountDue << endl;
            cout << "================================";
        }
    }
    else if (vehicleType == 'B') {
        cout << setw(15) << "Vehicle Type:" << setw(12) << "Bus" << endl;
        if(hoursParked <= 1){
            amountDue = hoursParked * BUS_FIRST_RATE;
            cout << setw(15) << "Time:" << setw(10) << hoursParked << " Hour(s)" << endl;
            cout << setw(15) << "Amount Due:" << setw(10) << "$" << amountDue << endl;
            cout << "================================";
        }
        else {
            amountDue = (BUS_FIRST_RATE * 1) + ((hoursParked - 1) * BUS_SECOND_RATE);
            cout << setw(15) << "Time:" << setw(10) << hoursParked << " Hour(s)" << endl;
            cout << setw(15) << "Amount Due:" << setw(10) << "$" << amountDue << endl;
            cout << "================================";
        }
    }

    return 0;
}

/*
Sample Execution 1:
Please enter your vehicle type <Car = C, Truck = T, Bus = B>
C
Thank you. Now, how many hours were you parked?
7
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
================================
  Vehicle Type:         Car
          Time:         7 Hour(s)
    Amount Due:         $10.00
================================
Process finished with exit code 0


Sample Execution 2:
Please enter your vehicle type <Car = C, Truck = T, Bus = B>
T
Thank you. Now, how many hours were you parked?
10
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
================================
  Vehicle Type:          Truck
          Time:          10 Hour(s)
    Amount Due:          $35.50
================================
Process finished with exit code 0


Sample Execution 3:
Please enter your vehicle type <Car = C, Truck = T, Bus = B>
Bus 8
Thank you. Now, how many hours were you parked?
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
================================
  Vehicle Type:         Bus
          Time:         0 Hour(s)
    Amount Due:         $0.00
================================
Process finished with exit code 0
*/