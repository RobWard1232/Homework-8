//Author: Robert Ward
//For Homework 8
//Purpose: to calculate the the price of a job using square footage.


#include <iostream>

using namespace std;

double calculateWallCost(double sf) {
    const double wallRate = 2.5;
    const double laborRate = 40.0;

    double totalCost = (sf / 200.0) * wallRate * laborRate;
    return totalCost;
}

double calculateCeilingCost (double sf) {
    const double ceilingRate = 3.2;
    const double laborRate = 40.0;

    double totalCost = (sf / 200.0) * ceilingRate * laborRate;
    return totalCost;
}

double calculateFloorCost(double squareFootage,  string floorType) {
    double laborRate;
    double hoursPer100SF;

    if (floorType == "Wood") {
        laborRate = 48.0;  // $ per hour
        hoursPer100SF = 2.0;
    } else if (floorType == "Tile") {
        laborRate = 52.0;  // $ per hour
        hoursPer100SF = 2.8;
    } else {
        laborRate = 30.0;  // $ per hour
        hoursPer100SF = 1.7;
    }

    double totalCost = (squareFootage / 100.0) * hoursPer100SF * laborRate;
    return totalCost;
}

double calculateTotalCost(double wallSquareFootage, double ceilingSquareFootage, double floorSquareFootage,  string floorType) {
    double wallCost = calculateWallCost(wallSquareFootage);
    double ceilingCost = calculateCeilingCost(ceilingSquareFootage);
    double floorCost = calculateFloorCost(floorSquareFootage, floorType);

    // Apply the discount for wall square footage above 1400 SF
    if (wallSquareFootage > 1400.0) {
        double discount = (wallSquareFootage - 1400.0) * 0.15 * 2.5 * 40.0;
        wallCost -= discount;
    }

    double totalCost = wallCost + ceilingCost + floorCost;
    return totalCost;
}

int main() {
int wallSF, ceilingSF, floorSF;
string input, floorType;

while (true) {

    cout << "Enter the square footage of walls: ";
    cin >> wallSF;

    cout << "Enter the square footage of ceilings: ";
    cin >> ceilingSF;

     cout << "Enter the square footage of flooring: ";
     cin >> floorSF;

     cout << "Enter the floor type (Wood, Tile, Other): ";
     cin >> floorType;

    double totalCost = calculateTotalCost(wallSF, ceilingSF, floorSF, floorType);

    cout << "Wall cost: $" << calculateWallCost(wallSF) << endl;

    cout << "Ceiling cost: $" << calculateCeilingCost(ceilingSF) << endl;

    cout << "Flooring cost: $" << calculateFloorCost(floorSF, floorType) << endl;

    cout << "Total cost: $" << totalCost <<  endl;

    return 0;

    if (input != "y" || input != "Y") {
        break;
    }
}
return 0;
}