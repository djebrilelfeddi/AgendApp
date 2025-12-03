#include "ResourceManager.hpp"

namespace ResourceManager {
    bool exists(const std::filesystem::path& filePath) {
        try {
            return std::filesystem::exists(filePath);
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error checking existence: " << e.what() << std::endl;
            return false;
        }
    }

    RETURNSTATUS checkDirectory(const std::filesystem::path& dirPath) {
        try {
            if (!std::filesystem::exists(dirPath)) {
                std::filesystem::create_directories(dirPath);
            }
            return RETURNSTATUS::OK;
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error creating directory: " << e.what() << std::endl;
            return RETURNSTATUS::ERR;
        }
    }

    RETURNSTATUS writeFile(const std::filesystem::path& filePath, const std::string& content) {
        try {
            auto parentDir = filePath.parent_path();
            if (!parentDir.empty()) {
                checkDirectory(parentDir);
            }

            std::ofstream file(filePath);
            if (!file.is_open()) {
                std::cerr << "Unable to open file: " << filePath << std::endl;
                return RETURNSTATUS::ERR;
            }

            file << content;
            file.close();
            return RETURNSTATUS::OK;

        } catch (const std::exception& e) {
            std::cerr << "Error writing to file: " << e.what() << std::endl;
            return RETURNSTATUS::ERR;
        }
    }

    void exportHtml(const Config& config, const Agenda::Agenda& agenda) {
        try {
            const Agenda::Propreties agendaPropreties = agenda.getPropreties();
            const std::filesystem::path htmlFilePath = getAppDirectory() / config.htmlDirectory / (agendaPropreties.name + ".html");

            std::string content;

            content += "<html><body>\n";
            content += "<h1>" + agendaPropreties.name + "</h1>\n";
            content += agenda.toHtml();
            content += "</body></html>\n";

            writeFile(htmlFilePath, content);
        } 
        catch (const std::exception& e) {
            std::cerr << "Error exporting agenda to HTML: " << e.what() << std::endl;
        }
    }

    std::filesystem::path getAppDirectory() {
        std::filesystem::path dataPath;

    #ifdef _WIN32
        const char* appData = std::getenv("APPDATA");
        if (!appData) {
            throw std::runtime_error("APPDATA environment variable is not set.");
        }
        dataPath = appData;
    #else
        const char* home = std::getenv("HOME");
        if (!home) {
            throw std::runtime_error("HOME environment variable is not set.");
        }
        dataPath = home;
    #endif

        dataPath /= "AgendaApp";
        std::filesystem::create_directories(dataPath);

        return dataPath;
    }

}
