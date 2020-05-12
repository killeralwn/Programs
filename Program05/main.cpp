// Logan Mayes
// lbm7fq@mail.umkc.edu
// 201R
// 05/09/2020

#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;


int main()
{
    Employee* employee[100];
    char flag;
    int amount = 0;
    int amountOfHourlyEmployee = 0;
    int amountOfMonthlyEmployee = 0;
    ifstream filein("input-1.txt");
    ofstream fileout("output.txt");

    while (!filein.eof())
    {

        filein >> flag;

        if (flag == 'H')
        {
            employee[amount] = new HourlyEmployee;
            employee[amount]->ReadData(filein);

            amountOfHourlyEmployee++;

        }
        else if (flag == 'M')
        {

            employee[amount] = new MonthlyEmployee;
            employee[amount]->ReadData(filein);

            amountOfMonthlyEmployee++;
        }
        else
        {
            cout << "There seems to be an error in the input file. Please mark (M or H) in the file." << endl;
            break;

        }
        amount++;

    }

    for (int i = 0; i < amount; ++i)
    {
        if (employee[i]->GetType() == "Monthly Employee")
        {
            employee[i]->WriteData(fileout);
        }
    }

    for (int i = 0; i < amount; ++i)
    {
        if (employee[i]->GetType() == "Hourly Employee")
        {
            employee[i]->WriteData(fileout);
        }
    }

    if (filein.eof())
    {
        cout << "You have " << amountOfHourlyEmployee << " hourly employees." << endl;
        cout << "You have " << amountOfMonthlyEmployee << " monthly employees." << endl;
    }

    filein.close();
    fileout.close();

    return 0;
}