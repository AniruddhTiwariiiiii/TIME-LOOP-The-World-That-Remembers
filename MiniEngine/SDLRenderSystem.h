#pragma once
#include "System.h"

struct SDL_Window;
struct SDL_Renderer;

class World;

class SDLRenderSystem : public System
{
public:
    explicit SDLRenderSystem(World &world);
    ~SDLRenderSystem();

    void update(float deltaTime) override;

private:
    World &world;

    SDL_Window *window;
    SDL_Renderer *renderer;
};
