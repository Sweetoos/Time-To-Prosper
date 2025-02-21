#pragma once

#include <string>

namespace Modifiers
{
    class IModifier
    {
    protected:
        virtual std::string GetName() const = 0;
        virtual double Apply(double baseValue) const = 0;
        virtual ~IModifier() = default;
    };
}