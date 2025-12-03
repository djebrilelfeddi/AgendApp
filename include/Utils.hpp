#ifndef UTILS_HPP
#define UTILS_HPP

#include <array>
#include <iostream>
#include <random>
#include <string>
#include "Timestamp/Date.hpp"

#ifdef _WIN32
    #include <windows.h>
#endif
namespace Utils
{
    std::string getUID(const size_t length);

    template<typename T>
    std::string readMultilineStream(T& stream, const std::string& endStreamText)
    {
        std::string line;
        std::string output;
        while (std::getline(stream, line) && line != endStreamText)
        {
            output += line + "\n";
        }
        if (!output.empty() && output.back() == '\n')
        {
            output.pop_back();
        }
        return output;
    };

    void clearBuffer();

    template<typename T>
    void getInput(T& var, const std::string& msg) {
        while (true) {
            std::cout << msg << "> ";
            std::cin >> var;

            if (std::cin.fail()) {
                std::cerr << "Invalid input." << std::endl;
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    }

    void getMultilineInput(std::string& var, const std::string& msg, const std::string& endStr);
    void inputDateTime(Timestamp::Date& inputDate, const std::string& label);
    void clear();
    void waitForKeyPress();
}

#endif