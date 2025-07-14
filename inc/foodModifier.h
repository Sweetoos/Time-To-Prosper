#pragma once

#include "modifiers.h"

namespace Modifiers
{
    class CModifierFood : public IModifier
    {
    private:
        float value;
        const std::string name = "food";
        float bonus;

    public:
        double Apply(double baseValue) const override;
        std::string GetName() const override;
    };
}
