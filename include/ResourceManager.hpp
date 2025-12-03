#ifndef RES_MANAGER_HPP
#define RES_MANAGER_HPP

#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

#include "./Agenda/Agenda.hpp"

#include <filesystem>
#include <optional>

namespace ResourceManager {
    struct Config {
        std::filesystem::path dataDirectory = "data";
        std::filesystem::path agendaDirectory = "agendas";
        std::filesystem::path htmlDirectory = "html";
        std::string dataExtension = ".dat";
    };

    bool exists(const std::filesystem::path& filePath);
    void exportHtml(const Config& config, const Agenda::Agenda& agenda);
    std::filesystem::path getAppDirectory();
    RETURNSTATUS writeFile(const std::filesystem::path& filePath, const std::string& content);
}

#endif      