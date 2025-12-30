#include "LifeSystem.h"
#include "EventBus.h"
#include "DeathEvent.h"
#include <iostream>

LifeSystem::LifeSystem(World &world, EventBus &eventBus)
    : world(world), eventBus(eventBus), framesAlive(0) {}

void LifeSystem::update(float)
{
    framesAlive++;

    if (framesAlive == 3)
    {
        std::cout << "💀 Player died\n";
        eventBus.emit(DeathEvent{});
        framesAlive = 0;
    }
}
