#ifndef ADVANCED2_COMPANYMANAGE_H
#define ADVANCED2_COMPANYMANAGE_H

#include <vector>
#include <fstream>
#include "interface.h"
#include "MyEmployee.h"
#include "MyPlane.h"
#include "MyReservation.h"
#include "MyCustomer.h"
#include "MyFlight.h"

/************************************************************************
* function name:
* The Input:
* The output:
* The Function operation:
*************************************************************************/
struct takenEmployees
{
    string employeeID;
    Date flightDate;
    string flightID;
    takenEmployees(const string &employeeID, const Date &flightDate, const string &flightID);
};
struct MyException : public std::exception
{
    std::string s;
    explicit MyException(string ss) : s(ss) {}
    ~MyException() throw () {}
    const char* what() const throw() { return s.c_str(); }
};
class DataBase {
public:
    static vector<MyPlane> planeTable;
    static vector<MyEmployee> employeeTable;
    static vector<MyReservation> reservationTable;
    static vector<MyCustomer> customerTable;
    static vector<MyFlight> flightTable;
    static vector<takenEmployees> takenEmployeesTable; // emplyeeID, FlightDate, FlightID
    static int IDCounter;

    static string GenerateID(const string);
    static string ReplaceAll(string, const string&, const string&);
    static MyEmployee* getEmployeeFromTable(const string);
    static list<Reservation *> getReservationList(const string);
    static list<Reservation *> getFlightReservationList(const string);
    static MyCustomer* getCustomerFromTable(const string);
    static MyFlight* getFlightFromTable(const string);
    static MyPlane* getPlaneFromTable(const string);
    static takenEmployees* getTakenEmployeesFromTakenTable(const string, const string);
    static MyReservation* getReservationFromTable(const string);
    static bool employeeFreeAtTheDate(const Date, const string);
    static bool checkForPlaneModel(int);
    static void loadEmployees();
    static void writeEmployees();
    static void loadReservations();
    static void writeReservations();
    static void loadPlanes();
    static void writePlanes();
    static void loadCostumers();
    static void writeCustomers();
    static void writeFlights();
    static void loadFlights();
    static void writeTakenEmplyees();
    static void loadTakenEmplyees();
    static list<Employee *> getEmployeeListFromTakenTable(const string);
    static bool assignedEmployeesSuccessfully(const Date date, const string, int, int, int, int, int);
    static string avilablePlaneForTheDate(int ,const Date);
};

#endif //ADVANCED2_COMPANYMANAGE_H

/*
 * plane : string ID, int model num, ints* crew, int max first, int max second.
 * employee : int seniority, int birth year, string employerID, jobs title, string ID.
 * res : string customer, string FlightID, classes res class, int maxBaggage, string ID.
 * flight : int plane model, Date date, string source, string des, string ID.
 * cus : string name, int priority, string ID.
 */