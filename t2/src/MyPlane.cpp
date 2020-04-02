#include <iostream>
#include "MyPlane.h"
/************************************************************************
* function name: MyPlane constructor with map
* The Input: args
* The output: void
* The Function operation: this constructor is for the input from the user
 * the second one if for the read/right oprations.
*************************************************************************/
MyPlane::MyPlane(const string &ID, int modelNumber,const map<Jobs, int> crewNeeded, int maxFirstClass, int maxEconomyClass) : ID(ID),
modelNumber(modelNumber), maxFirstClass(maxFirstClass), maxEconomyClass(maxEconomyClass) {
    MANAGER_num = 0;
    NAVIGATOR_num = 0;
    FLY_ATTENDANT_num = 0;
    PILOT_num = 0;
    OTHER_num = 0;
    this->mapToCrew(crewNeeded);
}
/************************************************************************
* function name: MyPlane constructor without map
* The Input: args
* The output: void
* The Function operation: this constructor is for  the read/right oprations.
*************************************************************************/
MyPlane::MyPlane(const string &ID, int modelNumber, int MANAGER_num, int NAVIGATOR_num, int FLY_ATTENDANT_num,
                 int PILOT_num, int OTHER_num, int maxFirstClass, int maxEconomyClass) : ID(ID),
                                                                                         modelNumber(modelNumber),
                                                                                         MANAGER_num(MANAGER_num),
                                                                                         NAVIGATOR_num(NAVIGATOR_num),
                                                                                         FLY_ATTENDANT_num(
                                                                                                 FLY_ATTENDANT_num),
                                                                                         PILOT_num(PILOT_num),
                                                                                         OTHER_num(OTHER_num),
                                                                                         maxFirstClass(maxFirstClass),
                                                                                         maxEconomyClass(
                                                                                                 maxEconomyClass) {}

string MyPlane::getID() {
        return ID;
}

int MyPlane::getModelNumber() {
    return modelNumber;
}

map<Jobs, int> MyPlane::getCrewNeeded() {
    return crewToMap();
}
int MyPlane::getMaxFirstClass() {
    return maxFirstClass;
}

int MyPlane::getMaxEconomyClass() {
    return maxEconomyClass;
}

int MyPlane::getMANAGER_num() const {
    return MANAGER_num;
}

int MyPlane::getNAVIGATOR_num() const {
    return NAVIGATOR_num;
}

int MyPlane::getFLY_ATTENDANT_num() const {
    return FLY_ATTENDANT_num;
}

int MyPlane::getPILOT_num() const {
    return PILOT_num;
}

int MyPlane::getOTHER_num() const {
    return OTHER_num;
}
/************************************************************************
* function name: crew to map
* The Input: void
* The output: map of jobs and quantity of each
* The Function operation: creating a map from the object data
*************************************************************************/
map<Jobs, int> MyPlane::crewToMap() const{
    map<Jobs, int> crewNeeded;
    crewNeeded.insert(pair<Jobs, int>(MANAGER, MANAGER_num));
    crewNeeded.insert(pair<Jobs, int>(NAVIGATOR, NAVIGATOR_num));
    crewNeeded.insert(pair<Jobs, int>(FLY_ATTENDANT, FLY_ATTENDANT_num));
    crewNeeded.insert(pair<Jobs, int>(PILOT, PILOT_num));
    crewNeeded.insert(pair<Jobs, int>(OTHER, OTHER_num));
    return crewNeeded;
}
/************************************************************************
* function name: map to crew
* The Input: map of jobs and quantity of each
* The output: void
* The Function operation: mainly used for th constructor when we get a
 * map from the user we convert it to individual pieces and add it to
 * our object
*************************************************************************/
void MyPlane::mapToCrew(const map<Jobs, int> crewNeeded){
    map<Jobs, int> crewNeeded2 = crewNeeded;
    map<Jobs, int> :: iterator it;
    string crew;
    for ( it = crewNeeded2.begin(); it != crewNeeded2.end(); it++ ) {
        switch (it->first) {
            case MANAGER : MANAGER_num = it->second; break;
            case NAVIGATOR : NAVIGATOR_num = it->second; break;
            case FLY_ATTENDANT : FLY_ATTENDANT_num = it->second; break;
            case PILOT : PILOT_num = it->second; break;
            default : OTHER_num = it->second; break;
        }
    }
}