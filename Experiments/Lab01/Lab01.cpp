//Author:       Robert Myers, rfm5594
//Class:        CMPSC 121
//Experiment:   01
//File:         /OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Experiments/Lab01/Lab01.cpp
//Purpose:      Getting acquainted with the V.S. development environment

#include <iostream>
using namespace std;
int main() {
    double length, width, height, volume, surface;
    cout << "Enter length, width and height in inches: ";
    cin >> length >> width >> height;
    volume = length * width * height;   // enter appropriate formula here
    surface = (2 * length * width) + (2 * length * height) + (2 * height * width);   // enter appropriate formula here
    cout << "For a box with length = " << length << ", width = " << width << ", height = " << height << endl;
    cout << "the volume is " << volume << " cubic inches and the surface is " << surface << " square inches" << endl;
    return 0;

/*  Execution Sample:
Enter length, width and height in inches: 12
8
7
For a box with length = 12, width = 8, height = 7
the volume is 672 cubic inches and the surface is 472 square inches
 */
}