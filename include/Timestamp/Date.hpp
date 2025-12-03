#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <string>
#include <sstream>

#include "Time.hpp"

#include "../interfaces/IStringConvertible.hpp"

namespace Timestamp 
{
    class Date final : public IStringConvertible
    {
    public:
        //Constructeurs
        Date();
        Date(const unsigned int d, const unsigned int m, const unsigned int y);
        Date(const unsigned int d, const unsigned int m, const unsigned int y, const Time& t);
        explicit Date(const std::string& dateText);

        //Getters
        unsigned int getDay()   const;
        unsigned int getMonth() const;
        unsigned int getYear()  const;
        Time getTime()          const;

        //Setters
        void setDay(const unsigned int d);
        void setMonth(const unsigned int m);
        void setYear(const unsigned int y);
        void setTime(const Time& t);

        //Méthode virtuelle override
        std::string toString() const override;

    private:
        unsigned int day   = 1;
        unsigned int month = 1;
        int year           = 1;
        Time time;

    };

    bool isDayValid(const unsigned int day, const unsigned int month, const int year);
    bool isLeapYear(const int year);
    unsigned int getDaysInMonth(const unsigned int month, const int year);
}

#endif