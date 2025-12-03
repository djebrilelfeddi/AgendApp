#include "Agenda/Agenda.hpp"

namespace Agenda 
{
    Agenda::Agenda(const std::string &n, const std::string &t, const std::string &d) {
        propreties.name = n;
        propreties.title = t;
        propreties.description = Utils::MultiString(d);
    }

    RETURNSTATUS Agenda::display() const {
        std::cout << "== Agenda Properties ==" << std::endl
                  << "Name: " << propreties.name << std::endl
                  << "Title: " << propreties.title << std::endl
                  << "Description: " << propreties.description.get() << std::endl << std::endl
                  << " == Events ==" << std::endl
                  << events.toString()
                  << std::endl;

        return RETURNSTATUS::OK_DISPLAY;
    }

    Propreties Agenda::getPropreties() const {
        return propreties;
    }

    Events::EventsList& Agenda::getEvents() {
        return events;
    }

    std::string Agenda::toString() const {
        return std::format(
            "name: {}\n"
            "title: {}\n"
            "description: {}\n:endDescription\n"
            "{}\n", propreties.name, propreties.title, propreties.description.get(), events.toString()
        );
    }

    std::string Agenda::toHtml() const 
    {
        try 
        {
            std::string eventsContent;
            if (events.count() <= 0) {
                eventsContent = "<h2>No events in agenda</h2></body></html>";
            } else {
                eventsContent = std::format("<h2>Events</h2>{}</body></html>", events.toHtml());
            }

            return std::format(R"(<!DOCTYPE html>
                <html>
                <head>
                <title>{}</title>
                <style>
                .event-block {{
                    border: 1px solid #000;
                    margin: 10px 0;
                    padding: 10px;
                    border-radius: 5px;
                    background-color: #f9f9f9;
                }}
                </style>
                </head>
                <body>
                <h2>Propreties</h2>
                <p><strong>Title:</strong> {}</p>
                <p><strong>Description:</strong> {}</p>
                {})",
                propreties.name,
                propreties.title,
                propreties.description.toHtml(),
                eventsContent);
        }
        catch (const std::format_error& e) {
            return "Error generating HTML content.";
        }
    }
}