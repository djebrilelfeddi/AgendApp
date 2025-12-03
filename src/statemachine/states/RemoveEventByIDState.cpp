#include "RemoveEventByIDState.hpp"
#include "statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "MainMenuState.hpp"
#include "Utils.hpp"
#include "ConfirmEventRemovalState.hpp"
#include <iostream>

std::unique_ptr<BaseState> RemoveEventByIDState::handle(StateMachine &machine) {
    auto controller = machine.getAgendaController();
    auto &eventsList = controller->getEvents();
    
    std::vector<std::shared_ptr<Events::Event>> foundEvents = findInputEvents(
        "Enter the event ID to remove (or 'cancel' to cancel)\n",
        [&](const std::string& input) -> std::vector<std::shared_ptr<Events::Event>> {
            return eventsList.findByID(input);
        }
    );

    if (foundEvents.empty()) {
        return std::make_unique<RemoveEventMenuState>();
    }

    return std::make_unique<ConfirmEventRemovalState>(foundEvents[0]);
}