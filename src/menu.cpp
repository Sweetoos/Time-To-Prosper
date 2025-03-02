#include "menu.h"

#include <fstream>
#include <iostream>
#include <filesystem>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Menu
{
    bool runnable = true;

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
        try
        {
            std::string language;
            ReadDefaultSettings(language);
            std::ifstream menuFile("local/menu.json");
            std::ifstream configFile("save/config.json");
            if (!menuFile.is_open())
            {
                throw std::runtime_error("couldn't read menu.json file\t func: DisplayMenu");
            }
            json data;
            menuFile >> data;
            json config;
            configFile >> config;

            std::cout << data["menu"]["title"][language] << '\n';
            for (const auto &option : data["menu"]["options"])
            {
                std::cout << option["id"] << ". " << option["text"][language] << '\n';
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
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

            json config;
            config["language"] = "en";

            std::ofstream configFile(configFileName);
            if (configFile.is_open())
            {
                configFile << config.dump(4);
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

    void ReadDefaultSettings(std::string &language)
    {
        try
        {
            namespace fs = std::filesystem;
            if (!fs::exists("save/config.json"))
            {
                CreateDefaultSettings();
            }

            std::ifstream defaultSettingsFile("save/config.json");
            if (!defaultSettingsFile.is_open())
            {
                throw std::runtime_error("couldn't open config file\t func: ReadDefaultSettings");
            }

            json data;
            defaultSettingsFile >> data;
            defaultSettingsFile.close();

            if (data.contains("language"))
            {
                language = data["language"].get<std::string>();
            }
            else
            {
                throw std::runtime_error("invalid config file format\t func: ReadDefaultSettings");
            }
        }
        catch (const json::parse_error &e)
        {
            std::cerr << "JSON parsing error: " << e.what() << '\n';
            language = "en";
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            language = "en";
        }
    }
}