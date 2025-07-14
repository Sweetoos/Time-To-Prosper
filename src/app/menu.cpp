#include "menu.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem;

void Run()
{
    try
    {
        if(!fs::exists("local"))
            fs::create_directory("local");

        std::ifstream menuFile("local/menu.json");
        if (!menuFile.is_open())
        {
            throw std::runtime_error(
                "Couldn't read menu.json file\t func: Run");
        }
        json data;
        menuFile >> data;

        const std::string language = "en";
        const unsigned int width = 1920;
        const unsigned int height = 1080;
        std::cout << data["menu"]["title"][width][height][language];

        // while (runnable)
        //{
        // DisplayMenu();
        //}
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return;
    }
}
