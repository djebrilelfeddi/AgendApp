#include "statemachine/states/QuitState.hpp"
#include "statemachine/StateMachine.hpp"

std::unique_ptr<BaseState> QuitState::handle(StateMachine &) {
    //std::cout << "Exiting application. Goodbye!\n";
    return nullptr;
}
