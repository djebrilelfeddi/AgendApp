#ifndef SHOWAGENDASTATE_HPP
#define SHOWAGENDASTATE_HPP

#include "../BaseState.hpp"
#include <memory>

class ShowAgendaState : public BaseState {
public:
    std::unique_ptr<BaseState> handle(StateMachine&) override;
};

#endif
