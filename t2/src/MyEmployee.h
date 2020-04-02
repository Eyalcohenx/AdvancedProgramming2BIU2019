#ifndef ADVANCED2_MYEMPLOYEE_H
#define ADVANCED2_MYEMPLOYEE_H

#include "interface.h"

class MyEmployee : public Employee{
    int seniority;
    int birthYear;
    string EmployerID;
    Jobs title;
    string ID;
public:
    MyEmployee(int seniority, int birthYear, const string &EmployerID, Jobs title,
            const string &ID);
    int getSeniority() override ;
    int getBirthYear() override ;
    Employee *getEmployer() override;
    Jobs getTitle() override;
    string getID() override ;
    const string &getEmployerID() const;

    void setEmployerID(const string &EmployerID);
};

#endif //ADVANCED2_MYEMPLOYEE_H
