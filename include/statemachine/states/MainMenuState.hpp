#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include <memory>
#include <iostream>
#include <string>
#include <functional>
#include "../MenuState.hpp"
#include "../StateMachine.hpp"
#include "EditAgendaState.hpp"
#include "ShowAgendaState.hpp"
#include "AddEventState.hpp"
#include "RemoveEventMenuState.hpp"
#include "ExportHTMLState.hpp"
#include "SaveAgendaState.hpp"
#include "ConfirmQuitState.hpp"
#include "Agenda/Controller.hpp"

class MainMenuState : public MenuState {
public:
    void enter(StateMachine &machine) override;
};

#endif
