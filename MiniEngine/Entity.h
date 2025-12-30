#pragma once

class Entity
{
public:
    explicit Entity(int id) : id(id) {}

    int getId() const { return id; }

private:
    int id;
};
