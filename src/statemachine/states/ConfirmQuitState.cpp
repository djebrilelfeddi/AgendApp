#include "statemachine/states/ConfirmQuitState.hpp"
#include "statemachine/states/QuitState.hpp"
#include "statemachine/states/MainMenuState.hpp"
#include "statemachine/StateMachine.hpp"

std::unique_ptr<BaseState> ConfirmQuitState::handle(StateMachine& machine) {
    auto currentController = machine.getAgendaController();
    
    if (!currentController->isSaved()) {
        std::cout << "Be careful! You did not save the calendar." << std::endl;

        std::string input;
        while (true) {
            std::cout << "Save it? (Y for yes / N for no / C to cancel): ";
            std::cin >> input;

            if (input == "y" || input == "Y") {
                try {
                    currentController->saveAgenda();
                    machine.setTransitionMessage("Saved successfully.");
                    break;
                } catch (const std::exception& e) {
                    std::cout << "An error occurred trying to save the agenda: " << e.what() << std::endl;
                }
            } else if (input == "n" || input == "N") {
                break;
            } else if (input == "c" || input == "C") {  
                machine.setTransitionMessage("Returning to Main Menu.");
                return std::make_unique<MainMenuState>();
            } else {
                std::cout << "Invalid input. Please enter Y, N, or C." << std::endl;
            }
        }
    }

    return std::make_unique<QuitState>();
}
