#include "Agenda/Controller.hpp"

namespace Agenda 
{
    using Timestamp::Date;

    Controller::Controller() {
        config = ResourceManager::Config();
    };

    void Controller::loadAgenda(const std::string& agendaName) {
        
        std::filesystem::path filePath = ResourceManager::getAppDirectory() / config.agendaDirectory / (agendaName + config.dataExtension);

        if (!ResourceManager::exists(filePath)) {
            std::cout << "The agenda doesn't exist, let's create a new one!" << std::endl;

            std::string title, description;

            std::cout << "title> ";
            std::cin >> title;

            std::cout << "description> ";
            std::cin >> description;

            currentAgenda = Agenda(agendaName, title, description);
        } else {
            currentAgenda = parseAgenda(filePath.string());
        }
    }

    const ResourceManager::Config Controller::getConfig() const {
        return config;
    }

    auto extractField = [](const std::string& line, const std::string& str) { return line.substr(str.length()); };

    Agenda Controller::parseAgenda(const std::string& filename) {
        Propreties properties;
        Agenda agenda;

        std::ifstream file(filename);
        std::string line;

        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file: " + filename);
        }

        while (std::getline(file, line)) {
            if (line.empty()) continue;

            if      (line.find("name:") == 0)        properties.name = extractField(line, "name: ");
            else if (line.find("title:") == 0)       properties.title = extractField(line, "title: ");
            else if (line.find("description:") == 0) properties.description = Utils::MultiString(extractField(line, "description: "));
            else if (line.find("uid:") == 0) {
                auto event = std::make_shared<Events::Event>(parseEvent(file, line));
                agenda.getEvents().add(event);
            }
        }

        agenda = Agenda(properties.name, properties.title, properties.description.get());
        return agenda;
    }

    Events::Event Controller::parseEvent(std::ifstream& file, std::string& firstLine) 
    {
        if (!file.good()) throw std::runtime_error("File stream error while parsing event.");

        std::string uid = extractField(firstLine, "uid:");
        std::string title, description;
        Date begin, end;
        std::string line;

        while (std::getline(file, line) && !line.empty()) 
        {
            if      (line.find("title:") == 0)       title = extractField(line, "title: ");
            else if (line.find("description:") == 0) description = Utils::readMultilineStream(file, ":endDescription");
            else if (line.find("beginDate:") == 0)   begin = Date(extractField(line, "beginDate: ")); // "DD/MM/YY HH:MM"
            else if (line.find("endDate:") == 0)     end = Date(extractField(line, "endDate: "));
        }

        Events::Event e(uid, title, description);
        e.setDates(begin, end);
        return e;
    }

    RETURNSTATUS Controller::saveAgenda() {
        std::filesystem::path fileName = currentAgenda.getPropreties().name + config.dataExtension;
        std::filesystem::path filePath = ResourceManager::getAppDirectory() / config.agendaDirectory / fileName;
        std::string content = currentAgenda.toString();
        saved = true;
        return ResourceManager::writeFile(filePath, content);
    }


    void Controller::setProperties(const std::string& name, const std::string& title, const std::string& description) {
        Propreties currentPropreties = currentAgenda.getPropreties();

        currentAgenda = Agenda(
            (name.size() ? name : currentPropreties.name), 
            (title.size() ? title : currentPropreties.title),
            (description.size() ? description : currentPropreties.description.get())
        );

        saved = false;
    }

    RETURNSTATUS Controller::exportHtml() const {
        try {
            ResourceManager::exportHtml(config, currentAgenda);
            return RETURNSTATUS::OK;
        } catch (const std::exception& e) {
            std::cerr << "Error exporting HTML: " << e.what() << std::endl;
            return RETURNSTATUS::ERR;
        }
    }


    bool Controller::isSaved() const {
        return saved;
    }

    RETURNSTATUS Controller::display() const {
        return currentAgenda.display();
    }

    void Controller::addEvent(const std::shared_ptr<Events::Event>& event) {
        currentAgenda.getEvents().add(event);
        saved = false;
    }

    RETURNSTATUS Controller::removeEvent(const std::shared_ptr<Events::Event>& event) {
        currentAgenda.getEvents().remove(event);
        saved = false;
        return RETURNSTATUS::OK;
    }

    Events::EventsList& Controller::getEvents() {
        return currentAgenda.getEvents();
    }

    void Controller::displayAllEvents() 
    {
        auto &eventsList = getEvents();
        for (size_t i = 0; i < eventsList.count(); ++i) {
            auto eventOpt = eventsList.findByIndex(i);
            if (eventOpt.has_value()) {
                auto event = eventOpt.value();
                std::cout << "[ID: " << event->getID() << " | Title: " << event->getTitle() << "]" << "\n";
            }
        }
    }
}