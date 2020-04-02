#include "MyEmployee.h"
#include "DataBase.h"

MyEmployee::MyEmployee(int seniority, int birthYear, const string &EmployerID, Jobs title, const string &ID)
        : seniority(seniority), birthYear(birthYear), title(title), ID(ID) {
    if (EmployerID == "")
        this->EmployerID = "null";
    else
        this->EmployerID = EmployerID;
}

string MyEmployee::getID(){
    return ID;
}

int MyEmployee::getSeniority() {
    return seniority;
}

int MyEmployee::getBirthYear() {
    return birthYear;
}

Employee *MyEmployee::getEmployer() {
    return DataBase::getEmployeeFromTable(EmployerID);
}

Jobs MyEmployee::getTitle() {
    return title;
}

const string &MyEmployee::getEmployerID() const {
    return EmployerID;
}

void MyEmployee::setEmployerID(const string &EmployerID) {
    MyEmployee::EmployerID = EmployerID;
}


