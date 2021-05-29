//Author:	        Robert Myers, rfm5594, World Campus
//Class:      	    CMPSC 121
//Activity:   	    05
//File:             /Users/robertmyers/OneDrive - The Pennsylvania State University/Summer 2021/CMPSC121/Activity5.cpp
//Purpose: 	        Integer Division
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
int main() {
    // variable declaration
    int shareCount;
    float purchasePrice, commissionRate, salePrice,
    purchaseCost, purchaseCommissionCost, totalPurcahseCost,
    salesRevenue, saleCommission, saleCost, totalProfitOrLoss;

    // user prompt
    cout << "Enter number of shares purchased, purchase price of stock, commission rate, and salesprice:" << endl;

    // read in values from user
    cin >> shareCount >> purchasePrice >> commissionRate >> salePrice;

    // arithmetic
    purchaseCost = shareCount * purchasePrice;
    purchaseCommissionCost = commissionRate * purchaseCost;
    totalPurcahseCost = purchaseCost + purchaseCommissionCost;
    cout << "    ************ TRANSACTION DETAILS *************" << endl;

    cout << purchaseCost << endl << purchaseCommissionCost << endl << totalPurcahseCost;

    return 0;
}
