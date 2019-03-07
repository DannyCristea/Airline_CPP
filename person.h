//begin person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
    string firstName;
    string lastName;
    int    employeeID;
    string companyName;
    float  hoursWorked;
    float  payRate;

public:
    inline Person();
    
    void inline setFirstName(string fName);
    
    string inline getFirstName();
    
    void inline setLastName(string lName);
    
    string inline getLastName();
    
    void inline setEmployeeId(int id);
   
    int inline getEmployeeId();
    
    void inline setCompanyName(string coName);
    
    string inline getCompanyName();
    
    void inline setPayRate(float rate);
    
    float inline getPayRate();
    
    void inline setHoursWorked(float hours);
    
    float inline getHoursWorked();
    
    float inline totalPay();
    
    string inline fullName();
};
#endif // end person.h
