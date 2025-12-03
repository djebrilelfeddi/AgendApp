#ifndef REMOVEEVENTBASESTATE_HPP
#define REMOVEEVENTBASESTATE_HPP

#include "../BaseState.hpp"
#include <memory>
#include <functional>
#include "Events/Event.hpp"
#include "Events/EventsList.hpp"

class RemoveEventState : public BaseState {
public:
    virtual void enter(StateMachine &machine) override;
protected:
    void displayEvents(StateMachine &machine) const ;
    std::vector<std::shared_ptr<Events::Event>> inputRemoval(Events::EventsList& eventsList, const std::string& message);
    std::vector<std::shared_ptr<Events::Event>> findInputEvents(
        const std::string& message,
        std::function<std::vector<std::shared_ptr<Events::Event>>(const std::string&)> findFunc
    );
};

#endif
