#pragma once
#include <string>
#include <memory>

#include "civPerk.h"

namespace Civilization
{
    class ICivilization
    {
    protected:
        virtual std::string GetName() const = 0;
        virtual CivPerk GetCivPerk() const = 0;
    };
}