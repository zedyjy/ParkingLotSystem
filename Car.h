//
// Created by zeyne on 20.03.2022.
//

#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H
using namespace std;
#include <iostream>

class Car {
public:
    Car(const int lotID, const string lotLocation,const string carType, const int carPlateNum);
    Car();
    ~Car();
    void setLotId(int lotId);
    int getLotId();
    void setLotLocation(string lotLocation);
    string getLotLocation();
    void setCarPlateNum(int carPlateNum);
    int getCarPlateNum();
    void setCarType(string carType);
    string getCarType();
    void setLotLocationByNum(string lotLocation);
    int getLotLocationByNum();
    void setIsOccupied(const bool isOcc);
    bool getIsoccupied();

private:
    int lotId;
    string lotLocation;
    int carPlateNum;
    string carType;
    int lotLocationNum;
    bool isOcc;

};

#endif //UNTITLED_CAR_H
