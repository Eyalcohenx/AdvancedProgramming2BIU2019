#ifndef ADVANCED2_MYRESERVATION_H
#define ADVANCED2_MYRESERVATION_H

#include "interface.h"

class MyReservation : public Reservation
{
    string customerID;
    string flightID;
    Classes resClass;
    int maxBaggage;
    string ID;

public:
    explicit MyReservation(const string &customerID, const string &flightID, Classes resClass, int baggage, const string &ID, int);
    MyReservation(const string &customerID, const string &flightID, Classes resClass, int maxBaggage, const string &ID);

    string getID() override ;
    Customer* getCustomer() override ;
    Flight* getFlight() override ;
    Classes getClass() override ;
    int getMaxBaggage() override ;

    const string &getCustomerID() const;

    const string &getFlightID() const;

    Classes getResClass() const;

    int getBaggage() const;
};


#endif //ADVANCED2_MYRESERVATION_H
