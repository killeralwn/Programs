// Logan Mayes
// lbm7fq@mail.umkc.edu
// 5/11/2020
// 201R
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include "Header.h"

using namespace std;


void printOneMonth(int year, int month, int getFirstDay)
{
    int days = 0;
    string monthName;
    days = DayPerMonth(month, year);
    const string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    monthName = months[month - 1];

    cout << "\t" << monthName << " " << year << endl;
    cout << "____________________________________" << endl;
    cout << "   Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

    int i = 0;
    int firstDay = 0;
    int dayOfWeek = 0;

    switch (month)
    {
    case 1:
        firstDay = getFirstDay;
        break;
    case 2:
        firstDay = getFirstDay + 3;
        break;
    case 3:
        firstDay = getFirstDay + 3;
        break;
    case 4:
        firstDay = getFirstDay + 6;
        break;
    case 5:
        firstDay = getFirstDay + 8;
        break;
    case 6:
        firstDay = getFirstDay + 11;
        break;
    case 7:
        firstDay = getFirstDay + 13;
        break;
    case 8:
        firstDay = getFirstDay + 16;
        break;
    case 9:
        firstDay = getFirstDay + 19;
        break;
    case 10:
        firstDay = getFirstDay + 21;
        break;
    case 11:
        firstDay = getFirstDay + 24;
        break;
    case 12:
        firstDay = getFirstDay + 26;
        break;
    }

    if (isLeapYear(year))
    {
        switch (month)
        {
        case 1:
            firstDay = getFirstDay;
            break;
        case 2:
            firstDay = getFirstDay + 3;
            break;
        case 3:
            firstDay = getFirstDay + 4;
            break;
        case 4:
            firstDay = getFirstDay + 7;
            break;
        case 5:
            firstDay = getFirstDay + 9;
            break;
        case 6:
            firstDay = getFirstDay + 12;
            break;
        case 7:
            firstDay = getFirstDay + 14;
            break;
        case 8:
            firstDay = getFirstDay + 17;
            break;
        case 9:
            firstDay = getFirstDay + 20;
            break;
        case 10:
            firstDay = getFirstDay + 22;
            break;
        case 11:
            firstDay = getFirstDay + 25;
            break;
        case 12:
            firstDay = getFirstDay + 27;
            break;
        }
    }

    if ((firstDay % 7) >= 0)
    {
        if ((firstDay % 7) == 0)
        {
            dayOfWeek = 0;
        }

        else if ((firstDay % 7) == 1)
        {
            dayOfWeek = 1;
            cout << " ";
        }

        else if ((firstDay % 7) == 2)
        {
            dayOfWeek = 2;
            cout << "\t ";
        }

        else if ((firstDay % 7) == 3)
        {
            dayOfWeek = 3;
            cout << "\t\t";
        }

        else if ((firstDay % 7) == 4)
        {
            dayOfWeek = 4;
            cout << "\t\t ";
        }

        else if ((firstDay % 7) == 5)
        {
            dayOfWeek = 5;
            cout << "\t\t\t";
        }

        else if ((firstDay % 7) == 6)
        {
            dayOfWeek = 6;
            cout << "\t\t\t ";
        }
    }

    for (int j = 1; j <= days; j++)
    {
        printf("%5d", j);

        if (++i > 6)
        {
            i = 0;
            printf("\n");
        }
    }
    cout << endl;
}

int DayPerMonth(int MonthNumber, int Year)
{
    int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(Year))
    {
        if (MonthNumber == 2)
            return 29;
        else
            return months[MonthNumber - 1];
    }

    else
    {
        return months[MonthNumber - 1];
    }
}

int GetStartDayNember()
{
    string week[] = { "sunday","monday","tuesday","wednesday","thursday","friday","saturday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
    string day;
    int flag = 0;

    while (true)
    {
        cout << "What day of the week does Jan 1 fall on this year? ";
        cin >> day;

        for (int i = 0; i < day.size(); i++)
        {
            if (day.at(i) >= 65 && day.at(i) <= 90)
            {
                day.at(i) = day.at(i) + 32;
            }
        }

        for (int i = 0; i < day.size(); i++)
        {
            if (day.compare(week[i]) == 0)
            {
                flag = 1;
                return i;
            }
        }

        if (flag == 0)
        {
            cout << "Please check the spelling of your days." << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}

int GetYear()
{
    int year;

    while (true)
    {
        cout << "Enter Year (must be in range 1000 <= Year <= 9999) : ";
        cin >> year;

        if (cin.fail())
        {
            cout << "I'm sorry, you must enter a number" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }

        else if (year < 1000 || year>9999)
        {
            cout << "I'm sorry, but the year must be between 1000 and 9999" << endl;
        }

        else
        {
            break;
        }
    }
    return year;
}

bool isLeapYear(int year)
{
    if (year % 400 == 0) {
        return true;
    }

    if (year % 100 == 0) {
        return false;
    }

    if (year % 4 == 0) {
        return true;
    }

    return false;
}
