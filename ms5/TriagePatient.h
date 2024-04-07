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

#ifndef SENECA_TRIAGE_PATIENT_H_
#define SENECA_TRIAGE_PATIENT_H_
#include <iostream>
#include "Patient.h"
namespace seneca
{
    const int SYMPTOMS_LENGTH = 512;
    class TriagePatient : public Patient
    {
        char *m_symptoms;

    public:
        TriagePatient();
        char type() const;

        TriagePatient(const TriagePatient &triagePatient);

        TriagePatient &operator=(const TriagePatient &triagePatient);

        ~TriagePatient();

        std::ostream &write(std::ostream &ostr) const;

        std::istream &read(std::istream &istr);

        friend std::istream &operator>>(std::istream &is, TriagePatient &triagePatient);
        friend std::ostream &operator<<(std::ostream &os, const TriagePatient &triagePatient);
    };
}
#endif