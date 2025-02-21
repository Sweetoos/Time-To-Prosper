#pragma once
#include <string>

#include "civilization.h"
namespace City
{
    class ICity
    {
    protected:
        virtual std::string GetName() const = 0;
        virtual Civilization::ICivilization GetCivilization() const = 0;
    };
}