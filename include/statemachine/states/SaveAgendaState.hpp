#ifndef SAVEAGENDASTATE_HPP
#define SAVEAGENDASTATE_HPP

#include "../BaseState.hpp"
#include <memory>
#include <fstream>
#include <format>

class SaveAgendaState : public BaseState {
public:
    std::unique_ptr<BaseState> handle(StateMachine&) override;
};

#endif
