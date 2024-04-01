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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "TestPatient.h"

using namespace std;

namespace seneca
{
    int nextTestTicket = 1;

    TestPatient::TestPatient() : Patient(nextTestTicket)
    {
        nextTestTicket++;
    }
    char TestPatient::type() const
    {
        return 'C';
    }
    std::ostream &TestPatient::write(std::ostream &os) const
    {
        if (&os == &std::cout)
        {
            os << "Contagion TEST" << endl;
            Patient::write(os);
        }
        else
        {
            Patient::write(os);
        }

        return os;
    }
    std::istream &TestPatient::read(std::istream &istr)
    {
        Patient::read(istr);
        nextTestTicket = Patient::number() + 1;
        return istr;
    }

    std::ostream &operator<<(std::ostream &ostr, const TestPatient &testPatient)
    {
        return testPatient.write(ostr);
    }
    std::istream &operator>>(std::istream &istr, TestPatient &testPatient)
    {
        return testPatient.read(istr);
    }
}
