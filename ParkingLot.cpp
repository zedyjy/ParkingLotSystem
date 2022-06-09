
//
// Created by zeyne on 14.03.2022.
//

#include "ParkingLot.h"
#include <iostream>
using namespace std;


ParkingLot::ParkingLot(const long lotID, const int column,const int row) {
    setLotColumn(column);
    setLotRow(row);
    setLotID(lotID);
    setLots(column, row);

    cars = new Car**[this->getLotRow()];
    for(int i = 0; i < this->getLotRow();i++){
        cars[i] = new Car*[this->getLotColumn()];
        for(int j=0;j<getLotColumn();j++) {
            cars[i][j] = NULL;
        }
    }
}

ParkingLot::~ParkingLot() {
    for(int i = 0; i < this->getLotRow();i++){
        for(int j=0;j<getLotColumn();j++) {
            delete cars[i][j];
            cars[i][j] = NULL;
        }
        delete[] cars[i];
        cars[i]=NULL;
    }
}

int ParkingLot::getLotID() {
    return lotID;
}

void ParkingLot::setLotID(const int lotID) {
    this->lotID= lotID;
}

void ParkingLot::setLotRow(const int row) {
    this -> row = row;
}

int ParkingLot::getLotRow() {
    return row;
}

void ParkingLot::setLotColumn(const int column) {
    this->column=column;
}

int ParkingLot::getLotColumn() {
    return column;
}

void ParkingLot::setLots( int column, int row) {
    totalLots=getLotColumn()*getLotRow();
}

int ParkingLot::getTotalLotNum() {
    return totalLots;
}

void ParkingLot::putCar(int lotId,string location, string carType, int carPlateNum) {
    Car *car=new Car(lotId,location, carType, carPlateNum);
    int  column1= (int)location.at(1)-48;
    int row1  = car->getLotLocationByNum();
    if(cars[row1-1][column1-1] !=NULL){
        cout<<"Cannot park heavy-duty car with number plate "<< carPlateNum<<" at location "<< location<<", already occupied"<<endl;
        return;
    }
    cars[row1-1][column1-1] = car;
    cout << "Light-duty car with number plate " << carPlateNum << " has been parked at location "
         << location << " " << "lot " << lotId << endl;
}

void ParkingLot::putCarB( int lotID,  string lotLocation,  string carType,  int carPlateNum) {
    Car *car=new Car(lotID,lotLocation, carType, carPlateNum);
    int column1 = (int)lotLocation.at(1)-48;
    int row1 = car->getLotLocationByNum();
    if ((column1 - 1) < 0 || (row1-2) < 0 || (column1 - 2) > getLotColumn() || (row1- 2) > getLotRow() ||cars[row1-2][column1-1] !=NULL || cars[row1-1][column1-1] != NULL) {
        cout << "Cannot park type '" << carType << "' car with number plate " << car->getCarPlateNum()
             << " at location "
             << car->getLotLocation() << " , not enough space" << endl;
        return;
    }
    if(cars[row1-2][column1-1] !=NULL && cars[row1-1][column1-1] != NULL){
        cout<<"not empty";
        return;
    }
    cars[row1-2][column1-1] = car;
    cars[row1-1][column1-1] = car;
    cout << "Heavy-duty car with number plate " << carPlateNum << " has been parked at location "
         << lotLocation << " " << "lot " << lotID << endl;
}

Car* ParkingLot::giveCar(const int carPlateNum) {
    for (int i = 0; i < this->getLotRow(); i++) {
        for (int j = 0; j < getLotColumn(); j++) {
            if (cars[i][j] != NULL) {
                if (cars[i][j]->getCarPlateNum() == carPlateNum) {
                    return cars[i][j];
                }
            }
        }
    }
    return NULL;
}

void ParkingLot::removeCarById(const int plateNum) {
    int column1;
    int row1;
    Car* car =giveCar(plateNum);
    if(car==NULL){
        return;
    }
    else{
        column1=car->getLotLocationByNum();
         row1=(int)car->getLotLocation().at(1)-48;
        cout<<carTypeAsString(plateNum)<<" with number plate "<< car->getCarPlateNum()
            <<" car has been removed from slot "<< car->getLotLocation()
            << ", lot "<<getLotID()<<endl;
        cars[row1-1][column1-1]=NULL;
        if(car->getCarType()=="b" && (row1-2)>=0){
            cars[row1-2][column1-1]=NULL;
        }
        delete car;
        return;
    }
}

string ParkingLot::carTypeAsString(int plateNum) {
    string carType="";
    if(giveCar(plateNum)->getCarType()=="a"){
        carType = "Light-duty";
    }
    else{
        carType = "Heavy-duty";
    }
    return carType;
}

void ParkingLot::printLotContents(int lotId) {
    int row2 = 0;
    cout<<"ID:"<< lotId<<", ("<<getLotColumn() <<","<< getLotRow() <<"), empty slots: "<< getTotalLotNum()<<endl;
    for(int i = 0; i < getLotRow();i++){
        for(int j=0;j< getLotColumn() ;j++) {
            if(cars[i][j]==NULL) {
                cout << "+ ";
                row2++;
            }
            else {
                cout<<cars[i][j]->getCarType()<<" ";
                row2++;
            }
        }
        if(row2==getLotColumn()){
            cout<<endl;
            row2=0;
        }
    }
}

void ParkingLot::cleanLot() {
    for(int i = 0; i < this->getLotRow();i++) {
        for (int j = 0; j < getLotColumn(); j++) {
            if (cars[i][j] != NULL) {
                removeCarById(cars[i][j]->getCarPlateNum());
                if (cars[i+1][j]->getCarType()=="b") {
                    j++;
                }
            }
        }
    }
}