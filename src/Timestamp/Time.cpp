#include "Timestamp/Time.hpp"

namespace Timestamp 
{
    Time::Time() : hour(0), minute(0) {}
    Time::Time(const unsigned int h, const unsigned int m) {
        setHour(h);
        setMinute(m);
    }
    Time::Time(const std::string& timeText) {
        std::istringstream iss(timeText);
        char delimiter;
        unsigned int h, m;

        if (!(iss >> h >> delimiter >> m) || delimiter != ':') {
            throw std::invalid_argument("Format d'heure invalide. Attendu: HH:MM");
        }
        setHour(h);
        setMinute(m);
    }

    unsigned int Time::getHour()   const { return hour;   }
    unsigned int Time::getMinute() const { return minute; }

    void Time::setHour(const unsigned int h) {
        if (h > 23) {
            throw std::invalid_argument("L'heure doit etre comprise entre 0 et 23");
        }
        hour = h;
    }

    void Time::setMinute(const unsigned int m) {
        if (m > 59) {
            throw std::invalid_argument("Les minutes doivent etre comprises entre 0 et 59");
        }
        minute = m;
    }
    
    std::string Time::toString() const {
        return std::format("{:02}:{:02}", hour, minute);
    }
}