#include "interface.h"
#include "DataBase.h"

using namespace std;
Date::Date(string date){
    if (date.length() != 10)
        throw MyException("Illegal Date");
    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));
    if(year < 0 || year > 9999)
        throw MyException("Illegal Date");
    if(month < 1 || month > 12)
        throw MyException("Illegal Date");
    if(day < 1 || day >31)
        throw MyException("Illegal Date");
    this->date = date;
}
bool Date::operator<(const Date& d) const{
    int this_year = stoi(date.substr(0,4));
    int this_month = stoi(date.substr(5,2));
    int this_day = stoi(date.substr(8,2));
    int d_year = stoi(d.date.substr(0,4));
    int d_month = stoi(d.date.substr(5,2));
    int d_day = stoi(d.date.substr(8,2));
    if (this_year < d_year)
        return true;
    else if (this_year > d_year)
        return false;
    else {
        if (this_month < d_month)
            return true;
        if (this_month > d_month)
            return false;
        else {
            if (this_day < d_day)
                return true;
            if (this_day > d_day)
                return false;
        }
    }
    return false;
}
bool Date::operator>(const Date& d) const{
    if((date == d.date) || (*this < d))
        return false;
}
bool Date::operator==(const Date& d) const{
    return date == d.date;
}

