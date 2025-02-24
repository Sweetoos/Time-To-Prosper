#include "menu.h"

#include <fstream>
#include <iostream>
#include <filesystem>

#include <lib/json/include/nlohmann/json.hpp>

using json = nlohmann::json;

namespace Menu
{
    void Run()
    {
        try
        {
            std::ifstream menuFile("local/menu.json");
            if (!menuFile.is_open())
            {
                throw std::runtime_error("couldn't read menu.json file\t func: Run");
            }
            json data;
            menuFile >> data;

            std::string language = "en";
            std::cout << data["menu"]["title"][language];

            while (runnable)
            {
                DisplayMenu();
            }
        }
        catch (std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            return;
        }
    }

    void DisplayMenu()
    {
    }
    void CreateDefaultSettings()
    {
        try
        {
            namespace fs = std::filesystem;
            const std::string saveFolder = "save";
            const std::string configFileName = "save/config.json";
            if (!fs::exists("save"))
            {
                if (!fs::create_directory(saveFolder))
                    throw std::runtime_error("couldn't create save folder\t func: CreateDefaultSettings");
            }
            std::ofstream configFile(configFileName);
            if (configFile.is_open())
            {
                configFile << R"({
                    "language": "en"
                })";
                configFile.close();
            }
            else
            {
                throw std::runtime_error("couldn't create config file\t func: CreateDefaultSettings");
            }
        }
        catch (std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            return;
        }
    }
    void ReadDefaultSettings()
    {
        CreateDefaultSettings();
        std::ifstream defaultSettingsFile("save/config.json");
        json data;
        defaultSettingsFile>>data;
        ///TODO: finish this function
    }
}