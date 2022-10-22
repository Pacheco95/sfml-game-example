#pragma once

#include <vector>
#include "GameObject.h"

class World {
public:
    World();

    std::vector<GameObject *> &getGameObjects();

    void updatePhysics(float deltaTimeInSeconds);

private:
    b2World m_b2World;
    std::vector<GameObject *> m_gameObjects;
};
