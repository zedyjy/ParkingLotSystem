//
// Created by zeyne on 13.03.2022.
//

#ifndef UNTITLED_PARKINGSYSTEM_H
#define UNTITLED_PARKINGSYSTEM_H

using namespace std;
#include <iostream>
#include "ParkingLot.h"
#include "Car.h"

class ParkingSystem {
public:
    ParkingSystem();

    ~ParkingSystem();

    void createLot(int id, int rows, int columns);

    void removeLot(int id);

    void listLots();

    void lotContents(int id);

    void parkCar(int lotId, string location, string carType, int plateNumber);

    void findCar(int plateNumber);

    void removeCar(int plateNumber);

    bool isCarHere(int plateNum);
// ...
//you may define additional member functions and data members, if necessary
private:
    int maxSize;
    ParkingLot **lots;
    int carNums;
};
#endif //UNTITLED_PARKINGSYSTEM_H
