#include "person.cpp"
#include <iostream>
//#include <algorithm>  // maybe not needed
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
//#include <list>

using namespace std;

int readData(vector<Person> &employees);  // prototype fucntion
void getCompanies(vector<Person> &employees, vector<string> &companyNames);  // prototype function
void printHighestPaid(vector<Person> &emplyees);  // protoype function
void separateAndSave(vector<Person> &employees, vector<string> &companyNames);  // protoype function

int main()
{
  
  vector <Person> employees;
  vector <string> companyNames;

  readData(employees);
  //printHighestPaid(employees);
  
  getCompanies(employees, companyNames);    // dont need to call this fuction
  separateAndSave(employees, companyNames);

	return 0;
}

int readData(vector<Person> &employees)
{
  string first, last, coName;
  int empId;
  float hours, pay;
  int count = 0;
  Person obj;

  ifstream inData;
  inData.open("input.txt");

  while(inData >> first)
  {
    inData >> last;
    inData >> empId;
    inData >> coName;
    inData >> hours;
    inData >> pay;

    obj.setFirstName(first);
    obj.setLastName(last);
    obj.setCompanyName(coName);
    obj.setEmployeeId(empId);
    obj.setHoursWorked(hours);
    obj.setPayRate(pay);
    employees.push_back(obj);  // pushes new objects into the emplyee vector dynamically. 
    count++;
    
   // cout << first << " " << last << " " << fixed << setprecision(2) << empId << " " << coName << " " << hours << " " << fixed << setprecision(1) << pay << endl;
  }
    inData.close();
    return count;  // count is 16
}

void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
  string temp;  
  for (int i = 0; i < employees.size(); i++)
  { 
    temp = employees[i].getCompanyName();
    companyNames.push_back(temp);
  // cout << " " << companyNames[i] << endl;
  }
  
  for (unsigned i = 0; i < companyNames.size(); ++i)
  {
    for (unsigned k = 0; k < companyNames.size(); ++k)
    {
      if((companyNames[i] == companyNames[k]) && (i != k))
      {
        companyNames.erase(companyNames.begin()+k);
        k -= 2;
      }
    }
  }
}

void printHighestPaid(vector<Person> &employees)
{
   int slotRichest = 0;
   for (int i = 1; i < employees.size(); i++)
    {
      if(employees[i-1].totalPay() < employees[i].totalPay())
      {
        slotRichest = i;
      }
    }
    cout << "Highest paid: " << employees[slotRichest].fullName() << endl;
    cout << "Employee ID: " << employees[slotRichest].getEmployeeId() << endl;
    cout << "Employer: " << employees[slotRichest].getCompanyName() << endl;
    cout << "Total Pay: $" << fixed << setprecision(2) << employees[slotRichest].totalPay() << endl;
}

void separateAndSave(vector<Person> &employees, vector<string> &companyNames)
{  
    for (int i = 0; i < employees.size(); i++)
    {
      if (employees)
    //  ofstream outData;
    //  outData.open(companyNames[i]);
     // cout << employees[i].fullName() << " " << employees[i].getEmployeeId() << " " << companyNames[i] << " " << employees[i].totalPay() << endl;
    }

}
