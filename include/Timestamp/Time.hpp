#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <sstream>
#include <format>

#include "../interfaces/IStringConvertible.hpp"

namespace Timestamp 
{
    class Time final : public IStringConvertible
    {
    public:
        //Constructeurs
        Time();
        Time(const unsigned int h, const unsigned int m);
        explicit Time(const std::string& timeText);

        //getters
        unsigned int getHour()   const;
        unsigned int getMinute() const;

        //Setters
        void setHour(const unsigned int h);
        void setMinute(const unsigned int m);

        //Méthode virtuelle override
        std::string toString() const override;

    private:
        unsigned int hour;
        unsigned int minute;
    };
}

#endif