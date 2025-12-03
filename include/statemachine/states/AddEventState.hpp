#ifndef ADDEVENTSTATE_HPP
#define ADDEVENTSTATE_HPP

#include "../BaseState.hpp"
#include <memory>
#include "Events/Event.hpp"

class AddEventState final : public BaseState {
public:
    std::unique_ptr<BaseState> handle(StateMachine&) override;
private:
    bool validateTitle(const std::string& title, StateMachine& machine);
    bool confirmEventDetails(const Events::Event& event);
    std::string generateUniqueEventID();
    std::shared_ptr<Events::Event> createEvent(StateMachine& machine);
};

#endif
