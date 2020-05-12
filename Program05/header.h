#pragma once
// Logan Mayes
// lbm7fq@mail.umkc.edu
// 201R
// 05/08/2020

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Employee
{
public:
    string Getname();
    string GetId() const; 
    void SetName(const string& NewName);
    void SetId(const string& NewId);
    virtual string GetType() { return "Employee"; };
    virtual bool ReadData(istream& inFile) = 0;
    virtual bool WriteData(ostream& outFile) = 0;
protected:
    string name = "";
    string id = "";
};


class HourlyEmployee:public Employee
{
public:
    HourlyEmployee();
    char GetExpertEmployee() const;
    double GetSalary();
    virtual string GetType() override;
    bool SetExpertEmployee(char NewExpert);
    bool SetSalary(double NewSalary);
    virtual bool ReadData(istream& inFile) override;
    virtual bool WriteData(ostream& outFile) override;
private:
    double Salary;
    char experience;
};


class MonthlyEmployee:public Employee
{
public:
    MonthlyEmployee();
    virtual string GetType() override;
    bool ReadData(istream& inFile) override;
    bool WriteData(ostream& outFile) override;
    bool SetRank(int value);
    int GetRank();

private:
    int rank;
};

#endif
