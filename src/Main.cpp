
#include "statemachine/StateMachine.hpp"
#include "agenda/Agenda.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <agenda_filename>\n";
        return 1;
    }

    StateMachine machine;

    Utils::clear();
    machine.getAgendaController()->loadAgenda(argv[1]);
    Utils::clear();
    machine.run();
    return 0;
}
