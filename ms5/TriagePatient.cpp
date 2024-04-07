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
#include "TriagePatient.h"

using namespace std;

namespace seneca
{
    int nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket)
    {
        m_symptoms = nullptr;
        nextTriageTicket++;
    }

    char TriagePatient::type() const
    {
        return 'T';
    }

    TriagePatient::TriagePatient(const TriagePatient &triagePatient) : Patient(triagePatient.number())
    {
        if (triagePatient.m_symptoms != nullptr)
        {
            operator=(triagePatient);
        }

        m_symptoms = nullptr;
    }
    TriagePatient &TriagePatient::operator=(const TriagePatient &triagePatient)
    {
        if (this != &triagePatient)
        {
            Patient::operator=(triagePatient);

            delete[] m_symptoms;
            m_symptoms = nullptr;

            if (triagePatient.m_symptoms != nullptr)
            {
                if ((strlen(triagePatient.m_symptoms) + 1) < SYMPTOMS_LENGTH)
                {
                    m_symptoms = new char[strlen(triagePatient.m_symptoms) + 1];
                    strcpy(m_symptoms, triagePatient.m_symptoms);
                }
                else
                {
                    strncpy(triagePatient.m_symptoms, triagePatient.m_symptoms, SYMPTOMS_LENGTH + 1);
                    triagePatient.m_symptoms[SYMPTOMS_LENGTH] = '\0';
                }
            }
        }

        return *this;
    }
    TriagePatient::~TriagePatient()
    {
        delete[] m_symptoms;
        m_symptoms = nullptr;
    }

    std::ostream &TriagePatient::write(std::ostream &ostr) const
    {
        if (&ostr == &std::cout)
        {
            ostr << "TRIAGE" << endl;
            Patient::write(ostr);
            ostr << "Symptoms: " << m_symptoms << endl;
        }
        else if (&ostr == &std::clog)
        {
            Patient::write(ostr);
        }
        else
        {
            Patient::write(ostr);
            ostr << "," << m_symptoms;
        }
        return ostr;
    }
    std::istream &TriagePatient::read(std::istream &istr)
    {
        Patient::read(istr);
        if (&istr == &std::cin)
        {
            istr.clear();
            std::cout << "Symptoms: ";
            istr.ignore(10000, '\n');
            char symptom[SYMPTOMS_LENGTH];
            istr.getline(symptom, SYMPTOMS_LENGTH + 1);

            delete[] m_symptoms;
            m_symptoms = new char[strlen(symptom) + 1];
            strcpy(m_symptoms, symptom);
        }
        else
        {
            delete[] m_symptoms;
            m_symptoms = nullptr;
            m_symptoms = new char[SYMPTOMS_LENGTH + 1];
            // istr.ignore(1000, ',').ignore(1000, ',').ignore(1000, ',').ignore(1000, ',');
            istr.get(m_symptoms, 1000, '\n');
            istr.ignore(10000, '\n');
        }

        nextTriageTicket = Patient::number() + 1;
        return istr;
    }

    std::ostream &operator<<(std::ostream &os, const TriagePatient &triagePatient)
    {
        return triagePatient.write(os);
    }
    std::istream &operator>>(std::istream &istr, TriagePatient &triagePatient)
    {
        if (&istr == &std::cin)
        {
            return triagePatient.read(istr);
        }
        else
        {
            istr.clear();
            istr.seekg(0, ios::beg);
            return triagePatient.read(istr);
        }
    }
}