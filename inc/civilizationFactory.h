#pragma once

#include "civilization.h"
namespace Civilization
{
    class CivilizationFactory
    {
        static std::unique_ptr<ICivilization> CreateCivilization(const int &civilizationId);
    };
}