#include "foodModifier.h"

namespace Modifiers
{
    double CModifierFood::Apply(double baseValue) const
    {
        return baseValue + bonus;
    }
    std::string CModifierFood::GetName() const
    {
        return name;
    }
}