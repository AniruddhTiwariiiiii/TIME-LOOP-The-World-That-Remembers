#pragma once

class Entity;
class World;

class ResetPolicy
{
public:
    virtual void reset(World &world, Entity &entity) = 0;
    virtual ~ResetPolicy() = default;
};
