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
#ifndef SENECA_TEST_PATIENT_H_
#define SENECA_TEST_PATIENT_H_
#include <iostream>
#include "Patient.h"
namespace seneca
{

    class TestPatient : public Patient
    {
    public:
        TestPatient();

        char type() const;

        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);

        friend std::istream &operator>>(std::istream &istr, TestPatient &testPatient);
        friend std::ostream &operator<<(std::ostream &ostr, const TestPatient &testPatient);
    };
}
#endif
