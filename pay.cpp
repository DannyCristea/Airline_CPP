#include "person.h"
#include "person.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readData(vector<Person> &employees);  // prototype fucntion
void getCompanies(vector<Person> &employees, vector<string> &companyNames);  // prototype function
void printHighestPaid();  // protoype function
void separateAndSave();  // protoype function

int main()
{
  vector <Person> employees;
  vector <string> companyNames;



	return 0;
}

void readData(vector<Person> &employees)
{
  string first, last, coName;
  int empId;
  float hours, pay;
  Person obj;

  ifstream inData;
  inData.open("input.txt");

  while(inData >> first)
  {
    inData >> last;
    inData >> coName;
    inData >> empId;
    inData >> hours;
    inData >> pay;

    obj.setFirstName(first);
    obj.setLastName(last);
    obj.setCompanyName(coName);
    obj.setEmployeeId(empId);
    obj.setHoursWorked(hours);
    obj.setPayRate(pay);
    employees.push_back(obj);
  }
    inData.close();
}

void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
  //  string tmpName = "";
  //  while(employees)
  //  {

  //  }
}

void printHighestPaid()
{

}

void separateAndSave()
{

}
