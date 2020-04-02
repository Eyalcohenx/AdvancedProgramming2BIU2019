#include <iostream>
#include "DataBase.h"
#include "MyCustomer.h"
// initiating static vectors
vector<MyPlane> DataBase::planeTable = {};
vector<MyEmployee> DataBase::employeeTable = {};
vector<MyReservation> DataBase::reservationTable = {};
vector<MyCustomer> DataBase::customerTable = {};
vector<MyFlight> DataBase::flightTable = {};
vector<takenEmployees> DataBase::takenEmployeesTable = {};
int DataBase::IDCounter = 0;
/************************************************************************
* function name: replace all
* The Input: 3 strings
* The output: string
* The Function operation: replace in a bigger string the "from" string to
 * the "to" string
*************************************************************************/
string DataBase::ReplaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}
/************************************************************************
* function name: write flghts
* The Input: void
* The output: void
* The Function operation: writing to the file the vector as a table
*************************************************************************/
void DataBase::writeFlights() {
    ofstream FlightData("database/FlightsData.txt");
    for (unsigned int i = 0; i < flightTable.size(); i++){
        MyFlight oneFlight = flightTable.at(i);
        FlightData << oneFlight.getModelNumber() << ' ' << oneFlight.getDate().getDate()
                      << ' ' << ReplaceAll(oneFlight.getSource(), string(" "), string("$"))
                      << ' ' << ReplaceAll(oneFlight.getDestination(), string(" "), string("$"))
                      << ' ' << oneFlight.getID() << ' ' << oneFlight.getPlaneID() << ' ' <<
                      oneFlight.getFirstClassLeft() << ' ' << oneFlight.getSecondClassLeft() << ' ' << endl;
    }
    FlightData.close();
}
/************************************************************************
* function name: load flghts
* The Input: void
* The output: void
* The Function operation: loading from the table to the vector
*************************************************************************/
void DataBase::loadFlights() {

    ifstream FlightsData("database/FlightsData.txt");
    if (!FlightsData.is_open()) {
        flightTable = {};
        return;
    }
    int getPlaneModelNumber;
    string getDate;
    string getSource;
    string getDestination;
    string getID;
    string getPlaneID;
    int getFirstLeft;
    int getSecondLeft;
    while(FlightsData >> getPlaneModelNumber >> getDate >> getSource >> getDestination >> getID >> getPlaneID >> getFirstLeft >> getSecondLeft){
        getSource = ReplaceAll(getSource, string("$"), string(" "));
        getDestination = ReplaceAll(getDestination, string("$"), string(" "));
        MyFlight temp = MyFlight(getPlaneModelNumber, Date(getDate), getSource, getDestination, getID, getPlaneID, getFirstLeft, getSecondLeft);
        if (getFlightFromTable(temp.getID()) == nullptr)
            flightTable.emplace_back(temp);
    }

    FlightsData.close();
}
/************************************************************************
* function name: write customers
* The Input: void
* The output: void
* The Function operation: writing to the file the vector as a table
*************************************************************************/
void DataBase::writeCustomers() {
    ofstream CustomersData("database/CustomersData.txt");
    for (unsigned int i = 0; i < customerTable.size(); i++){
        MyCustomer oneCustomer = customerTable.at(i);
        CustomersData << ' ' << ReplaceAll(oneCustomer.getFullName(), string(" "), string("$")) << ' ' << oneCustomer.getPriority()
        << ' ' << oneCustomer.getID() << ' ' << endl;
    }
    CustomersData.close();
}
/************************************************************************
* function name: load customers
* The Input: void
* The output: void
* The Function operation: loading from the table to the vector
*************************************************************************/
void DataBase::loadCostumers() {
    ifstream CustomersData("database/CustomersData.txt");
    if (!CustomersData.is_open()) {
        customerTable = {};
        return;
    }
    string getFullName;
    int getPriority;
    string getID;
    while(CustomersData >> getFullName >> getPriority >> getID){
        getFullName = ReplaceAll(getFullName, string("$"), string(" "));
        MyCustomer temp = MyCustomer(getFullName, getPriority, getID);
        if (getCustomerFromTable(temp.getID()) == nullptr)
            customerTable.emplace_back(temp);
    }

    CustomersData.close();
}
/************************************************************************
* function name: write reservations
* The Input: void
* The output: void
* The Function operation: writing to the file the vector as a table
*************************************************************************/
void DataBase::writeReservations() {
    ofstream reservationsData("database/reservationsData.txt");

    for (unsigned int i = 0; i < reservationTable.size(); i++){
        MyReservation oneReservation = reservationTable.at(i);
        reservationsData << ' ' << oneReservation.getCustomerID() << ' ' << oneReservation.getFlightID()
        << ' ' << oneReservation.getClass() << ' ' << oneReservation.getMaxBaggage() << ' ' << oneReservation.getID() << ' ' << endl;
    }
    reservationsData.close();
}
/************************************************************************
* function name: load reservations
* The Input: void
* The output: void
* The Function operation: loading from the table to the vector
*************************************************************************/
void DataBase::loadReservations() {

    ifstream reservationsData("database/reservationsData.txt");
    if (!reservationsData.is_open()) {
        reservationTable = {};
        return;
    }
    string getCustomerID;
    string getFlightID;
    int getResClass;
    int getBaggage;
    string getID;
    Classes thisClass;
    while (reservationsData >> getCustomerID >> getFlightID >> getResClass >> getBaggage >> getID){
        if (getResClass == 0)
            thisClass = FIRST_CLASS;
        else
            thisClass = SECOND_CLASS;
        MyReservation temp = MyReservation(getCustomerID, getFlightID, thisClass, getBaggage, getID, 0);
        if (getReservationFromTable(temp.getID()) == nullptr)
            reservationTable.emplace_back(temp);
    }
    reservationsData.close();
}
/************************************************************************
* function name: write employees
* The Input: void
* The output: void
* The Function operation: writing to the file the vector as a table
*************************************************************************/
void DataBase::writeEmployees() {
    ofstream EmployeeData("database/EmployeeData.txt");
    for (unsigned int i = 0; i < employeeTable.size(); i++){
        MyEmployee oneEmployee = employeeTable.at(i);
        if(oneEmployee.getEmployer() == nullptr)
            oneEmployee.setEmployerID("null");
        EmployeeData << ' ' << oneEmployee.getSeniority() << ' ' << oneEmployee.getBirthYear() << ' ' << oneEmployee.getEmployerID()
                << ' ' << oneEmployee.getTitle() << ' ' << oneEmployee.getID() << ' ' << endl;
    }
    EmployeeData.close();
}
/************************************************************************
* function name: load employees
* The Input: void
* The output: void
* The Function operation: loading from the table to the vector
*************************************************************************/
void DataBase::loadEmployees() {

    ifstream employeeFile("database/EmployeeData.txt");
    if (!employeeFile.is_open()) {
        employeeTable = {};
        return;
    }
    int getSeniority, getBirthYear;
    string getEmployerID;
    int getTitle;
    string getID;
    Jobs convert;
    while (employeeFile >> getSeniority >> getBirthYear >> getEmployerID >> getTitle >> getID){
        switch (getTitle){
            case 0 : convert = MANAGER; break;
            case 1 : convert = NAVIGATOR; break;
            case 2 : convert = FLY_ATTENDANT; break;
            case 3 : convert = PILOT; break;
            default :  convert = OTHER; break;
        }
        MyEmployee temp = MyEmployee(getSeniority, getBirthYear, getEmployerID, convert, getID);
        if (getEmployeeFromTable(temp.getID()) == nullptr)
            employeeTable.emplace_back(temp);
    }
    employeeFile.close();
}
/************************************************************************
* function name: write planes
* The Input: void
* The output: void
* The Function operation: writing to the file the vector as a table
*************************************************************************/
void DataBase::writePlanes() {
    ofstream PlaneData("database/PlaneData.txt");
    for (unsigned int i = 0; i < planeTable.size(); i++){
        MyPlane temp = planeTable.at(i);
        PlaneData << temp.getID() << ' ' << temp.getModelNumber() << ' '  << temp.getMANAGER_num() << ' '  << temp.getNAVIGATOR_num()
                  << ' '  << temp.getFLY_ATTENDANT_num() << ' '  << temp.getPILOT_num() << ' '  << temp.getOTHER_num() << ' '  << temp.getMaxFirstClass()
                  << ' '  << temp.getMaxEconomyClass() << ' '  << endl;
    }
    PlaneData.close();
}
/************************************************************************
* function name: load planes
* The Input: void
* The output: void
* The Function operation: loading from the table to the vector
*************************************************************************/
void DataBase::loadPlanes() {

    ifstream planeFile("database/PlaneData.txt");
    if (!planeFile.is_open()) {
        planeTable = {};
        return;
    }
    string getID;
    int getModelNumber , getMANAGER_num , getNAVIGATOR_num
    , getFLY_ATTENDANT_num , getPILOT_num , getOTHER_num , getMaxFirstClass, getMaxEconomyClass;
    while (planeFile >> getID >> getModelNumber >> getMANAGER_num >> getNAVIGATOR_num
           >> getFLY_ATTENDANT_num >> getPILOT_num >> getOTHER_num >> getMaxFirstClass >> getMaxEconomyClass){
        MyPlane temp = MyPlane(getID, getModelNumber , getMANAGER_num , getNAVIGATOR_num
                , getFLY_ATTENDANT_num , getPILOT_num , getOTHER_num , getMaxFirstClass, getMaxEconomyClass);
        if (getPlaneFromTable(temp.getID()) == nullptr)
            planeTable.emplace_back(temp);
    }
    planeFile.close();

}
/************************************************************************
* function name: get employee from table
* The Input: employee ID
* The output: MyEmployee Pointer
* The Function operation: looking for the employee in the database vector
 * and sending its pointer back
*************************************************************************/
MyEmployee* DataBase::getEmployeeFromTable(const string ID) {
    MyEmployee* returned = nullptr;
    if(ID == "null")
        return returned;
    for (unsigned int i = 0; i < employeeTable.size(); i++){
        if (employeeTable.at(i).getID() == ID)
            returned = (&employeeTable.at(i));
    }
    return returned;
}
/************************************************************************
* function name: get reservation list
* The Input: customer ID
* The output: customer's reservation list
* The Function operation: getting the customer calling it its reservation
 * list
*************************************************************************/
list<Reservation *> DataBase::getReservationList(const string customerID){
    list<Reservation *> returned = list<Reservation *>();
    for (unsigned int i = 0; i < reservationTable.size(); i++){
        if (reservationTable.at(i).getCustomerID() == customerID)
            returned.emplace_back(&reservationTable.at(i));
    }
    return returned;
}
/************************************************************************
* function name: get flight reservation list
* The Input: flight
* The output: fligth's reservations
* The Function operation: getting the reservation list of the given flight
*************************************************************************/
list<Reservation *> DataBase::getFlightReservationList(const string flightID){
    list<Reservation *> returned = list<Reservation *>();
    for (unsigned int i = 0; i < reservationTable.size(); i++){
        if (reservationTable.at(i).getFlightID() == flightID)
            returned.emplace_back(&reservationTable.at(i));
    }
    return returned;
}
/************************************************************************
* function name: get customer from table
* The Input: customer ID
* The output: pointer to the customer
* The Function operation: iterating over the customer vector and searching
 * for the specific customer with this ID
*************************************************************************/
MyCustomer* DataBase::getCustomerFromTable(const string customerID) {
    MyCustomer* returned = nullptr;
    for (unsigned int i = 0; i < customerTable.size(); i++){
        if (customerTable.at(i).getID() == customerID)
            returned = (&customerTable.at(i));
    }
    return returned;
}

