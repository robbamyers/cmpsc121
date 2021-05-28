#include <iostream>
using namespace std;

int main() {
    // variable declaration
    int intOne, intTwo, intThree, intFour, intFive;
    double average;

    // input 5 integers
    cout << "Enter 5 integers: \n";
    cin >> intOne >> intTwo >> intThree >> intFour >> intFive;

    // arithmetic of average
    average = (intOne + intTwo + intThree + intFour + intFive) / 5.0;

    // display output to user
    cout << "The average is: " << average;
}

/*
    Execution Sample

    Enter 5 integers:
    982
    234
    1
    45
    2
    The average is: 252.8
*/
