#ifndef BASESTATE_HPP
#define BASESTATE_HPP

#include <memory>
#include "Utils.hpp"

class StateMachine;

class BaseState {
public:
    virtual ~BaseState() = default;

    virtual void enter(StateMachine&) {};
    virtual void exit(StateMachine&) { Utils::clear();};
    virtual std::unique_ptr<BaseState> handle(StateMachine&) { return nullptr; };
};

#endif
