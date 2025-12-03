#include "Timestamp/Date.hpp"

namespace Timestamp 
{
    Date::Date() : day(1), month(1), year(1), time() {}

    Date::Date(const unsigned int y, const unsigned int m, const unsigned int d) {
        setYear(y);
        setMonth(m);
        setDay(d);
    }

    Date::Date(const unsigned int d, const unsigned int m, const unsigned int y, const Time& t) : time(t) {
        setYear(y);
        setMonth(m);
        setDay(d);
    }

    Date::Date(const std::string& dateText) {
        std::istringstream iss(dateText);

        char delimiter1, delimiter2;
        unsigned int d, m, y;
        std::string timeStr;

        if (!(iss >> d >> delimiter1 >> m >> delimiter2 >> y) || delimiter1 != '/' || delimiter2 != '/') {
            throw std::invalid_argument("Format de date invalide. Attendu: DD/MM/YYYY");
        }

        setYear(y);
        setMonth(m);
        setDay(d);
        
        if (iss >> timeStr) {
            time = Time(timeStr);
        } else {
            time = Time(); 
        }
    }

    unsigned int Date::getDay() const {
        return day;
    }

    void Date::setDay(const unsigned int d) {
        day = d;
        if (!isDayValid(day, month, year)) {
            throw std::invalid_argument("Jour invalide pour le mois et l'année donnés");
        }
    }

    unsigned int Date::getMonth() const {
        return month;
    }

    void Date::setMonth(const unsigned int m) {
        if (m < 1 || m > 12) throw std::invalid_argument("Le mois doit etre compris entre 1 et 12");

        month = m;
    }

    unsigned int Date::getYear() const {
        return year;
    }

    void Date::setYear(const unsigned int y) {
        year = y;
    }

    Time Date::getTime() const {
        return time;
    }

    void Date::setTime(const Time& t) {
        time = t;
    }
    
    std::string Date::toString() const {
        constexpr std::string_view formatStr = "{:02}/{:02}/{} {}";
        return std::format(formatStr, day, month, year, time.toString());
    }

    bool isDayValid(const unsigned int day, const unsigned int month, const int year)
    {
        return day >= 1 && day <= getDaysInMonth(month, year);
    }

    unsigned int getDaysInMonth(const unsigned int month, const int year)
    {
        constexpr std::array<unsigned int, 12> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};

        if (month < 1 || month > 12) {
            throw std::out_of_range("Month is not valid");
        }
        if (month == 2 && isLeapYear(year)) {
            return 29;
        }
        return daysInMonth[month - 1];
    }
    
    bool isLeapYear(const int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

}