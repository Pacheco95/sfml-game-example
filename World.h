#pragma once

#include <vector>
#include "GameObject.h"

class World {
public:
    World();

private:
    b2World m_b2World;
    std::vector<GameObject *> m_gameObjects;
};
