//
// Created by zeyne on 20.03.2022.
//

#include "Car.h"
using namespace std;
#include <iostream>
//#include <unordered_map>

Car::Car(const int lotID, const string lotLocation,const string carType, const int carPlateNum) {
    setLotId(lotID);
    setLotLocation(lotLocation);
    setCarType(carType);
    setCarPlateNum(carPlateNum);
    setLotLocationByNum(lotLocation);
}

Car::Car() {
    setCarType("");
    setLotId(0);
    setLotLocation("");
    setCarPlateNum(0);
    setLotLocationByNum(0);
}

Car::~Car() {

}

void Car::setLotId(int lotId) {
    this->lotId=lotId;
}

int Car::getLotId() {
    return lotId;
}

void Car::setLotLocation(string lotLocation) {
    this->lotLocation=lotLocation;
}

string Car::getLotLocation() {
    return lotLocation;
}

void Car::setCarPlateNum(int carPlateNum) {
    this->carPlateNum=carPlateNum;
}

int Car::getCarPlateNum() {
    return carPlateNum;
}

void Car::setCarType(string carType) {
    this->carType=carType;
}

string Car::getCarType() {
    return carType;
}

void Car::setLotLocationByNum(string lotLocation) {
    char characters[12]={'A','B','C','D','E','F','G','H','I','J','K','L'};
    char rowLetter=lotLocation.at(0);
    for(int i = 0; i<12;i++){
        if(rowLetter==characters[i]){
            lotLocationNum=i+1;
            return;
        }
    }
}

int Car::getLotLocationByNum() {
    return lotLocationNum;
}

bool Car::getIsoccupied() {
    return isOcc;
}

void Car::setIsOccupied(bool isOcc) {
    this->isOcc=isOcc;
}
