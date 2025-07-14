#include "app.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include "mainMenuState.h"

using json = nlohmann::json;
namespace fs=std::filesystem;

App::App()
{
    ReadDefaultSettings();
    
    // CreateWindow(height, width) or sth like that
}

void App::launch()
{
    stateMachine.addState(std::make_unique<MainMenuState>(this));
}

void App::CreateDefaultSettings()
{
    try
    {
        const std::string saveFolder = "save";
        if(!fs::exists(saveFolder))
            fs::create_directory(saveFolder);
        
        const std::string configFileName = "save/config.json";

        if (!fs::exists("save"))
        {
            if (!fs::create_directory(saveFolder))
                throw std::runtime_error(
                    "Couldn't create save folder\t func: "
                    "CreateDefaultSettings");
        }

        std::ofstream configFile(configFileName);
        if (configFile.is_open())
        {
            configFile << R"({
                "settings":{
                    "width": "1920",
                    "height": "1080",
                    "language": "en"
                }
            })";
            configFile.close();
        }
        else
        {
            throw std::runtime_error(
                "Couldn't create config file\t func: CreateDefaultSettings");
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return;
    }
}

void App::ReadDefaultSettings()
{
    CreateDefaultSettings();
    std::ifstream defaultSettingsFile("save/config.json");
    json data;
    defaultSettingsFile >> data;
    height=data["height"];
    width=data["width"];
    language=data["language"];
}
