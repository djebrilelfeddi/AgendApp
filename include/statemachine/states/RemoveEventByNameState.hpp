#ifndef REMOVEEVENTBYNAMESTATE_HPP
#define REMOVEEVENTBYNAMESTATE_HPP

#include "RemoveEventState.hpp"

class RemoveEventByNameState : public RemoveEventState {
public:
    std::unique_ptr<BaseState> handle(StateMachine&) override;
};

#endif
