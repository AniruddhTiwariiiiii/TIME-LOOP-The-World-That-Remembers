#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include "Entity.h"
#include "Transform.h"
#include "Memory.h"
#include "Collider.h"
#include "EnemyTag.h"
#include "PlayerTag.h"
#include "Camera.h"

class System;
class ResetPolicy;

class World
{
public:
    World();
    ~World();

    EnemyTag &addEnemy(Entity &entity);
    EnemyTag *getEnemy(Entity &entity);

    // -------- Entity --------
    Entity &createEntity();
    std::vector<Entity> &getEntities();

    // -------- Transform Component --------
    Transform &addTransform(Entity &entity);
    Transform *getTransform(Entity &entity);

    // -------- Collider Component --------
    Collider &addCollider(Entity &entity, float w, float h);
    Collider *getCollider(Entity &entity);

    // -------- Memory Component (Time Loop) --------
    Memory &addMemory(Entity &entity, std::unique_ptr<ResetPolicy> policy);
    Memory *getMemory(Entity &entity);

    // --------- Player Tags ------------------------
    PlayerTag &addPlayer(Entity &entity);
    PlayerTag *getPlayer(Entity &entity);

    // ---------- Camera Component ------------------
    Camera &addCamera(Entity &entity);
    Camera *getCamera(Entity &entity);

    // -------- Systems --------
    void addSystem(std::unique_ptr<System> system);
    void update(float deltaTime);

    // -------- Time Loop --------
    void resetWorld();

private:
    int nextEntityId;

    // -------- ECS storage --------
    std::vector<Entity> entities;
    std::unordered_map<int, Transform> transforms;
    std::unordered_map<int, Collider> colliders;
    std::unordered_map<int, Memory> memories;
    std::unordered_map<int, EnemyTag> enemies;
    std::unordered_map<int, PlayerTag> players;
    std::unordered_map<int, Camera> cameras;

    // -------- Systems --------
    std::vector<std::unique_ptr<System>> systems;
};
