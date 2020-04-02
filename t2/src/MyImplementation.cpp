#include "MyImplementation.h"

Employee* MyImplementation::addEmployee(int seniority, int birth_year, string employer_id, Jobs title) {
    DataBase::employeeTable.emplace_back(MyEmployee(seniority, birth_year, employer_id, title, DataBase::GenerateID("E")));
    return &DataBase::employeeTable.back();
}

Employee* MyImplementation::getEmployee(string id) {
    return DataBase::getEmployeeFromTable(id);
}

Plane* MyImplementation::addPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers) {

    //converting from map to two ints
    map<Classes, int> :: iterator it;
    int maxFirst = 0, maxSecond = 0;
    if (max_passangers.size() > 2 || crew_needed.size() > 5)
        throw MyException("the maps are too big");
    for ( it = max_passangers.begin(); it != max_passangers.end(); it++ ) {
        switch (it->first){
            case FIRST_CLASS : maxFirst = it->second; break;
            default: maxSecond = it->second; break;
        }
    }
    DataBase::planeTable.emplace_back(MyPlane( DataBase::GenerateID("P"), model_number, crew_needed, maxFirst, maxSecond));
    return &DataBase::planeTable.back();
}

Plane* MyImplementation::getPlane(string id) {
    return DataBase::getPlaneFromTable(id);
}

Customer* MyImplementation::addCustomer(string full_name, int priority) {
    DataBase::customerTable.emplace_back(MyCustomer(full_name, priority, DataBase::GenerateID("C")));
    return &DataBase::customerTable.back();
}

Customer* MyImplementation::getCustomer(string id) {
    return DataBase::getCustomerFromTable(id);
}


Flight* MyImplementation::addFlight(int model_number, Date date, string source, string destination) {
    DataBase::flightTable.emplace_back(MyFlight(model_number, date, source, destination, DataBase::GenerateID("F")));
    return &DataBase::flightTable.back();
}

Flight* MyImplementation::getFlight(string id) {
    return DataBase::getFlightFromTable(id);
}

Reservation* MyImplementation::addResevation(string customerId, string flightId, Classes cls, int max_baggage) {
    DataBase::reservationTable.emplace_back(MyReservation(customerId, flightId, cls, max_baggage, DataBase::GenerateID("R")));
    return &DataBase::reservationTable.back();
}

Reservation* MyImplementation::getReservation(string id) {
    return DataBase::getReservationFromTable(id);
}

MyImplementation::MyImplementation() {
    //load
    DataBase::loadCostumers();
    DataBase::loadReservations();
    DataBase::loadFlights();
    DataBase::loadEmployees();
    DataBase::loadTakenEmplyees();
    DataBase::loadPlanes();
    //EXPLNATION : need to load all if the user writes -
    // addCustomer(....).getReservtions.at(0).getFlight.getAssignedCrew....
    // thats why we need to load all the data!!!
}

void MyImplementation::exit() {

    //write
    DataBase::writeCustomers();
    DataBase::writeReservations();
    DataBase::writeFlights();
    DataBase::writeEmployees();
    DataBase::writeTakenEmplyees();
    DataBase::writePlanes();
}