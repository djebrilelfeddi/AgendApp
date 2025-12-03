#include "statemachine/states/SaveAgendaState.hpp"
#include "statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "statemachine/states/MainMenuState.hpp"
#include <format>

std::unique_ptr<BaseState> SaveAgendaState::handle(StateMachine &machine) {
    auto controller = machine.getAgendaController();

    RETURNSTATUS code = controller->saveAgenda();

    if (code == RETURNSTATUS::OK) {
        machine.setTransitionMessage("Agenda saved.");
    } else {
        machine.setTransitionMessage("An error occured while trying to save the agenda.");
    }

    return std::make_unique<MainMenuState>();
}