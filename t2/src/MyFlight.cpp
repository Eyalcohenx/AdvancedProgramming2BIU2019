#include "MyFlight.h"
#include "DataBase.h"


MyFlight::MyFlight(int planeModelNumber, const Date &date, const string &source, const string &destination,
                   const string &ID) : planeModelNumber(planeModelNumber), date(date),
                                                              source(source), destination(destination), ID(ID){
    if (!(DataBase::checkForPlaneModel(planeModelNumber)))
        throw MyException("cannot add flight");
    string Check = DataBase::avilablePlaneForTheDate(planeModelNumber, date); // returning plane avilable at this date
    if (Check == "notFound")
        throw MyException("cannot add flight");
    else
        this->planeID = Check;
    MyPlane* thisPlane = DataBase::getPlaneFromTable(planeID);
    // checking if we have employees to assign to this flight
    if (!(DataBase::assignedEmployeesSuccessfully(date, ID, thisPlane->getMANAGER_num(),
            thisPlane->getNAVIGATOR_num(), thisPlane->getFLY_ATTENDANT_num(),
            thisPlane->getPILOT_num(), thisPlane->getOTHER_num())))
        throw MyException("couldnt assign employees");
    this->firstClassLeft = thisPlane->getMaxFirstClass();
    this->secondClassLeft = thisPlane->getMaxEconomyClass();
}

string MyFlight::getID(){
    return ID;
}

int MyFlight::getModelNumber(){
    return planeModelNumber;
}

list<Reservation *> MyFlight::getReservations(){
    return DataBase::getFlightReservationList(ID);
}

list<Employee *> MyFlight::getAssignedCrew(){
    return DataBase::getEmployeeListFromTakenTable(ID);
}

Date MyFlight::getDate(){
    return date;
}

string MyFlight::getSource(){
    return source;
}

string MyFlight::getDestination(){
    return destination;
}

const string &MyFlight::getPlaneID() const {
    return planeID;
}

int MyFlight::getFirstClassLeft() const {
    return firstClassLeft;
}

int MyFlight::getSecondClassLeft() const {
    return secondClassLeft;
}

void MyFlight::setFirstClassLeft(int firstClassLeft) {
    MyFlight::firstClassLeft = firstClassLeft;
}

void MyFlight::setSecondClassLeft(int secondClassLeft) {
    MyFlight::secondClassLeft = secondClassLeft;
}

MyFlight::MyFlight(int planeModelNumber, const Date &date, const string &source, const string &destination,
                   const string &ID, const string &planeID, int firstClassLeft, int secondClassLeft) : planeModelNumber(
        planeModelNumber), date(date), source(source), destination(destination), ID(ID), planeID(planeID),
                                                                                                       firstClassLeft(
                                                                                                               firstClassLeft),
                                                                                                       secondClassLeft(
                                                                                                               secondClassLeft) {}

