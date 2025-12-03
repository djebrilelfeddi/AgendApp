#ifndef CONFIRMQUITSTATE_HPP
#define CONFIRMQUITSTATE_HPP

#include "../BaseState.hpp"
#include <memory>

class ConfirmQuitState final : public BaseState {
public:
    std::unique_ptr<BaseState> handle(StateMachine&) override;
};

#endif
