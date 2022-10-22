#pragma once

#include <vector>
#include "GameObject.h"

class World {
public:
    World();

    std::vector<GameObject *> &getGameObjects();

    void updatePhysics(float deltaTimeInSeconds);

    b2Body *CreateBody(b2BodyDef &bodyDef);

    void addGameObject(GameObject *gameObject);

private:
    b2World m_b2World;
    std::vector<GameObject *> m_gameObjects;
};
