/***********************************************************************
Final Project Milestone 4
Author   Alexander Raydan

Revision History
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "IOAble.h"
using namespace std;
namespace seneca
{
    std::ostream &operator<<(std::ostream &os, const IOAble &ioAble)
    {
        return ioAble.write(os);
    }

    std::istream &operator>>(std::istream &is, IOAble &ioAble)
    {
        return ioAble.read(is);
    }
}