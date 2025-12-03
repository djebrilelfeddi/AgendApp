#ifndef EVENT_HPP
#define EVENT_HPP

#include "./MultiString.hpp"
#include "./Timestamp/Date.hpp"
#include "../interfaces/IHtmlConvertible.hpp"

namespace Events
{
    class Event final : public IHtmlConvertible
    {
    public:
        //Constructeurs
        Event() = default;
        Event(const std::string &eventId, const std::string &title, const std::string &desc);

        //Getters et Setters
        std::string getID()                 const;
        std::string getTitle()              const;
        Timestamp::Date getBeginDate()      const;
        Timestamp::Date getEndDate()        const;
        Utils::MultiString getDescription() const;

        //Setters
        void setDates(const Timestamp::Date &begin, const Timestamp::Date &end);

        //Méthodes virtuelles override
        std::string toString() const override;
        std::string toHtml()   const override;

    private:
        std::string id;
        std::string title;
        Utils::MultiString description;
        Timestamp::Date beginDate;
        Timestamp::Date endDate;
    };
}

#endif