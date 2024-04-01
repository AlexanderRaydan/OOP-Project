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

#include "Time.h"
#include "Utils.h"
#include <iomanip>

namespace seneca
{

    Time::Time(unsigned int min) : m_minutes(min) {}

    Time &Time::reset()
    {
        m_minutes = U.getTime();
        return *this;
    }

    std::ostream &Time::write(std::ostream &ostr) const
    {
        unsigned int hours = m_minutes / 60;
        unsigned int minutes = m_minutes % 60;
        ostr << std::setw(2) << std::setfill('0') << hours << ':' << std::setw(2) << minutes;
        return ostr;
    }

    std::istream &Time::read(std::istream &ist)
    {
        unsigned int hours = 0, minutes = 0;
        char colon = '\0';
        ist >> hours;

        // ist >> hours >> colon >> minutes;

        if (ist.peek() == '\n')
        {
            ist.setstate(std::ios::failbit);
            return ist;
        }

        ist >> colon >> minutes;

        if (colon != ':')
        {
            ist.setstate(std::ios::failbit);
        }
        else
        {
            m_minutes = hours * 60 + minutes;
        }
        return ist;
    }

    Time::operator unsigned int() const
    {
        return m_minutes;
    }

    Time &Time::operator*=(int val)
    {
        m_minutes *= val;
        return *this;
    }

    Time &Time::operator-=(const Time &D)
    {
        int diff = m_minutes - D.m_minutes;
        if (diff < 0)
        {
            diff += 24 * 60; // Add 24 hours in minutes
        }
        m_minutes = diff;
        return *this;
    }

    Time Time::operator-(const Time &T) const
    {
        Time temp(*this);
        temp -= T;
        return temp;
    }

    std::ostream &operator<<(std::ostream &os, const Time &time)
    {
        return time.write(os);
    }

    std::istream &operator>>(std::istream &is, Time &time)
    {
        return time.read(is);
    }

}
