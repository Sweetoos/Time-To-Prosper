#pragma once
#include <string>

namespace Menu
{
    extern bool runnable;
    /// @brief function responsible for creating config.json file if it doesn't exist
    void CreateDefaultSettings();
    void ReadDefaultSettings(std::string &language);
    void Run();
    void DisplayMenu();
}
