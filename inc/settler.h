#pragma once

#include <string>

#include "unit.h"
#include "city.h"
#include "civilization.h"

namespace Unit
{
    class CSettler : public IUnit
    {
    private:
        int attack;
        int defense;
        int movement;

    public:
        CSettler(int attack, int defense, int movement);
        void CreateCity();
        void JoinCity(const City::ICity &city);
    };
}