#pragma once
#include "System.h"

class EventBus;

class InputSystem : public System
{
public:
    explicit InputSystem(EventBus &eventBus);

    void update(float deltaTime) override;

private:
    EventBus &eventBus;
};
