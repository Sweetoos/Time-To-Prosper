#pragma once

#include "state.h"
class MainMenuState : public State
{
private:
public:
    MainMenuState(App *app);

    void handleEvent() override;
    void update() override;
    void render() override;
};
