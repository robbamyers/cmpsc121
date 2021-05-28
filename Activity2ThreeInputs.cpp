#include <iostream>
using namespace std;

int main() {
    int inputOne, inputTwo, inputThree;
    float answer;

    cout << "Add and Divide -- A program which takes three numbers, sums the first two and divides by the third number\n";

    cout << "Please provide the first number: ";
    cin >> inputOne;

    cout << "Please provide the second number: ";
    cin >> inputTwo;

    cout << "Please provide the third number: ";
    cin >> inputThree;

    answer = (inputOne + inputTwo)/inputThree;

    cout << "The answer is: " << answer;
}
