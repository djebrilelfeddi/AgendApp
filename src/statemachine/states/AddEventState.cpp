#include "statemachine/states/AddEventState.hpp"
#include "statemachine/StateMachine.hpp"
#include "Agenda/Controller.hpp"
#include "statemachine/states/MainMenuState.hpp"
#include "Events/Event.hpp"
#include "timestamp/Date.hpp"

std::unique_ptr<BaseState> AddEventState::handle(StateMachine &machine) {
    auto currentController = machine.getAgendaController();

    std::shared_ptr<Events::Event> finalEvent = createEvent(machine);

    if (!finalEvent) {
        return std::make_unique<AddEventState>();
    }

    currentController->addEvent(finalEvent);
    machine.setTransitionMessage("Event '" + finalEvent->getTitle() + "' added");
    return std::make_unique<MainMenuState>();
}

std::string AddEventState::generateUniqueEventID() {
    return Utils::getUID(15);
}

bool AddEventState::validateTitle(const std::string& title, StateMachine& machine) {
    if (title == "cancel") {
        machine.setTransitionMessage("The event title cannot be 'cancel'.");
        return false;
    }
    return true;
}

std::shared_ptr<Events::Event> AddEventState::createEvent(StateMachine& machine) {
    std::string title, description, endStr = ".";
    Timestamp::Date startDate, endDate;

    while (true) {
        Utils::getInput(title, "Event title");
        if (!validateTitle(title, machine)) {
            return nullptr;
        }

        Utils::getMultilineInput(description, "Description (Write a line with only '.' to end):", endStr);
        Utils::inputDateTime(startDate, "Begin date");
        Utils::inputDateTime(endDate, "End date");

        auto event = std::make_shared<Events::Event>(generateUniqueEventID(), title, description);
        event->setDates(startDate, endDate);

        if (confirmEventDetails(*event)) {
            return event;
        }
        Utils::clear();
    }
}

bool AddEventState::confirmEventDetails(const Events::Event& event) {
    Utils::clear();
    std::string output = std::format(
        "Please confirm the event details:\n"
        "\nID: {}\n"
        "Title: {}\n"
        "Description: {}\n"
        "Begin date and hour: {}\n"
        "End date and hour: {}\n"
        "\nIs this correct? (Y for yes, N for no): ",
        event.getID(), event.getTitle(), event.getDescription().get(),
        event.getBeginDate().toString(), event.getEndDate().toString()
    );

    std::cout << output;
    char confirmation;
    std::cin >> confirmation;
    Utils::clearBuffer();

    return confirmation == 'Y' || confirmation == 'y';
}