MyFlight* DataBase::getFlightFromTable(const string flightID) {
    MyFlight* returned = nullptr;
    for (unsigned int i = 0; i < flightTable.size(); i++){
        if (flightTable.at(i).getID() == flightID)
            returned = (&flightTable.at(i));
    }
    return returned;
}
/************************************************************************
* function name: avilable plane for the date
* The Input: needed model number of a plane and the date we want to use it
* The output: the plane we found ID, if we didnt find we return "notFound"
* The Function operation: every flight has an plane ID that it is taking,
 * we search the flights for flight with the same plane ID and the same
 * date if we find one we pass it and if we didnot find one we return the
 * plane ID we found
*************************************************************************/
string DataBase::avilablePlaneForTheDate(int planeModelNumber, const Date date) {
    string planeID = "notFound";
    vector<MyPlane> planeCheck = planeTable;
    vector<MyFlight> flightCheck = flightTable;
    // flag to check if we found a plane to connect to this flight
    bool flag = false;
    // going over the plane list
    for (unsigned int i = 0; (i < planeTable.size()) && !flag; i++){
        //checking if the model number is the same as needed
        if (planeTable.at(i).getModelNumber() == planeModelNumber) {
            // searching in the flight is there is a flight with the same date and plane id
            for (unsigned int j = 0; j < flightTable.size(); j++) {
                if (flightTable.at(j).getPlaneID() == planeTable.at(i).getID()
                    && flightTable.at(j).getDate().getDate() == date.getDate())
                    flag = true;
            }
            // if we found a flight that is alredy usuing this plane at the same date we need to reset the flag
            if (flag)
                flag = false;
                // else we connect this flight to that class
            else
                planeID = planeTable.at(i).getID();
        }
    }
    return planeID;
}
/************************************************************************
* function name: write taken employees
* The Input: void
* The output: void
* The Function operation: writing rom the taking employee table to the file
*************************************************************************/
void DataBase::writeTakenEmplyees() {
    ofstream TakenEmployeesData("database/TakenEmployeesData.txt");
    for (unsigned int i = 0; i < takenEmployeesTable.size(); i++) {
        TakenEmployeesData << takenEmployeesTable.at(i).employeeID << ' ' << takenEmployeesTable.at(i).flightDate.getDate() << ' '
        <<  takenEmployeesTable.at(i).flightID << ' ' << endl;
    }
    TakenEmployeesData.close();
}
/************************************************************************
* function name: oad taken employees
* The Input: void
* The output: void
* The Function operation: loading from the table to the vector
*************************************************************************/
void DataBase::loadTakenEmplyees() {

    ifstream TakenEmployeesData("database/TakenEmployeesData.txt");
    if (!TakenEmployeesData.is_open()) {
        takenEmployeesTable = {};
        return;
    }
    string getEmpID;
    string getDate;
    string getFlightID;
    while (TakenEmployeesData >> getEmpID >> getDate >> getFlightID){
        takenEmployees temp = takenEmployees(getEmpID, Date(getDate), getFlightID);
        if (getTakenEmployeesFromTakenTable(getEmpID, getFlightID) == nullptr)
            takenEmployeesTable.emplace_back(temp);
    }
    TakenEmployeesData.close();
}
/************************************************************************
* function name: check for plane model
* The Input: int - model number
* The output: bool
* The Function operation: checking if the given plane model number exists
*************************************************************************/
bool DataBase::checkForPlaneModel(int modelNum) {
    bool modelExists = false;
    for (unsigned int i = 0;i < planeTable.size(); i++){
        if (planeTable.at(i).getModelNumber() == modelNum)
            modelExists = true;
    }
    return modelExists;
}
/************************************************************************
* function name: get plane from table
* The Input: plane ID
* The output: pointer to plane
* The Function operation: looking for a specific plane in the vector
*************************************************************************/
MyPlane* DataBase::getPlaneFromTable(const string planeID) {
    MyPlane* returned = nullptr;
    for (unsigned int i = 0;i < planeTable.size(); i++){
        if (planeTable.at(i).getID() == planeID)
            returned = &planeTable.at(i);
    }
    return returned;
}
/************************************************************************
* function name: assigned employees successfully
* The Input: date of flight its ID and number of each job needed
* The output: true - if we successfully assigned the employees
 * false - if we didnt
* The Function operation: looking for an employee, when we find one we
 * search on the taken employees table if this specific employee is free
 * at this date, if its not we continue and if he is free we assigned it
 * to our flight an add the date to temp vector if we assigned all we add
 *  this vector to the static vector of the class
*************************************************************************/
bool DataBase::assignedEmployeesSuccessfully(const Date date,const string flightID, int managersNeeded,
        int navigatorsNeeded, int flyAttendantsNeeded, int pilotsNeeded, int otherNeeded) {
    bool addedSuccessfully = false;
    vector<takenEmployees> addToTakenEmployees = {};
    vector<MyEmployee> check = employeeTable;
    for (unsigned int i = 0; i < employeeTable.size(); i++){
        MyEmployee thisEmployee = employeeTable.at(i);
        if (thisEmployee.getTitle() == MANAGER && managersNeeded > 0){
            if (employeeFreeAtTheDate(date, thisEmployee.getID())){
                managersNeeded --;
                addToTakenEmployees.emplace_back(takenEmployees(thisEmployee.getID(), date, flightID));
            }
        }
        else if (thisEmployee.getTitle() == NAVIGATOR && navigatorsNeeded > 0) {
            if (employeeFreeAtTheDate(date, thisEmployee.getID())) {
                navigatorsNeeded--;
                addToTakenEmployees.emplace_back(takenEmployees(thisEmployee.getID(), date, flightID));
            }
        }
        else if (thisEmployee.getTitle() == FLY_ATTENDANT && flyAttendantsNeeded > 0){
            if (employeeFreeAtTheDate(date, thisEmployee.getID())) {
                flyAttendantsNeeded--;
                addToTakenEmployees.emplace_back(takenEmployees(thisEmployee.getID(), date, flightID));
            }
        }
        else if (thisEmployee.getTitle() == PILOT && pilotsNeeded > 0){
            if (employeeFreeAtTheDate(date, thisEmployee.getID())) {
                pilotsNeeded--;
                addToTakenEmployees.emplace_back(takenEmployees(thisEmployee.getID(), date, flightID));
            }
        }
        else if (thisEmployee.getTitle() == OTHER && otherNeeded > 0){
            if (employeeFreeAtTheDate(date, thisEmployee.getID())) {
                otherNeeded--;
                addToTakenEmployees.emplace_back(takenEmployees(thisEmployee.getID(), date, flightID));
            }
        }
    }
    if (managersNeeded + navigatorsNeeded + flyAttendantsNeeded + pilotsNeeded + otherNeeded == 0){
        for (unsigned int i = 0; i < addToTakenEmployees.size(); i++){
            takenEmployeesTable.emplace_back(addToTakenEmployees.at(i));
        }
        addedSuccessfully = true;
    }
    return addedSuccessfully;
}

