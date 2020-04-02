#ifndef ADVANCED2_MYFLIGHT_H
#define ADVANCED2_MYFLIGHT_H

#include "interface.h"


class MyFlight : public Flight{
    int planeModelNumber;
    Date date;
    string source;
    string destination;
    string ID;
    string planeID;
    int firstClassLeft;
    int secondClassLeft;
public:

    explicit MyFlight(int planeModelNumber, const Date &date, const string &source, const string &destination, const string &ID);

    MyFlight(int planeModelNumber, const Date &date, const string &source, const string &destination, const string &ID,
             const string &planeID, int firstClassLeft, int secondClassLeft);

    string getID() override ;
    int getModelNumber() override ;
    list<Reservation *> getReservations() override ;
    list<Employee *> getAssignedCrew() override ;
    Date getDate() override ;
    string getSource() override ;
    string getDestination() override ;
    const string &getPlaneID() const;

    int getFirstClassLeft() const;

    int getSecondClassLeft() const;

    void setFirstClassLeft(int firstClassLeft);

    void setSecondClassLeft(int secondClassLeft);

};


#endif //ADVANCED2_MYFLIGHT_H
