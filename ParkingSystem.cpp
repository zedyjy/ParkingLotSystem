//
// Created by zeyne on 13.03.2022.
//

#include "ParkingSystem.h"
#include <iostream>
#include <unordered_map>

using namespace std;
ParkingSystem::ParkingSystem() {
    maxSize = 0;
    lots = NULL;
    carNums=0;
}

ParkingSystem::~ParkingSystem() {
    if(lots != NULL){
        delete [] lots;
    }
}

void ParkingSystem::createLot(int id, int rows, int columns) {
    for(int i = 0; i < maxSize; i++ ){
        if(lots[i]->getLotID()==id){
            cout << "You have entered a lot id that already exists." << endl;
            return;
        }
    }
    if(rows > 12 || columns > 12){
        cout << "Rows or columns cannot exceed 12." << endl;
    }
    else{
        ParkingLot ** temp = lots;
        lots = new ParkingLot*[maxSize+1];
        ParkingLot * lot = new ParkingLot(id,columns,rows);
        lots[maxSize] = lot;
        maxSize++;
        for(int i = 0;i<maxSize-1;i++){
            lots[i] = temp[i];
            temp [i] = NULL;
        }
        cout << "Lot created." << endl;
        delete [] temp;
    }
}

void ParkingSystem::removeLot(int id) {
    for(int i = 0; i < maxSize; i++){
        if(lots[i]->getLotID() == id){
            ParkingLot** lotsCopy = new ParkingLot*[maxSize-1];
            for(int a = 0; a < i; a++){
                lotsCopy[a] = lots[a];
            }
            for(int a = i; a < maxSize-1; a++){
                lotsCopy[a] = lots[a + 1];
            }
            cout << "Lot id with "<< id << " is deleted" << endl;
            delete [] lots ;
            lots = lotsCopy;
            maxSize--;
            for (int i = 0; i < maxSize; i++) {
                lots[i]->getTotalLotNum();
            }
            return;
        }
    }

    cout << "There is no lot id exist with given number" << endl;
    return;
}

void ParkingSystem::listLots() {
    if(maxSize > 0 ){
        for (int i = 0; i < maxSize; i++) {
            cout<< "ID:" << lots[i]->getLotID() << ", Dim:"<<"("<< lots[i]->getLotRow() <<","<<  lots[i]->getLotColumn()
                    <<"), number of empty parking spaces: "<< lots[i]->getTotalLotNum()<<endl;
        }
    }
    else {
        cout << "There are no lots" << endl;
    }
}

void ParkingSystem::parkCar(int lotId, string location, string carType, int plateNumber) {
    bool doesLotExist=false;
    for (int i = 0; i < maxSize; i++) {
        if(lots[i]->getLotID()== lotId)
            doesLotExist=true;
    }
    if(!doesLotExist){
        cout<<"Lot "<<lotId<<" is not in the system"<<endl;
        return;
    }
    Car car = Car(lotId, location, carType, plateNumber);
    int size = 0;
    if(isCarHere(plateNumber)){
        return;
    }
    for (int i = 0; i < maxSize; i++) {
        int row = (int) location.at(1) - 48;
        int column = car.getLotLocationByNum();
        if (lotId == lots[i]->getLotID()) {
            if (carType == "a") {
                lots[i]->putCar(lotId, location, carType, plateNumber);
                carNums++;

            } else if (carType == "b") {
                lots[i]->putCarB(lotId, location, carType, plateNumber);
                carNums++;

            }
        }
    }
}


void ParkingSystem::findCar(int plateNumber) {
    string carType = "";
    for (int i = 0; i < maxSize ; i++) {
        if (lots[i]->giveCar(plateNumber) != NULL) {
            lots[i]->giveCar(plateNumber);
            cout<<lots[i]->carTypeAsString(plateNumber)<<" car with number plate "<< plateNumber <<" is at location "<<
                lots[i]->giveCar(plateNumber)->getLotLocation()<<", lot "<<lots[i]->getLotID()<<endl;
            return;
        }
    }
    cout<<"The car with number plate "<< plateNumber<<" is not in the system"<<endl;
    return;
}

void ParkingSystem::lotContents(int id) {
    for(int i = 0;i< maxSize;i++) {
        if(lots[i]->getLotID()==id) {
            lots[i]->printLotContents(id);
        }
    }
}

void ParkingSystem::removeCar(int plateNumber) {
    for(int i = 0;i< maxSize;i++) {
        if (lots[i]->giveCar(plateNumber) != NULL) {
            lots[i]->removeCarById(plateNumber);
            return;
        }
    }
    cout<<"The car is not in the system"<<endl;
}

bool ParkingSystem::isCarHere(int plateNum) {
    Car *car;
    for(int i = 0;i<maxSize;i++) {
        car=lots[i]->giveCar(plateNum);
        if(car!=NULL) {
            return true;
        }
    }
    return false;
}





