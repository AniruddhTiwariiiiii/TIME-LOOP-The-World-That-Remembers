#include "InputSystem.h"
#include "EventBus.h"
#include "MoveEvent.h"
#include "QuitEvent.h"

#include <SDL2/SDL.h>

InputSystem::InputSystem(EventBus &eventBus)
    : eventBus(eventBus) {}

void InputSystem::update(float)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            eventBus.emit(QuitEvent{});
        }

        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
        {
            bool pressed = (event.type == SDL_KEYDOWN);
            float v = pressed ? 1.f : 0.f;

            switch (event.key.keysym.sym)
            {
            case SDLK_w:
                eventBus.emit(MoveEvent(0.f, -v));
                break;
            case SDLK_s:
                eventBus.emit(MoveEvent(0.f, v));
                break;
            case SDLK_a:
                eventBus.emit(MoveEvent(-v, 0.f));
                break;
            case SDLK_d:
                eventBus.emit(MoveEvent(v, 0.f));
                break;
            default:
                break;
            }
        }
    }
}
