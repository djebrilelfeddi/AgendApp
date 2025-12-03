#include "ConfirmEventRemovalState.hpp"
#include "statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "MainMenuState.hpp"
#include "Utils.hpp"
#include <iostream>

ConfirmEventRemovalState::ConfirmEventRemovalState(std::shared_ptr<Events::Event> event) {
    eventToRemove = std::move(event);
}
std::unique_ptr<BaseState> ConfirmEventRemovalState::handle(StateMachine &machine) {
    char confirm = '\0';
    std::cout << "Are you sure you want to remove \"" << eventToRemove->getTitle() << "\" (" << eventToRemove->getID() << ")? (Y/N): ";
    std::cin >> confirm;

    if (confirm == 'Y' || confirm == 'y') {
        machine.getAgendaController()->removeEvent(eventToRemove);
        machine.setTransitionMessage("Event '" + eventToRemove->getTitle() + "' (" + eventToRemove->getID() + ") removed");
    } else {
        machine.setTransitionMessage("Removal cancelled.");
        return std::make_unique<RemoveEventMenuState>();
    }

    return std::make_unique<MainMenuState>();
}