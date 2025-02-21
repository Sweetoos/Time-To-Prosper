#pragma once
#include <string>

#include "civilization.h"

namespace Unit
{
    class IUnit
    {
    protected:
        virtual Civilization::ICivilization GetCivilization() const = 0;
        virtual std::string GetName() const = 0;
        virtual int GetAttack() const = 0;
        virtual int GetDefense() const = 0;
        virtual int GetMovement() const = 0;
        virtual bool IsBattleUnit() const = 0;
    };
}