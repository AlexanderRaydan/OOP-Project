/***********************************************************************
Final Project Milestone 3
Version 1.0
Author   Alexander Raydan
Revision History
-----------------------------------------------------------
Date      Reason
2024/3/9  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SENECA_TIME_H_
#define SENECA_TIME_H_
#include <iostream>
namespace seneca
{

    class Time
    {
        unsigned int m_minutes;

    public:
        Time(unsigned int min = 0u);
        Time &reset();
        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
        operator unsigned int() const;
        Time &operator*=(int val);
        Time &operator-=(const Time &D);
        Time operator-(const Time &T) const;
    };

    std::ostream &operator<<(std::ostream &os, const Time &time);
    std::istream &operator>>(std::istream &is, Time &time);
}
#endif // !SENECA_TIME_H_
