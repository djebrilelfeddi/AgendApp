#include "statemachine/states/EditAgendaState.hpp"
#include "statemachine/StateMachine.hpp"
#include "statemachine/states/MainMenuState.hpp"
#include "Agenda/Controller.hpp"

std::unique_ptr<BaseState> EditAgendaState::handle(StateMachine &machine) {
    auto controller = machine.getAgendaController();

    std::string title, description, endStr=".";

    Utils::getInput(title, "Agenda title");
    Utils::getMultilineInput(description, "Description (Write a line with only '.' to end) :", endStr);
    controller->setProperties("", title, description);
    machine.setTransitionMessage("Agenda updated.");
    return std::make_unique<MainMenuState>();
}