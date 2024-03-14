/***********************************************************************
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>

using namespace std;
namespace seneca
{

    void Menu::setEmpty()
    {
        m_text = nullptr;
        m_numOptions = 0;
        m_numTabs = 0;
    }

    Menu::Menu(const char *menuContent, int numberOfTabs)
        : m_text(nullptr), m_numOptions(0), m_numTabs(numberOfTabs)
    {

        if (menuContent)
        {
            int len = strlen(menuContent) + 1;
            m_text = new char[len];
            strncpy(const_cast<char *>(m_text), menuContent, len);

            const char *ptr = m_text;
            while (*ptr && *ptr != '\0')
            {
                if (*ptr == '\n')
                {
                    m_numOptions++;
                }
                ptr++;
            }

            m_numTabs = numberOfTabs;
        }
    }

    Menu::~Menu()
    {
        delete[] m_text;
        setEmpty();
    }

    std::ostream &Menu::display(std::ostream &ostr) const
    {

        const char *ptr = m_text;

        if (m_text)
        {
            for (int i = 0; i < m_numTabs; ++i)
            {
                ostr << "   ";
            }

            while (*ptr != '\0')
            {
                cout << *ptr;

                if (*ptr == '\n')
                {
                    for (int i = 0; i < m_numTabs; ++i)
                    {
                        ostr << "   ";
                    }
                }
                ptr++;
            }

            cout << endl;

            for (int i = 0; i < m_numTabs; ++i)
            {
                ostr << "   ";
            }
            ostr << "0- Exit\n";
        }
        return ostr;
    }

    int &Menu::operator>>(int &selection)
    {

        display();

        for (int i = 0; i < m_numTabs; ++i)
        {
            cout << "   ";
        }
        cout << "> ";

        bool flag = false;
        do
        {
            flag = false;
            if (!(cin >> selection))
            {
                flag = true;
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (cin.peek() != '\n')
            {
                flag = true;
                cout << "Only enter an integer, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (selection < 0 || selection > m_numOptions)
            {
                flag = true;
                cout << "Invalid value enterd, retry[0 <= value <= " << m_numOptions << "]: ";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

        } while (flag);

        return selection;
    }
}