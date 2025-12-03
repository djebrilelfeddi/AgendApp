#ifndef REMOVEEVENTMENUSTATE_HPP
#define REMOVEEVENTMENUSTATE_HPP

#include "../MenuState.hpp"
#include <memory>

class RemoveEventMenuState : public MenuState {
public:
    void enter(StateMachine&) override;
    std::unique_ptr<BaseState> handle(StateMachine &machine) override;
};

#endif
