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
    cout << "Enter number of shares purchased, purchase price of stock, commission rate, and sale price:" << endl;

    // read in values from user
    cin >> shareCount >> purchasePrice >> commissionRate >> salePrice;

    // arithmetic
    purchaseCost = shareCount * purchasePrice;
    purchaseCommissionCost = commissionRate * purchaseCost;
    totalPurcahseCost = purchaseCost + purchaseCommissionCost;
    salesRevenue = shareCount * salePrice;
    saleCommission = commissionRate * salesRevenue;
    saleCost = salesRevenue + saleCommission;
    totalProfitOrLoss = saleCost - totalPurcahseCost;

    // display transaction details to user
    cout << "    ************ TRANSACTION DETAILS *************" << endl;
    cout << fixed << setprecision(2); // set precision to two decimal places
    cout << setw(35) << "Cost of stock before commission" << setw(5) << "$" << purchaseCost << endl;
    cout << setw(35) << "Commission on purchase" << setw(5) << "$" << purchaseCommissionCost << endl;
    cout << setw(35) << "Total cost of purchase" << setw(5) << "$" << totalPurcahseCost << endl;
    cout << endl;
    cout << setw(35) << "Sale revenue before commission" << setw(5) << "$" << salesRevenue << endl;
    cout << setw(35) << "Commissions on sale" << setw(5) << "$" << saleCommission << endl;
    cout << setw(35) << "Total cost of sale" << setw(5) << "$" << saleCost << endl;
    cout << endl;
    cout << setw(35) << "Profit or loss on sale" << setw(5) << "$" << totalProfitOrLoss;

    return 0;
}
/* Sample Execution:
Enter number of shares purchased, purchase price of stock, commission rate, and salesprice:
1000 23.12 .01 25.67
    ************ TRANSACTION DETAILS *************
    Cost of stock before commission    $23120.00
             Commission on purchase    $231.20
             Total cost of purchase    $23351.20

     Sale revenue before commission    $25670.00
                Commissions on sale    $256.70
                 Total cost of sale    $25413.30

             Profit or loss on sale    $2062.10
*/