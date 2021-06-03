//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    08
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/cmpsc121/Activity8/Activity08.cpp
//Purpose: 	        Use conditional logic to display where a Cartesian coordinate resides
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
using namespace std;

int main() {
    // variable declaration
    int x, y ;
    char decision;
    // user prompt
    cout << "Please enter an integer coordinate: x, y" << endl;
    // read in x and y coordinates from user
    cin >> x >> y;
    // possible coordinate locations and assignment for switch
    if (x == 0 && y == 0) {             // origin
        decision = 'a';
    }
    else if (x==0 && !(y==0)){          // y-axis
        decision = 'b';
    }
    else if (!(x==0) && y==0){          // x-axis
        decision = 'c';
    }
    else if (x>0 && y>0){               // quadrant 1
        decision = 'd';
    }
    else if (x<0 && y>0){               // quadrant 2
        decision = 'e';
    }
    else if (x<0 && y<0){               // quadrant 3
        decision = 'f';
    }
    else if (x>0 && y<0){               // quadrant 4
        decision = 'g';
    }
    // conditionally display output based on decision
    switch(decision){
        case 'a': cout << "This point is the origin"; break;
        case 'b': cout << "This point is on the y-axis"; break;
        case 'c': cout << "This point is on the x-axis"; break;
        case 'd': cout << "This point is in quadrant 1"; break;
        case 'e': cout << "This point is in quadrant 2"; break;
        case 'f': cout << "This point is in quadrant 3"; break;
        case 'g': cout << "This point is in quadrant 4"; break;
    }
}

/* Sample Execution:
Please enter an integer coordinate: x, y
0 3
This point is on the y-axis
Process finished with exit code 0
 */