#ifndef EVENTSLIST_HPP
#define EVENTSLIST_HPP

#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "Event.hpp"
#include "../interfaces/IHtmlConvertible.hpp"

namespace Events 
{
    class EventsList final : public IHtmlConvertible
    {
    public:
        //Constructeur et Destructeur
        EventsList() = default;
        ~EventsList() noexcept override = default;

        //Getters
        std::optional<std::shared_ptr<Event>> findByIndex(size_t index)                  const;
        std::vector<std::shared_ptr<Event>>   findByTitle(const std::string& eventTitle) const;
        std::vector<std::shared_ptr<Event>>   findByID(const std::string& eventID)       const;

        //Méthodes virtuelles override
        std::string toString() const override;
        std::string toHtml()   const override;

        //Autres méthodes
        size_t count() const;
        void display() const;
        void add(const std::shared_ptr<Event>& event);
        void remove(const std::shared_ptr<Event>& event);

    private:
        std::vector<std::shared_ptr<Event>> events;
    };
}

#endif
