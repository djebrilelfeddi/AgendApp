#ifndef REMOVEEVENTBYIDSTATE_HPP
#define REMOVEEVENTBYIDSTATE_HPP

#include "RemoveEventState.hpp"

class RemoveEventByIDState final : public RemoveEventState {
public:
    std::unique_ptr<BaseState> handle(StateMachine&) override;
};

#endif
