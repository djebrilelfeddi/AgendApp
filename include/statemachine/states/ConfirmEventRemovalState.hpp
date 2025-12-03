#ifndef CONFIRMEVENTREMOVAL_HPP
#define CONFIRMEVENTREMOVAL_HPP

#include "Events/Event.hpp"
#include "../BaseState.hpp"
#include <memory>

class ConfirmEventRemovalState : public BaseState {
public:
    ConfirmEventRemovalState(std::shared_ptr<Events::Event> event);
    std::unique_ptr<BaseState> handle(StateMachine&) override;
private:
    std::shared_ptr<Events::Event> eventToRemove = nullptr;
};

#endif
