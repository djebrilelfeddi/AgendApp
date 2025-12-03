#include "statemachine/states/ExportHTMLState.hpp"
#include "statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "statemachine/states/MainMenuState.hpp"

std::unique_ptr<BaseState> ExportHTMLState::handle(StateMachine &machine) {
    auto agenda = machine.getAgendaController();

    RETURNSTATUS code = agenda->exportHtml();
    if (code == RETURNSTATUS::OK) {
        machine.setTransitionMessage("Agenda successfully exported to HTML");
    } else {
        machine.setTransitionMessage("An error occured while trying to export the agenda.");
    }
    return std::make_unique<MainMenuState>();
}