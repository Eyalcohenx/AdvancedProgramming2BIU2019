#include "MyReservation.h"
#include "DataBase.h"

MyReservation::MyReservation(const string &customerID, const string &flightID, Classes resClass, int maxBaggage,
                             const string &ID, int notused) : customerID(customerID), flightID(flightID), resClass(resClass),
                                                 maxBaggage(maxBaggage), ID(ID) {}

MyReservation::MyReservation(const string &customerID, const string &flightID, Classes resClass, int baggage,
                             const string &ID) : customerID(customerID), flightID(flightID), resClass(resClass),
                                                 maxBaggage(baggage), ID(ID) {
    MyCustomer* checkForCustomer = DataBase::getCustomerFromTable(customerID);
    if (checkForCustomer == nullptr)
        throw MyException("no such customer");
    MyFlight* checkForFlight = DataBase::getFlightFromTable(flightID);
    if (checkForFlight == nullptr)
        throw MyException("no such flight");
    else{
        if(resClass == FIRST_CLASS) {
            if (checkForFlight->getFirstClassLeft() > 0)
                checkForFlight->setFirstClassLeft(checkForFlight->getFirstClassLeft() - 1);
            else
                throw MyException("no more room at first class");
        }
        else if(resClass == SECOND_CLASS){
            if (checkForFlight->getSecondClassLeft() > 0)
                checkForFlight->setSecondClassLeft(checkForFlight->getSecondClassLeft() - 1);
            else
                throw MyException("no more room at second class");
        }
        else
            throw MyException("no such class");
    }
}

string MyReservation::getID() {
    return ID;
}

const string &MyReservation::getCustomerID() const {
    return customerID;
}

const string &MyReservation::getFlightID() const {
    return flightID;
}

Classes MyReservation::getResClass() const {
    return resClass;
}

int MyReservation::getBaggage() const {
    return maxBaggage;
}

Customer *MyReservation::getCustomer() {
    return DataBase::getCustomerFromTable(customerID);
}

Flight *MyReservation::getFlight() {
    return DataBase::getFlightFromTable(flightID);
}

Classes MyReservation::getClass() {
    return resClass;
}

int MyReservation::getMaxBaggage() {
    return maxBaggage;
}

