#include "RemoveEventMenuState.hpp"
#include "statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "MainMenuState.hpp"
#include "RemoveEventByNameState.hpp"
#include "RemoveEventByIDState.hpp"
#include <iostream>

void RemoveEventMenuState::enter(StateMachine&) {
    menuName = "Remove Event Menu";
    menuBase = std::make_unique<MainMenuState>();
    StateFactory = {
        { "Remove by Title", [](){ return std::make_unique<RemoveEventByNameState>(); } },
        { "Remove by ID",   [](){ return std::make_unique<RemoveEventByIDState>(); } },
        { "Cancel",         [](){ return std::make_unique<MainMenuState>(); } }
    };
}

std::unique_ptr<BaseState> RemoveEventMenuState::handle(StateMachine &machine) {
    auto controller = machine.getAgendaController();

    if (controller->getEvents().count() == 0) {
        machine.setTransitionMessage("No events found. Returning to the main menu.");
        return std::make_unique<MainMenuState>();
    }

    std::cout << "=== Events ===\n";

    controller->displayAllEvents();

    std::cout << "\n=== "<<menuName<<" ===\n";

    for (size_t i = 0; i < StateFactory.size(); ++i) {
        std::cout << "[" << i+1 << "] " << StateFactory[i].first << '\n';
    }

    size_t choice;

    bool ok=false;
    
    while (!ok){
        Utils::getInput(choice, "");
        if (choice > 0 && choice <= StateFactory.size()) {
           ok=true;
        } 
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }
    return StateFactory[choice - 1].second();
}

