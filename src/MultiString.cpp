#include "MultiString.hpp"

namespace Utils 
{ 
    MultiString::MultiString(const std::string& copy) {
        value = copy;
    }

    std::string MultiString::toHtml() const 
    {
        std::string formattedDescription;
        
        for (const char c : value) 
        {
            if (c == '\n') {
                formattedDescription += "<br>";
            } 
            else {
                formattedDescription += c;
            }
        }
        return formattedDescription;
    }

    std::string MultiString::get() const {
        return value;
    }
}