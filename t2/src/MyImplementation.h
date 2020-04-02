#ifndef ADVANCED2_MYIMPLEMENTATION_H
#define ADVANCED2_MYIMPLEMENTATION_H

#include "DataBase.h"

class MyImplementation : public Ex2{
    string notused;
public:
    MyImplementation();

    Employee *addEmployee(int seniority, int birth_year, string employer_id, Jobs title) override;

    Employee *getEmployee(string id) override;

    Plane *addPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers) override;

    Plane *getPlane(string id) override;

    Flight *addFlight(int model_number, Date date, string source, string destination) override;

    Flight *getFlight(string id) override;

    Customer *addCustomer(string full_name, int priority) override;

    Customer *getCustomer(string id) override;

    Reservation *addResevation(string customerId, string flightId, Classes cls, int max_baggage) override;

    Reservation *getReservation(string id) override;

    void exit() override;
};


#endif //ADVANCED2_MYIMPLEMENTATION_H
