#ifndef AGENDA_HPP
#define AGENDA_HPP

#include "./Events/EventsList.hpp"
#include "Propreties.hpp"
#include "ReturnStatus.hpp"
#include "../interfaces/IHtmlConvertible.hpp"

namespace Agenda 
{
    class Agenda final : public IHtmlConvertible
    {
    public:
        //Constructeur et Destructeur
        Agenda(const std::string& name = "", const std::string& type = "", const std::string& description = "");
        ~Agenda() noexcept override = default;

        //Getters
        Events::EventsList& getEvents();
        Propreties getPropreties() const;

        //Méthodes virtuelles override
        std::string toString() const override;
        std::string toHtml()   const override;

        //Méthodes Autre
        RETURNSTATUS display() const;

    private:
        Propreties propreties;
        Events::EventsList events;
    };
}

#endif

//INVERSION DE DEPENDANCES
//INJECTION DE DEPENDANCES
//DESIGN PATTERNS