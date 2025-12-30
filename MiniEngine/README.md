# Time Loop Mini Engine (C++ / SDL2)

A small, event-driven C++ game engine built from scratch to demonstrate
ECS architecture, system decoupling, and time-loop persistence.

## Features

- ECS-style World (Entity, Component, System)
- Event Bus (Input, Death, Quit)
- SDL2 rendering (windowed 2D)
- Player input (WASD)
- Enemy AI (patrol)
- Collision detection (AABB)
- Camera system (world → screen space)
- Time-loop reset with persistence policies

## Architecture

- **Entity**: ID only
- **Components**: Transform, Collider, Camera, Memory, Tags
- **Systems**: Input, Movement, AI, Collision, Camera, Render, Life
- **Events**: MoveEvent, DeathEvent, QuitEvent
- **Persistence**: ResetPolicy strategy (reset vs persist)

## Controls

- W/A/S/D – Move player
- Close window – Quit

## Build (macOS)

```bash
brew install sdl2
clang++ -std=c++17 *.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -o MiniEngine
./MiniEngine
```

---

## 2️⃣ Add a SHORT architecture diagram (optional but strong)

Create `ARCHITECTURE.md`:

```md
Input → EventBus → MovementSystem
AI → Enemy Movement
Collision → DeathEvent → World Reset
Camera → Render (SDL)

World owns all entities & components
Systems read/write via World API
```
