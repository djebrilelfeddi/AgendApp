#include "statemachine/states/MainMenuState.hpp"

void MainMenuState::enter(StateMachine&) {
    menuName = "Main Menu";
    menuBase = std::make_unique<MainMenuState>();
    StateFactory = {
        { "Edit Agenda", [](){ return std::make_unique<EditAgendaState>(); } },
        { "Show Agenda", [](){ return std::make_unique<ShowAgendaState>(); } },
        { "Add Event",   [](){ return std::make_unique<AddEventState>(); } },
        { "Remove Event",[](){ return std::make_unique<RemoveEventMenuState>(); } },
        { "Export HTML", [](){ return std::make_unique<ExportHTMLState>(); } },
        { "Save Agenda", [](){ return std::make_unique<SaveAgendaState>(); } },
        { "Quit",        [](){ return std::make_unique<ConfirmQuitState>(); } }
    };
}