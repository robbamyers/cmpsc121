//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    10
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Activity10/Activity10.cpp
//Purpose: 	        Nested loop practice
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

int main() {

    int numDayOfWeek;
    string strDayOfWeek;
    char continuation;

    do
    {
        cout << "Enter a day of week value: ";
        cin >> numDayOfWeek;
        while(numDayOfWeek < 1 || numDayOfWeek > 7) {
            cout << numDayOfWeek << " is invalid" << endl;
            cout << "Enter a day of week value: ";
            cin >> numDayOfWeek;
        }
        if(numDayOfWeek == 1){
            cout << "Sunday" << endl;
        }
        else if (numDayOfWeek == 2){
            cout << "Monday" << endl;
        }
        else if (numDayOfWeek == 3){
            cout << "Tuesday" << endl;
        }
        else if (numDayOfWeek == 4){
            cout << "Wednesday" << endl;
        }
        else if (numDayOfWeek == 5){
            cout << "Thursday" << endl;
        }
        else if (numDayOfWeek == 6){
            cout << "Friday" << endl;
        }
        else if (numDayOfWeek == 7){
            cout << "Saturday" << endl;
        }
        cout << "Do you wish to continue?" << endl;
        cin >> continuation;
    } while (toupper(continuation) == 'Y');
    cout << "Program terminated. Thanks for using the Day of the Week converter!";
    return 0;
}
/* Sample Execution:
Enter a day of week value: 12
12 is invalid
Enter a day of week value: 5
Thursday
Do you wish to continue?
y
Enter a day of week value: 2
Monday
Do you wish to continue?
n
Program terminated. Thanks for using the Day of the Week converter!
Process finished with exit code 0
*/