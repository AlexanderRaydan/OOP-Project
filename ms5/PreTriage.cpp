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
#include <fstream>
#include <cstring>
#include <iomanip>
#include "PreTriage.h"
#include "Patient.h"
#include "TriagePatient.h"
#include "TestPatient.h"
#include "Menu.h"

using namespace std;

namespace seneca
{

    PreTriage::PreTriage() : m_filename(nullptr), m_numberOfPatientsLineup(0), m_averageTimeContagionTest(15), m_averageTimeTriage(5) {}

    PreTriage::PreTriage(const char *filename) : m_filename(nullptr), m_numberOfPatientsLineup(0), m_averageTimeContagionTest(15), m_averageTimeTriage(5)
    {
        if (!filename)
        {
            m_filename = nullptr;
            return;
        }

        m_filename = new char[strlen(filename) + 1];
        strcpy(const_cast<char *>(m_filename), filename);

        load();
    }
    // Copy constructor
    PreTriage::PreTriage(const PreTriage &preTriage)
    {
        // Shallow copy of filename
        if (!preTriage.m_filename)
        {
            m_filename = nullptr;
            return;
        }

        m_filename = new char[strlen(preTriage.m_filename) + 1];
        strcpy(const_cast<char *>(m_filename), preTriage.m_filename);

        // Copy other members
        m_numberOfPatientsLineup = preTriage.m_numberOfPatientsLineup;
        m_averageTimeContagionTest = preTriage.m_averageTimeContagionTest;
        m_averageTimeTriage = preTriage.m_averageTimeTriage;

        load();
    }

    // Assign operator
    PreTriage &PreTriage::operator=(const PreTriage &preTriage)
    {
        if (this == &preTriage) // Self-assignment check
            return *this;

        // Delete existing dynamic memory
        for (unsigned int i = 0; i < m_numberOfPatientsLineup; ++i)
        {
            delete m_lineup[i];
        }
        delete[] m_filename;

        if (!preTriage.m_filename)
        {
            m_filename = nullptr;
            return *this;
        }

        m_filename = new char[strlen(preTriage.m_filename) + 1];
        strcpy(const_cast<char *>(m_filename), preTriage.m_filename);

        // Copy other members
        m_numberOfPatientsLineup = preTriage.m_numberOfPatientsLineup;
        m_averageTimeContagionTest = preTriage.m_averageTimeContagionTest;
        m_averageTimeTriage = preTriage.m_averageTimeTriage;

        load();

        return *this;
    }

    // Destructor
    PreTriage::~PreTriage()
    {
        save();
        // Delete dynamic memory
        for (unsigned int i = 0; i < m_numberOfPatientsLineup; ++i)
        {
            delete m_lineup[i];
        }
        delete[] m_filename;
    }

    void PreTriage::load()
    {
        cout << "Loading data...\n";

        // Open the data file
        ifstream file(m_filename);
        if (!file.is_open())
        {
            cout << "No data or bad data file!\n"
                 << endl;
            return;
        }

        // Read average wait times
        char comma;
        file >> m_averageTimeContagionTest >> comma >> m_averageTimeTriage;

        // Read patient records
        char type;
        while (file >> type)
        {
            if (m_numberOfPatientsLineup >= MAXIMUM_LINEUP_VALUE)
            {
                cout << "Warning: number of records exceeded " << MAXIMUM_LINEUP_VALUE << "\n";
                break;
            }

            Patient *patient = nullptr;

            if (type == 'T')
            {
                patient = new TriagePatient();
            }
            else if (type == 'C')
            {
                patient = new TestPatient();
            }

            file.ignore();
            patient->read(file);
            m_lineup[m_numberOfPatientsLineup++] = patient;
        }

        file.close();

        if (m_numberOfPatientsLineup > 0)
        {
            cout << m_numberOfPatientsLineup << " Records imported...\n"
                 << endl;
        }
        else
        {
            cout << "No data or bad data file!\n"
                 << endl;
        }
    }

    void PreTriage::save()
    {

        cout << "Saving lineup..." << endl;

        // Open the data file
        ofstream file(m_filename);

        if (!file.is_open())
        {
            cout << "No data or bad data file!\n"
                 << endl;
            return;
        }

        file << m_averageTimeContagionTest << "," << m_averageTimeTriage << endl;

        unsigned int triagePatientCount = 0;
        unsigned int testPatientCount = 0;

        for (unsigned int i = 0; i < m_numberOfPatientsLineup; i++)
        {
            m_lineup[i]->type() == 'T' ? triagePatientCount++ : testPatientCount++;
            m_lineup[i]->write(file) << endl;
        }
        cout << testPatientCount << " Contagion Tests and " << triagePatientCount << " Triage records were saved!" << endl;
    }

    void PreTriage::run()
    {
        Menu m("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
        int selection;

        while (m >> selection)
        {
            switch (selection)
            {

            case 1:
                // registerPatient();
                break;
            case 2:
                // admitPatient();
                break;
            case 3:
                // viewLineup();
                break;
            case 0:
                cout << "Exiting Pre-Triage application...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
}