#ifndef AGENDA_CONTROLLER_HPP
#define AGENDA_CONTROLLER_HPP

#include "Agenda.hpp"
#include "./Events/Event.hpp"
#include "./Timestamp/Date.hpp"
#include "ResourceManager.hpp"
#include "ReturnStatus.hpp"
#include "../interfaces/IHtmlConvertible.hpp"

namespace Agenda 
{
    class Controller final
    {
    public:
        //Constructeur et Destructeur
        Controller();
        ~Controller() noexcept = default;

        //Getters et Setters
        const ResourceManager::Config getConfig() const;
        bool isSaved() const;
        Events::EventsList& getEvents();
        void setProperties(const std::string& name, const std::string& title, const std::string& description);

        //Méthodes Autres
        void loadAgenda(const std::string& agendaName);
        void addEvent(const std::shared_ptr<Events::Event>& event);
        void displayAllEvents();
        RETURNSTATUS saveAgenda();
        RETURNSTATUS exportHtml() const;
        RETURNSTATUS display() const;
        RETURNSTATUS removeEvent(const std::shared_ptr<Events::Event>& event);

    private:
        Agenda currentAgenda;
        ResourceManager::Config config;
        bool saved = true;

        //Méthodes privées
        Agenda parseAgenda(const std::string& filename);
        Events::Event parseEvent(std::ifstream& file, std::string& firstLine);
    };
}

#endif
