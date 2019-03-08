#include "person.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

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
  printHighestPaid(employees);
  getCompanies(employees, companyNames);
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
  }
    inData.close();
    return count;
}

void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
  string temp;  
  for (int i = 0; i < employees.size(); i++)
  { 
    temp = employees[i].getCompanyName();
    companyNames.push_back(temp);
    //cout << companyNames[i] << endl;  // test to see it compayNames vector holds the correct values.
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
   //*******************************************// test loop to see if companyNames holds the correct values.
   // for (int i = 0; i < companyNames.size(); i++)
   // {
   //   cout << companyNames[i] << endl;
   // }
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
  float totalPay = 0.00;
  for (int i = 0; i < companyNames.size(); i++)
    {
      ofstream outData;
      outData.open(companyNames[i] + ".txt");
        for (int k = 0; k < employees.size(); k++)
          {
            if (companyNames[i] == employees[k].getCompanyName())  
              {
                outData << employees[k].fullName() << setw(5) << employees[k].getEmployeeId() << " " << employees[k].getCompanyName() << " $" << fixed << setprecision(2) << employees[k].totalPay() << endl;
                totalPay += employees[k].totalPay();     
              }
          }
      outData << "Total $" << totalPay << endl;
      totalPay = 0.00;
      outData.close();
    } 
}
