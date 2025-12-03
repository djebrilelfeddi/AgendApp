#include "../include/statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "../include/statemachine/states/MainMenuState.hpp"

StateMachine::StateMachine() : agenda(std::make_shared<AgendaManager>()), currentState(std::make_unique<MainMenuState>()) 
{
    currentState->enter(*this);
}

void StateMachine::displayTransitionMessage() {
    if (!transitionMessage.empty()) {
        std::cout << transitionMessage << "\n";
        transitionMessage.clear();
    }
}

void StateMachine::run() {
    while (currentState) {
        std::unique_ptr<BaseState> nextState = currentState->handle(*this);

        currentState->exit(*this);

        displayTransitionMessage();

        if (nextState) {
            currentState = std::move(nextState);
            currentState->enter(*this);
        } else {
            currentState.reset();
        }
    }
}

std::shared_ptr<AgendaManager> StateMachine::getAgendaController() {
    return agenda;
}

void StateMachine::setTransitionMessage(const std::string &message) {
    transitionMessage = message;
}

const std::string &StateMachine::getTransitionMessage() const {
    return transitionMessage;
}