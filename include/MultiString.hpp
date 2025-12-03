    
#ifndef MULTISTRING_HPP
#define MULTISTRING_HPP

#include <string>

namespace Utils 
{
    class MultiString
    {
    public:
        //Constructeurs
        MultiString() = default;
        explicit MultiString(const std::string& copy);

        //Méthodes publiques
        std::string toHtml() const;
        std::string get()    const;

    private:
        std::string value;
    };
}

#endif