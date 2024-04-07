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

#ifndef SENECA_IO_ABLE_H_
#define SENECA_IO_ABLE_H_
#include <iostream>
namespace seneca
{
    class IOAble
    {
    public:
        virtual std::ostream &write(std::ostream &ostr) const = 0;
        virtual std::istream &read(std::istream &istr) = 0;
        virtual ~IOAble(){};

        friend std::ostream &operator<<(std::ostream &os, const IOAble &ioAble);
        friend std::istream &operator>>(std::istream &is, IOAble &ioAble);
    };

}
#endif // !SENECA_IO_ABLE_H_
