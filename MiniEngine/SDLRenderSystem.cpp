#include "SDLRenderSystem.h"
#include "World.h"
#include "Transform.h"
#include "Entity.h"
#include "Camera.h"

#include <SDL2/SDL.h>
#include <iostream>

SDLRenderSystem::SDLRenderSystem(World &world)
    : world(world), window(nullptr), renderer(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL Init Failed\n";
        return;
    }

    window = SDL_CreateWindow(
        "Time Loop Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDLRenderSystem::~SDLRenderSystem()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLRenderSystem::update(float)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    // -------- Find active camera (player camera) --------
    Camera *cam = nullptr;
    for (Entity &e : world.getEntities())
    {
        cam = world.getCamera(e);
        if (cam)
            break;
    }

    float camX = cam ? cam->x : 0.f;
    float camY = cam ? cam->y : 0.f;

    // -------- Render entities relative to camera --------
    for (Entity &entity : world.getEntities())
    {
        Transform *t = world.getTransform(entity);
        if (!t)
            continue;

        SDL_Rect rect;
        rect.x = static_cast<int>(t->x - camX);
        rect.y = static_cast<int>(t->y - camY);
        rect.w = 20;
        rect.h = 20;

        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);
}