bool DataBase::employeeFreeAtTheDate(const Date date, const string employeeID) {
    bool free = true;
    for (unsigned int i = 0; i < takenEmployeesTable.size(); i++) {
        if (takenEmployeesTable.at(i).employeeID == employeeID
        && takenEmployeesTable.at(i).flightDate.getDate() == date.getDate())
            free = false;
    }
    return free;
}
/************************************************************************
* function name: get employee list from table
* The Input: Flight ID
* The output: employees assigned to that flight
* The Function operation: using get empployee method and creating a list of
 * assigned employees
*************************************************************************/
list<Employee *> DataBase::getEmployeeListFromTakenTable(const string flightID) {
    list<Employee *> listOfCrew = {};
    string employeeID = "";
    for (unsigned int i = 0; i < takenEmployeesTable.size(); i++) {
        employeeID = takenEmployeesTable.at(i).employeeID;
        if (takenEmployeesTable.at(i).flightID == flightID){
            listOfCrew.emplace_back(getEmployeeFromTable(employeeID));
        }
    }
    return listOfCrew;
}
/************************************************************************
* function name: get reservation from table
* The Input: reservation ID
* The output: pointer to reservation
* The Function operation: looking for a specific reservation in the vector
*************************************************************************/
MyReservation* DataBase::getReservationFromTable(const string reservationID) {
    MyReservation* returned = nullptr;
    for (unsigned int i = 0;i < reservationTable.size(); i++){
        if (reservationTable.at(i).getID() == reservationID)
            returned = &reservationTable.at(i);
    }
    return returned;
}
/************************************************************************
* function name: takenEmployees struct constructor
* The Input: args
* The output: voud
* The Function operation: creating the new struct
*************************************************************************/
takenEmployees::takenEmployees(const string &employeeID, const Date &flightDate, const string &flightID) : employeeID(
        employeeID), flightDate(flightDate), flightID(flightID) {}
