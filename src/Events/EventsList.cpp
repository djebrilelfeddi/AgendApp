#include "Events/EventsList.hpp"
#include <iostream>
#include <algorithm>

namespace Events 
{
    std::vector<std::shared_ptr<Event>> EventsList::findByTitle(const std::string& eventTitle) const {
        std::vector<std::shared_ptr<Event>> result;
        std::copy_if(events.begin(), events.end(), std::back_inserter(result), [&](const auto& event) {
            return event->getTitle() == eventTitle;
        });
        return result;
    }   
    

    std::vector<std::shared_ptr<Event>> EventsList::findByID(const std::string& eventID) const {
        std::vector<std::shared_ptr<Event>> result;
        std::copy_if(events.begin(), events.end(), std::back_inserter(result), [&](const auto& event) {
            try {
                return event->getID() == eventID;
            } 
            catch (const std::invalid_argument& e) {
                std::cerr << "find: string isn't numeric." << std::endl;
                throw e;
            }
        });
        return result;
    }

    std::optional<std::shared_ptr<Event>> EventsList::findByIndex(const size_t index) const {
        return (index < events.size()) ? std::optional<std::shared_ptr<Event>>(events[index]) : std::nullopt;
    }

    std::string EventsList::toString() const {
        if (count() <= 0) return "No events in calendar.\n";

        std::string result;
        for (const auto& event : events) {
            result += event->toString();
            result += "------------------\n";
        }
        return result;
    }

    std::string EventsList::toHtml() const {
        std::string html = "<div class='events-list'>";
        for (const auto& event : events) {
            html += event->toHtml();
        }
        html += "</div>";
        return html;
    }

    void EventsList::display() const {
        std::cout << toString() << std::endl;
    }

    size_t EventsList::count() const {
        return events.size();
    }

    void EventsList::add(const std::shared_ptr<Event>& event) {
        if (event) {
            events.push_back(event);
        }
    }

    void EventsList::remove(const std::shared_ptr<Event>& event) {
        events.erase(
        std::remove_if(events.begin(), events.end(), [&](const auto& e) {
            return e->getID() == event->getID();
        }), events.end());
    }
}