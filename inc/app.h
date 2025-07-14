#pragma once
#include <string>
#include "stateMachine.h"

class App
{
private:
    unsigned int height;
    unsigned int width;
    std::string language;
    StateMachine stateMachine;

public:
    App();
    void launch();
    void CreateDefaultSettings();
    void ReadDefaultSettings();
};
