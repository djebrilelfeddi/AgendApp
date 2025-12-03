#include "RemoveEventState.hpp"
#include "statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "MainMenuState.hpp"
#include "Utils.hpp"
#include <iostream>

void RemoveEventState::enter(StateMachine &machine) {
    machine.getAgendaController()->displayAllEvents();
}

std::vector<std::shared_ptr<Events::Event>> RemoveEventState::findInputEvents(
    const std::string& message,
    std::function<std::vector<std::shared_ptr<Events::Event>>(const std::string&)> findFunc
) {
    std::vector<std::shared_ptr<Events::Event>> foundEvents;
    std::string eventStr;

    while (true) {
        Utils::getInput(eventStr, message);
        if (eventStr == "cancel") break;

        foundEvents = findFunc(eventStr);
        if (!foundEvents.empty()) {
            break;
        }
        std::cerr << "No corresponding event found. Try again.\n";
    }

    return foundEvents;
}