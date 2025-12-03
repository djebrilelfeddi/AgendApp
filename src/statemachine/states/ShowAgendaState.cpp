#include "statemachine/states/ShowAgendaState.hpp"
#include "statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "statemachine/states/MainMenuState.hpp"

std::unique_ptr<BaseState> ShowAgendaState::handle(StateMachine &machine) {
    auto controller = machine.getAgendaController();
    controller->display();
    Utils::waitForKeyPress();
    return std::make_unique<MainMenuState>();
}
