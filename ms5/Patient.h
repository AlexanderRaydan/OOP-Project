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

#ifndef SENECA_PATIENT_H_
#define SENECA_PATIENT_H_

#include <iostream>
#include "Ticket.h"

namespace seneca
{
    class Patient
    {
    private:
        char *m_name;
        int m_ohip;
        Ticket m_ticket;

    public:
        Patient(int ticketNumber);

        virtual ~Patient();

        Patient(const Patient &other);

        Patient &operator=(const Patient &other);

        virtual char type() const = 0;

        bool operator==(char ch) const;

        bool operator==(const Patient &other) const;

        void setArrivalTime();

        Time time() const;

        int number() const;

        operator bool() const;

        operator char *() const;

        virtual std::ostream &write(std::ostream &ostr) const;

        virtual std::istream &read(std::istream &istr);

        friend std::istream &operator>>(std::istream &in, Patient &acct);
        friend std::ostream &operator<<(std::ostream &out, const Patient &acct);
    };

} // namespace seneca

#endif // SENECA_PATIENT_H_
