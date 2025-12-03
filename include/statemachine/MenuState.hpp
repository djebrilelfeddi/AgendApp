#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <memory>
#include <iostream>
#include <string>
#include <functional>
#include "StateMachine.hpp"

class MenuState : public BaseState {
public:
    virtual void enter(StateMachine&) override;
    virtual std::unique_ptr<BaseState> handle(StateMachine &machine) override;
protected:
    std::string menuName;
    std::unique_ptr<BaseState> menuBase = nullptr;
    std::vector<std::pair<std::string, std::function<std::unique_ptr<BaseState>()>>> StateFactory;
};

#endif
