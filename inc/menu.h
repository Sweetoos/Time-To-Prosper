#pragma once

namespace Menu
{
    bool runnable=true;
    /// @brief function responsible for creating config.json file if it doesn't exist
    void CreateDefaultSettings();
    void ReadDefaultSettings();
    void Run();
    void DisplayMenu();
}
