#include "statemachine/MenuState.hpp"

void MenuState::enter(StateMachine&) {
    menuName = "BaseMenu";
    menuBase = nullptr;
    StateFactory = {
        { "Main menu", [](){ return nullptr; } }
    };
}

std::unique_ptr<BaseState> MenuState::handle(StateMachine &machine) {
    auto agenda = machine.getAgendaController();

    std::cout << "=== "<<menuName<<" ===\n";

    for (size_t i = 0; i < StateFactory.size(); ++i) {
        std::cout << "[" << i+1 << "] " << StateFactory[i].first << '\n';
    }

    size_t choice;

    bool ok=false;
    
    while (!ok){
        Utils::getInput(choice, "");
        if (choice > 0 && choice <= StateFactory.size()) {
           ok=true;
        } 
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }
    return StateFactory[choice - 1].second();
}
