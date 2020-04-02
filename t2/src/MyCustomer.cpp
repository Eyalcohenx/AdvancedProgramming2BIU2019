#include "MyCustomer.h"
#include "DataBase.h"

MyCustomer::MyCustomer(const string &fullName, int priority, const string &ID) :fullName(fullName), ID(ID) {
    if (priority > 5 || priority < 1)
        throw MyException("needs to be between 1 and 5");
    this->priority = priority;
}

string MyCustomer::getID(){
    return ID;
};

string MyCustomer::getFullName(){
    return fullName;
};

int MyCustomer::getPriority(){
    return priority;
};

list<Reservation *> MyCustomer::getReservations() {
    return DataBase::getReservationList(ID);
};