#ifndef ISTRINGCONVERTIBLE_HPP
#define ISTRINGCONVERTIBLE_HPP

#include <string>
#include <ostream>

class IStringConvertible
{
public:
    virtual ~IStringConvertible()  noexcept = default;
    virtual std::string toString() const = 0;
};

#endif