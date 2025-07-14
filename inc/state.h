#pragma once

class App;

class State
{
public:
    virtual ~State() = default;

    virtual void handleEvent() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

protected:
    App *app;
};
