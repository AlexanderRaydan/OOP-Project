/***********************************************************************
Final Project Milestone 1
Module: Menu
Filename: Menu.h
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

#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_
#include <iostream>
namespace seneca
{
    class Menu
    {
        const char *m_text;
        int m_numOptions;
        int m_numTabs;

    public:
        Menu(const char *menuContent, int numberOfTabs = 0);
        ~Menu();

        void setEmpty();

        Menu(const Menu &) = delete;
        Menu &operator=(const Menu &) = delete;

        std::ostream &display(std::ostream &ostr = std::cout) const;

        int &operator>>(int &selection);
    };
}
#endif // !SENECA_MENU_H_
