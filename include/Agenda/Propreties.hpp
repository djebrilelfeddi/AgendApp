#ifndef AGENDAPROPS_HPP
#define AGENDAPROPS_HPP

#include <string>
#include "Utils.hpp"

namespace Agenda 
{
    struct Propreties {
        std::string name;
        std::string title;
        Utils::MultiString description;
    };
}

#endif
