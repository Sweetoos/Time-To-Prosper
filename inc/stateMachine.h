#pragma once
#include <memory>
#include "state.h"
#include <vector>
#include <memory>

class StateMachine
{
private:
    std::vector<std::unique_ptr<State>> states;
    std::unique_ptr<State> new_state;
    bool toDelete=false;
    bool toReplace=false;

public:
    void addState(std::unique_ptr<State>newState);
    void deleteState();

    void updateState();
    State* getActiveState();
};
