//
// Created by zeyne on 14.03.2022.
//

#ifndef UNTITLED_PARKINGLOT_H
#define UNTITLED_PARKINGLOT_H
#include "Car.h"
#include <iostream>
using namespace std;

class ParkingLot {
public:
    const static int numOfRow = 6;
    const static int numOfColumn = 7;
    ParkingLot(const long lotID, const int column,const int row);
    ParkingLot();
    ~ParkingLot();
    int getLotID();
    void setLotID(const int lotID);
    void setLotRow(const int row);
    int getLotRow();
    void setLotColumn(const int column);
    int getLotColumn();
    string getLots();
    int getTotalLotNum();
    void setLots(const int column,const int row);
    Car *** cars;
    void putCar(const int lotID, const string lotLocation,const string carType, const int carPlateNum);
    void putCarB(const int lotID, const string lotLocation,const string carType, const int carPlateNum);
    Car* giveCar( const int carPlateNum);
    void removeCarById(const int id);
    string carTypeAsString(const int plateNum);
    void printLotContents(const int lotId);
    void cleanLot();

private:
    int lotID;
    int totalLots;
    int availableLotNum;
    int row;
    int column;
};


#endif //UNTITLED_PARKINGLOT_H