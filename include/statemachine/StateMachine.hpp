#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <memory>
#include <random>
#include <string>
#include <iostream>
#include "BaseState.hpp"

#include "Agenda/Controller.hpp"

using AgendaManager = Agenda::Controller;

class StateMachine {
public:
    StateMachine();
    void run();

    std::shared_ptr<AgendaManager> getAgendaController();
    std::string generateUID(size_t len);
    void setTransitionMessage(const std::string &message);
    const std::string &getTransitionMessage() const;

private:
    std::shared_ptr<AgendaManager> agenda;
    std::unique_ptr<BaseState> currentState;
    std::string transitionMessage;

    void displayTransitionMessage();
};

#endif
