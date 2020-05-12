// Logan Mayes
// lbm7fq@mail.umkc.edu
// 201R
// 05/09/2020

#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;


string Employee::Getname()
{
    return name;
}

string Employee::GetId() const
{
    return id;
}

void Employee::SetName(const string& NewName)
{
    this->name = NewName;
}

void Employee::SetId(const string& NewId)
{
    this->id = NewId;
}

bool Employee::ReadData(istream& inFile)
{

    string inname, inid, space;
    if (inFile.good())
    {
        getline(inFile, space);
        getline(inFile, inname);
        getline(inFile, inid);
        Employee::SetName(inname);
        Employee::SetId(inid);
        return true;
    }
    return false;
}

HourlyEmployee::HourlyEmployee()
{
    name = "";
    id = "";
    Salary = 0;
    experience = '\0';
}

bool HourlyEmployee::SetExpertEmployee(char NewExpert)
{
    this->experience = NewExpert;
    if (experience == 'T')
    {
        return true;
    }
    return false;
}

bool HourlyEmployee::SetSalary(double NewSalary)
{
    this->Salary = NewSalary;
    if (Salary >= 1000 && Salary <= 10000)
    {
        return true;
    }
    return false;
}

char HourlyEmployee::GetExpertEmployee() const
{
    return experience;
}

double HourlyEmployee::GetSalary()
{
    return Salary;
}

string HourlyEmployee::GetType()
{
    return "Hourly Employee";
}

MonthlyEmployee::MonthlyEmployee()
{
    this->name = "";
    this->id = "";
    this->rank = 0;
}

bool MonthlyEmployee::SetRank(int value)
{
    this->rank = value;
    if (rank >= 1 && rank <= 10)
    {
        return true;
    }
    return false;
}

string MonthlyEmployee::GetType()
{
    return "Monthly Employee";
}

int MonthlyEmployee::GetRank()
{
    return rank;
}

bool HourlyEmployee::ReadData(istream& inFile)
{
    if (inFile.good())
    {
        Employee::ReadData(inFile);
        double Sal;
        char experience;

        inFile >> experience;
        inFile >> Sal;
        HourlyEmployee::SetSalary(Sal);
        HourlyEmployee::SetExpertEmployee(experience);
        return true;
    }
    else
    {
        return false;
    }

}

bool MonthlyEmployee::ReadData(istream& inFile)
{
    if (inFile.good())
    {
        Employee::ReadData(inFile);
        int Ra;


        inFile >> Ra;
        MonthlyEmployee::SetRank(Ra);
        return true;
    }
    else
    {
        return false;
    }
}

bool HourlyEmployee::WriteData(ostream& outFile)
{

    if (outFile.good())
    {
        outFile << HourlyEmployee::GetType() << endl;
        outFile << name << endl;
        outFile << id << endl;
        outFile << HourlyEmployee::GetExpertEmployee() << endl;
        outFile << HourlyEmployee::GetSalary() << endl;

        return true;
    }
    return false;
}

bool MonthlyEmployee::WriteData(ostream& outFile)
{

    if (outFile.good())
    {
        outFile << MonthlyEmployee::GetType() << endl;
        outFile << name << endl;
        outFile << id << endl;
        outFile << MonthlyEmployee::GetRank() << endl;
        return true;
    }
    return false;
}