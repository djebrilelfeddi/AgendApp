#include "RemoveEventByNameState.hpp"
#include "RemoveEventByIDState.hpp"
#include "statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "MainMenuState.hpp"
#include "ConfirmEventRemovalState.hpp"
#include "Utils.hpp"
#include <iostream>

std::unique_ptr<BaseState> RemoveEventByNameState::handle(StateMachine &machine) {
    auto controller = machine.getAgendaController();
    auto& eventsList = controller->getEvents();
    std::string bob;

    std::vector<std::shared_ptr<Events::Event>> foundEvents = findInputEvents(
        "Enter the event title to remove (or 'cancel' to cancel)\n",
        [&](const std::string& input) -> std::vector<std::shared_ptr<Events::Event>> {
            return eventsList.findByTitle(input);
        }
    );

    if (foundEvents.empty()) {
        return std::make_unique<RemoveEventMenuState>();
    }
    else if (foundEvents.size() > 1) {
        std::string eventID;
        std::vector<std::shared_ptr<Events::Event>> singleEvent;
        machine.setTransitionMessage("Multiple events found with this title");
        return std::make_unique<RemoveEventByIDState>();
    }

    return std::make_unique<ConfirmEventRemovalState>(foundEvents[0]);
}
