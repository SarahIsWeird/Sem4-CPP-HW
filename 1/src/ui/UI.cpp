#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

#include "UI.h"

void UI::Start() {
    Complex complex { 0, 0 };
    int option;

    while (true) {
        UI::PrintHelp();

        do {
            option = this->AskFor<int>("Please enter a menu option: ", "Please enter a valid option: ");
        } while (option < 0 || option > 9);

        std::cout << std::endl;

        /*
         * Could be improved by having a MenuOption class with an option name, description and OnCalled() method.
         * Kinda overkill for this simple application, though.
         */
        switch (option) {
            case 0: /* Exit the program */
                std::cout << "Bye!" << std::endl;

                return;
            case 1: /* Set the real component */
                complex.SetReal(this->AskForComponent("real"));

                break;
            case 2: /* Set the imaginary component */
                complex.SetImaginary(this->AskForComponent("imaginary"));

                break;
            case 3: /* Set both cartesian components */
                complex.SetReal(this->AskForComponent("real"));
                complex.SetImaginary(this->AskForComponent("imaginary"));

                break;
            case 4: /* Set the magnitude component */
                complex.SetMagnitude(this->AskForComponent("magnitude"));

                break;
            case 5: /* Set the angle component */
                complex.SetAngle(this->AskForComponent("angle"));

                break;
            case 6: /* Set both polar components */
                complex.SetMagnitude(this->AskForComponent("magnitude"));
                complex.SetAngle(this->AskForComponent("angle"));

                break;
            case 7: /* Output the cartesian components */
                std::cout << "a + bi\n"
                          << complex.ToCartesianString() << std::endl;

                break;
            case 8: /* Output the polar components */
                std::cout << "r * e^(i * theta)\n"
                          << complex.ToPolarString() << std::endl;

                break;
            case 9: /* Output both the cartesian and the polar components */
                std::cout << "a + bi / r * e^(i * theta)\n"
                          << complex.ToString() << std::endl;

                break;
        }
    }
}

void UI::PrintHelp() {
    std::cout << "\n"
              << "0: Exit the program\n"
              << "1: Set the real component\n"
              << "2: Set the imaginary component\n"
              << "3: Set both cartesian components\n"
              << "4: Set the magnitude\n"
              << "5: Set the angle\n"
              << "6: Set both polar components\n"
              << "7: Print the cartesian components\n"
              << "8: Print the polar components\n"
              << "9: Print both variants"
              << std::endl;
}

/* In my defense: It's reusable now! :D */
template <typename T> requires util::Formattable<T>
T UI::AskFor(const std::string& query, const std::string& error_query) {
    std::string input;
    T type;

    std::cout << query;

    while (true) {
        std::cin >> input; /* Must be split so that stdin is actually consumed, otherwise we get an infinite loop :( */
        std::stringstream ss(input); /* We need stream::fail */

        ss >> type;

        if (!ss.fail()) return type;
        
        std::cout << error_query;
    }
}

double UI::AskForComponent(const std::string& what) {
    return this->AskFor<double>("Please enter the " + what + " component: ", "Please enter a valid number: ");
}