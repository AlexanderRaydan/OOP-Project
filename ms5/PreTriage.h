/***********************************************************************
Final Project Milestone 5
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
#include "Time.h"

using namespace std;

namespace seneca
{

    const int MAXIMUM_LINEUP_VALUE = 100;

    class PreTriage
    {

    private:
        const char *m_filename;
        unsigned int m_numberOfPatientsLineup;
        Time m_averageTimeContagionTest;
        Time m_averageTimeTriage;
        Patient *m_lineup[MAXIMUM_LINEUP_VALUE] = {nullptr};

        void load();

        void save();
        void registerPatient();
        void admitPatient();
        void viewLineup();
        Time getWaitTime(const Patient &patient) const;

    public:
        PreTriage();
        PreTriage(const char *filename);

        // Copy constructor
        PreTriage(const PreTriage &preTriage);

        // Assign o operator
        PreTriage &operator=(const PreTriage &preTriage);

        // Destructor
        ~PreTriage();

        void run();
    };

}