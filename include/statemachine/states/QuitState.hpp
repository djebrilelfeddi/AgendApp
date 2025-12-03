#ifndef QUITSTATE_HPP
#define QUITSTATE_HPP

#include "../BaseState.hpp"
#include <memory>

class QuitState : public BaseState {
public:
    std::unique_ptr<BaseState> handle(StateMachine&) override;
};

#endif