/************************************************************************
* function name: Generate ID
* The Input: string of the type of the object
* The output: an ID
* The Function operation: add the type to the number it got to by now
 * and sending back a new ID
*************************************************************************/
string DataBase::GenerateID(const string type) {
    ifstream IDFile("database/IDFile");
    if (!IDFile.is_open()) {
        IDCounter = 0;
        ofstream writeID("database/IDFile");
        writeID << ++IDCounter;
        writeID.close();
        return type + "0";
    }
    IDFile >> IDCounter;
    IDFile.close();
    ofstream writeID("database/IDFile");
    writeID << ++IDCounter;
    writeID.close();
    return type + to_string(IDCounter);
}
/************************************************************************
* function name: get taken employees from the taken employees table
* The Input: employee ID and flight ID (needed both because employee can
 * be multiple times in this list, thats why we need to check the flight)
* The output: pointer to the struct
* The Function operation: looking for a specific taken employee in the
 * vector
*************************************************************************/
takenEmployees* DataBase::getTakenEmployeesFromTakenTable(const string employeeID, const string flightID) {
    takenEmployees* returned = nullptr;
    for (unsigned int i = 0;i < takenEmployeesTable.size(); i++){
        if (takenEmployeesTable.at(i).employeeID == employeeID && takenEmployeesTable.at(i).flightID == flightID)
            returned = &takenEmployeesTable.at(i);
    }
    return returned;
}

