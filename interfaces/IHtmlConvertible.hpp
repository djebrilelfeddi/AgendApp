#ifndef IHTMLCONVERTIBLE_HPP
#define IHTMLCONVERTIBLE_HPP

#include "IStringConvertible.hpp"

class IHtmlConvertible : public IStringConvertible
{
public:
    virtual ~IHtmlConvertible()  noexcept = default;
    virtual std::string toHtml() const = 0;
};

#endif