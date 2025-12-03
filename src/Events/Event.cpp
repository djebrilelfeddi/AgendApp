#include "Events/Event.hpp"

namespace Events 
{
    Event::Event(const std::string& uid, const std::string& title, const std::string& desc)  : id(uid), title(title), description(desc), beginDate(), endDate() {}

    Timestamp::Date Event::getBeginDate()      const { return beginDate; }
    Timestamp::Date Event::getEndDate()        const { return endDate; }
    Utils::MultiString Event::getDescription() const { return description; }
    std::string Event::getID()                 const { return id; }
    std::string Event::getTitle()              const { return title; }
    
    void Event::setDates(const Timestamp::Date& begin, const Timestamp::Date& end) {
        beginDate = begin;
        endDate = end;
    }

    std::string Event::toString() const {
        return std::format(
            "id: {}\ntitle: {}\ndescription: {}\nbegin date: {}\nend date: {}\n",
            id,
            title,
            description.get(),
            beginDate.toString(),
            endDate.toString()
        );
    }

    std::string Event::toHtml() const {
        return std::format("<div class='event-block'><h3>{}</h3>"
            "<p><strong>id:</strong> {}</p>"
            "<p><strong>description:</strong><br>{}</p>"
            "<p><strong>beginDate:</strong> {}</p>"
            "<p><strong>endDate:</strong> {}</p>"
            "</div>", 
            title, 
            id, 
            description.toHtml(), 
            beginDate.toString(), 
            endDate.toString()
        );
    }
}