#include "../include/Utils.hpp"

namespace Utils 
{
    std::string getUID(const std::size_t len) {
        constexpr char hex_chars[] = "0123456789abcdef";
        thread_local std::mt19937 gen(std::random_device{}());
        thread_local std::uniform_int_distribution<int> dis(0, 15);

        std::string uid;
        uid.reserve(len);

        for (std::size_t i = 0; i < len; ++i) {
            uid += hex_chars[dis(gen)];
        }

        return uid;
    }
    
    void getMultilineInput(std::string& var, const std::string& msg, const std::string& endStr) {
        std::cout << msg << "\n";
        var = Utils::readMultilineStream(std::cin, endStr);
    };
    
    void clearBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };

    void inputDateTime(Timestamp::Date& inputDate, const std::string& label) {
        std::string dateStr;
        std::string timeStr;

        while (true) 
        {
            try {
                getInput(dateStr, label + " (JJ/MM/AAAA)");
                getInput(timeStr, label + " (HH:MM)");

                inputDate = Timestamp::Date(dateStr);
                inputDate.setTime(Timestamp::Time(timeStr));
                break;
            } 
            catch (const std::invalid_argument& e) {
                std::cerr << "Error : " << e.what() << "\nPlease retry.\n";
            }
        }
        return;
    };

    void clear() {
    #ifdef _WIN32
        //obtenir le handle de la sortie
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) {
            std::cerr << "Erreur: Impossible d'obtenir le handle de la console." << std::endl;
            return;
        }

        //obtenir les modes de la console
        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode)) {
            std::cerr << "Erreur: Impossible d'obtenir le mode de la console." << std::endl;
            return;
        }

        //activer le traitement des sequences d'echappement ANSI
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        if (!SetConsoleMode(hOut, dwMode)) {
            std::cerr << "Erreur: Impossible d'activer le mode de sequence d'echappement ANSI." << std::endl;
            return;
        }
    #endif

        //effacer l'écran en utilisant les sequences d'echappement ANSI
        std::cout << "\033[2J\033[1;1H" << std::flush;
    }

    void waitForKeyPress() {   
        std::cout << "Press any key to continue.."  << std::endl; 
        clearBuffer();
       // std::cin.get();
    }
}
