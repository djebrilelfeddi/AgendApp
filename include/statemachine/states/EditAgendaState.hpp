#ifndef EDITAGENDASTATE_HPP
#define EDITAGENDASTATE_HPP

#include "../BaseState.hpp"
#include <memory>

class EditAgendaState final : public BaseState {
public:
    std::unique_ptr<BaseState> handle(StateMachine&) override;
};

#endif
