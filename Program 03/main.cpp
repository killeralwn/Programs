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


int main()
{
    int getFirstDay;
    int year;
    year = GetYear();
    getFirstDay = GetStartDayNember();

    for (int i = 1; i <= 12; i++)
    {
        printOneMonth(year, i, getFirstDay);
    }
    return 0;
}