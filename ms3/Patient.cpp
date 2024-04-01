/***********************************************************************
Final Project Milestone 3
Version 1.0
Author   Alexander Raydan
Revision History
-----------------------------------------------------------
Date      Reason
2024/3/14  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#include "Patient.h"
#include <iostream>
#include <cstring>
#include <iomanip>

namespace seneca
{

    Patient::Patient(int ticketNumber) : m_name(nullptr), m_ohip(0), m_ticket(ticketNumber) {}

    Patient::~Patient()
    {
        delete[] m_name;
    }

    Patient::Patient(const Patient &other) : m_ohip(other.m_ohip), m_ticket(other.m_ticket)
    {
        if (other.m_name != nullptr)
        {
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
        }
        else
        {
            m_name = nullptr;
        }
    }

    Patient &Patient::operator=(const Patient &other)
    {
        if (this != &other)
        {
            delete[] m_name;
            m_ticket = other.m_ticket;
            m_ohip = other.m_ohip;

            if (other.m_name != nullptr)
            {
                m_name = new char[strlen(other.m_name) + 1];
                strcpy(m_name, other.m_name);
            }
            else
            {
                m_name = nullptr;
            }
        }
        return *this;
    }

    // Type function (pure virtual)
    char Patient::type() const
    {
        return '\0';
    }

    bool Patient::operator==(char ch) const
    {
        return type() == ch;
    }

    bool Patient::operator==(const Patient &other) const
    {
        return type() == other.type();
    }

    void Patient::setArrivalTime()
    {
        m_ticket.resetTime();
    }

    Time Patient::time() const
    {
        return m_ticket.time();
    }

    int Patient::number() const
    {
        return m_ticket.number();
    }

    Patient::operator bool() const
    {
        return m_name != nullptr;
    }

    Patient::operator char *() const
    {
        return m_name;
    }

    // Write Patient Information into ostream
    std::ostream &Patient::write(std::ostream &ostr) const
    {
        if (!ostr) // Check if the ostream is in a valid state
            return ostr;

        if (!m_name)
        { // If the patient is in an invalid empty state
            ostr << "Invalid Patient Record" << std::endl;
        }
        else
        {
            if (&ostr == &std::cout)
            {
                ostr << m_ticket << std::endl;                       // Insert ticket information
                ostr << m_name << ", OHIP: " << m_ohip << std::endl; // Insert name and OHIP number
            }
            else if (&ostr == &std::clog)
            {
                ostr.width(53);
                ostr.fill('.');
                ostr << std::left << m_name;
                ostr.fill(' ');
                ostr << m_ohip << std::setw(5) << std::right << m_ticket.number() << " " << m_ticket.time();
            }
            else
            {
                ostr << type() << "," << m_name << "," << m_ohip << ",";
            }
        }
        return ostr;
    }

    std::istream &Patient::read(std::istream &istr)
    {
        if (!istr)
            return istr;

        if (&istr == &std::cin)
        {
            std::cout << "Name: ";
            char tempName[51] = {0};
            istr.get(tempName, 51, '\n');
            istr.ignore(10000, '\n');

            // Allocate memory for name and copy
            delete[] m_name;
            m_name = new char[strlen(tempName) + 1];
            strcpy(m_name, tempName);

            std::cout << "OHIP: ";
            bool flag = false;
            do
            {
                flag = false;
                istr >> m_ohip;
                if (istr.fail())
                {
                    flag = true;
                    std::cout << "Bad integer value, try again: ";
                    istr.clear();
                    istr.ignore(10000, '\n');
                    continue;
                }
                if (m_ohip < 100000000 || m_ohip > 999999999)
                {
                    flag = true;
                    std::cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
                    istr.clear();
                    istr.ignore(10000, '\n');
                    continue;
                }

            } while (flag);
        }
        else
        {
            // Read name
            char tempName[51];
            istr.get(tempName, 51, ','); // Ignore comma
            delete[] m_name;
            m_name = new char[strlen(tempName) + 1]; // Allocate memory for name
            strcpy(m_name, tempName);
            istr.ignore(10000, ','); // Ignore comma

            // Read OHIP number
            istr >> m_ohip;
            istr.ignore(10000, ','); // Ignore comma

            // Read ticket
            m_ticket.read(istr);
            istr.ignore(10000, '\n');
        }

        return istr;
    }

    std::istream &operator>>(std::istream &in, Patient &acct)
    {
        return acct.read(in);
    }

    std::ostream &operator<<(std::ostream &out, const Patient &acct)
    {
        return acct.write(out);
    }

} // namespace seneca
