#pragma once
#include <string>
#include <vector>

namespace Menu
{
    struct MenuOption
    {
        int id;
        std::string text;
        // Add any additional fields you need for menu options
    };

    extern bool runnable;
    /// @brief function responsible for creating config.json file if it doesn't exist
    void CreateDefaultSettings();
    void ReadDefaultSettings(std::string &language);
    void Run();

    /// @brief function responsible for displaying menu options
    void DisplayMenu(); // Removed template
}
