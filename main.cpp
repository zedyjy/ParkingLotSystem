//
// Created by zeyne on 30.03.2022.
//
#include <iostream>
using namespace std;
#include "ParkingSystem.h"
int main(){

    ParkingSystem L;
    L.listLots();
    // Testing add parking lot
    cout << endl;
    cout << "Testing add parking lots" << endl;
    cout << endl;

    L.createLot(376, 8, 6);
    L.createLot(424, 12,12);
    L.createLot(333, 5, 6);
    cout << endl;
    L.createLot(333, 4, 7);
    L.createLot(212, 13, 5);
    L.createLot(424, 14, 14);
    cout << endl;
    L.createLot(467, 6, 6);
    L.createLot(555, 9, 7);


    cout << endl;
    L.listLots();
    cout << endl;
    // Testing remove parking lot
    cout << endl;
    cout << "Testing remove parking lot" << endl;
    cout << endl;
    L.removeLot(424);
    L.removeLot(999);
    L.removeLot(333);
    cout << endl;
    L.removeLot(135);
    L.createLot(111, 6, 7);
    cout << endl;
    // Testing park car
    cout << endl;
    cout << "Testing park a car" << endl;
    cout << endl;
    L.parkCar( 376, "B5", "b", 711);
    L.parkCar( 376, "E1", "a", 171);
    L.parkCar( 376, "C3", "b", 188);
    cout << endl;
    L.parkCar( 376, "F3", "a", 200);
    L.parkCar( 376, "G1", "b", 888);
    L.parkCar( 467, "B4", "b", 734);
    L.parkCar( 467, "C4", "a", 900);
    cout << endl;
    L.parkCar( 477, "C3", "a", 557);
    L.parkCar( 467, "C3", "a", 170);
    L.parkCar( 466, "C3", "b", 177);
    cout << endl;
    L.parkCar( 111, "B1", "a", 434);
    L.parkCar( 111, "B4", "b", 589);
    L.parkCar( 111, "C4", "b", 360);
    cout << endl;
    L.listLots();
    cout << endl;
    // Testing find car
    cout << endl;
    cout << "Testing find a car" << endl;
    cout << endl;
    L.findCar(711);
    L.findCar(900);
    L.findCar(589);
    cout << endl;
    L.findCar(434);
    L.findCar(360);
    L.findCar(557);
    cout << endl;
    // Testing show lot contents
    cout << endl;
    cout << "Testing show lot contents" << endl;
    cout << endl;
    L.lotContents(376);
    cout << endl;
    L.lotContents(467);
    cout << endl;
    L.lotContents(555);
    cout << endl;
    L.lotContents(111);
    cout << endl;
    // Testing remove car
    cout << endl;
    cout << "Testing remove car" << endl;
    cout << endl;
    L.removeCar(900);
    L.removeCar(589);
    cout << endl;
    L.removeCar(170);
    L.removeCar(177);
    L.removeCar(557);
    cout << endl;
    cout << "Testing remove car, again, this time with cars in the lot " << endl;
    cout << "Notice how first cars are deleted " << endl;
    cout << endl;
    L.removeLot(376);
    cout << endl;
    return 0;
}
