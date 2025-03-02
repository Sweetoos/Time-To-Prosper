#include "menu.h"

#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>

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
            if (!menuFile.is_open())
            {
                throw std::runtime_error("couldn't read menu.json file\t func: DisplayMenu");
            }
            json data;
            menuFile >> data;
            std::vector<MenuOption> options;

            for (const auto &option : data["menu"]["mainMenuOptions"])
            {
                MenuOption menuOption{
                    option["id"].get<int>(),
                    option["text"][language].get<std::string>()};
                options.push_back(menuOption);
            }

            std::cout << data["menu"]["title"][language].get<std::string>() << '\n';
            for (const auto &option : options)
            {
                std::cout << option.id << ". " << option.text << '\n';
            }
            std::cout << data["choice"][language].get<std::string>() << ": ";
            int choice;
            std::cin >> choice;

            auto it = std::find_if(options.begin(), options.end(),
                                   [choice](const MenuOption &opt)
                                   { return opt.id == choice; });

            if (it != options.end())
            {
                /// @todo implement menu options
            }
            else
            {
                std::cout << "invalid choice\n";
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