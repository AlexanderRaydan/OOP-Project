/******************************************************************************
                        Milestone - #1
Full Name  : Jhonattan Gomez
Student ID#: 106321235
Email      : jgomez29@myseneca.ca
Date   	   : 2024-03-11

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "Menu.h"

using namespace std;
namespace seneca {
    // This constructor is designed to initialize a Menu object. It takes two parameters: a pointer to a character string menuContent, and an optional integer numberOfTabs with a default value of 0.
    // The constructor dynamically allocates memory to store the content pointed to by menuContent in the member variable m_text.It then scans m_text to count the number of newline characters(\n), which is used to determine the number of options in the menu.
    // The numberOfTabs parameter specifies the number of indentation tabs to be applied when displaying the menu.This allows for flexible formatting of the menu display.If not provided, no tabs will be applied by default.
    Menu::Menu(const char* menuContent, int numberOfTabs) {
        // Dynamically allocate memory for m_text and copy menuContent
        if (menuContent != nullptr) {
            size_t length = strlen(menuContent);
            m_text = new char[length + 1];
            strcpy(const_cast<char*>(m_text), menuContent);

            // Count the number of newline characters to determine m_optionsNumber
            const char* ptr = m_text;
            while (*ptr != '\0') {
                if (*ptr == '\n') {
                    ++m_optionsNumber;
                }
                ++ptr;
            }
        }
        if (numberOfTabs > 0) {
            m_indetationTabs = numberOfTabs;
        }
    }
    // Deallocates the dynamically allocated memory.
    Menu::~Menu() {
        if (m_text != nullptr) {
            delete[] m_text;
            m_text = nullptr;
        }
    }

    // The display method is responsible for presenting the Menu content to the user. It first outputs the menu options and a new line. Following the list of options, it prints:
    //    0 - Exit
    //    > _
    // This provides an option for the user to exit the menu and also indicates where the user can input their choice.
    // If the number of tabs attribute is not zero, the display method will indent the menu.Each tab corresponds to three spaces.This allows for adjustable formatting of the menu display.
    // Here are examples of how the menu would be displayed :
    // A menu with no indentation(i.e., number of tabs is 0) :
        /*Tester Options menu:
        1 - Option one
        2 - Option two
        0 - Exit
        >*/
    // 
    // A menu with number of tabs set to 2:
              /*Tester Options menu :
              1 - Option one
              2 - Option two
              0 - Exit
              >*/
    // In the second example, each line of the menu is indented by six spaces(two tabs * three spaces per tab) for a more structured visual presentation.This feature enhances the flexibility and user - friendliness of your menu system.
    std::ostream& Menu::display(std::ostream& os) {
        int i = 0;

        for (int j = 0; j < strlen(m_text); j++) {
            if (m_indetationTabs > 0 && j == 0) {
                for (int n = 0; n < m_indetationTabs; ++n) {
                    os << "   ";
                }
                i++;
            }
            if (m_text[j] != '\n') {
                os << m_text[j];
            }
            else {
                os << m_text[j];
                
                if (m_indetationTabs > 0 && i <= m_optionsNumber) {
                    for (int n = 0; n < m_indetationTabs; ++n) {
                        os << "   ";
                    }
                    i++;
                }
                
            }
        }

        os << endl;

        // Display exit option and input prompt
        for (int n = 0; n < m_indetationTabs; ++n) {
            os << "   ";
        }
        os << "0 - Exit" << endl;
        for (int n = 0; n < m_indetationTabs; ++n) {
            os << "   ";
        }
        os << "> ";

        return os;
    }
    // The member insertion operator first calls the display function and then receives the user's selection as an integer value. The integer reference selection argument is then set to this value and returned.
    // Make sure that the entered value is validated as an integer(with no trailing characters) and also the value should be between 0 and the number of options in the menu.
    // If the above conditions are not met, a proper error message should be displayed and re - entry requested(see below)
    // Assuming that the menu content is set to : "Tester Options menu:\n1- Option one\n2- Option two\n3- Option three", (hence the number of selections will 3) the operator>> should run like this :
       /*Tester Options menu :
       1 - Option one
       2 - Option two
       3 - Option three
       0 - Exit
       > abc
       Bad integer value, try again: 1 (with a space after 1)
       Only enter an integer, try again : -1
       Invalid value enterd, retry[0 <= value <= 3] : 4
       Invalid value enterd, retry[0 <= value <= 3] : 2*/
    // 2 is returned as user's selection.
    int& Menu::operator>>(int& Selection) {
        int numOptions = m_optionsNumber;
        int userInput;
        display(std::cout); // Call display function to show menu
        while (true) {
            
            std::string input;
            std::getline(std::cin, input);

            std::stringstream ss(input);
            if (ss >> userInput && ss.eof()) {
                if (userInput >= 0 && userInput <= numOptions) {
                    Selection = userInput;
                    break;
                }
                else {
                    std::cout << "Invalid value entered, retry [0 <= value <= " << numOptions << "]: ";
                }
            }
            else {
                std::cout << "Only enter an integer, try again: ";
            }
        }

        return Selection;
    }
}