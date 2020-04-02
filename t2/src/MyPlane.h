#ifndef ADVANCED2_MYPLANE_H
#define ADVANCED2_MYPLANE_H
#include "interface.h"

class MyPlane : public Plane{
    string ID;
    int modelNumber;
    int MANAGER_num, NAVIGATOR_num, FLY_ATTENDANT_num, PILOT_num, OTHER_num;
    int maxFirstClass;
    int maxEconomyClass;
public:
    MyPlane(const string &ID, int modelNumber,const map<Jobs, int> crewNeeded, int maxFirstClass, int maxEconomyClass);

    MyPlane(const string &ID, int modelNumber, int MANAGER_num, int NAVIGATOR_num, int FLY_ATTENDANT_num, int PILOT_num,
            int OTHER_num, int maxFirstClass, int maxEconomyClass);

    string getID() override;
    int getModelNumber() override;
    map<Jobs, int> getCrewNeeded() override;
    int getMaxFirstClass() override;
    int getMaxEconomyClass() override;
    map<Jobs, int> crewToMap() const;
    void mapToCrew(const map<Jobs, int>);

    int getMANAGER_num() const;

    int getNAVIGATOR_num() const;

    int getFLY_ATTENDANT_num() const;

    int getPILOT_num() const;

    int getOTHER_num() const;
};

#endif

