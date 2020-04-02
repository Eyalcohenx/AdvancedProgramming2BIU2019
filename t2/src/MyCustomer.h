#ifndef ADVANCED2_MYCUSTOMER_H
#define ADVANCED2_MYCUSTOMER_H

#include "interface.h"

class MyCustomer : public Customer
{
    string fullName;
    int priority;
    string ID;

public:
    MyCustomer(const string &fullName, int priority, const string &ID);
    string getID() override;
    string getFullName() override;
    int getPriority() override;
    list<Reservation *> getReservations() override;
};

#endif //ADVANCED2_MYCUSTOMER_H
