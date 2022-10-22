#include "World.h"
#include "utils.h"

World::World() : m_b2World(b2Vec2(0.f, GRAVITY_VERTICAL_FORCE)) {
    m_gameObjects.reserve(100);
}

std::vector<GameObject *> &World::getGameObjects() {
    return m_gameObjects;
}

void World::updatePhysics(float deltaTimeInSeconds) {
    m_b2World.Step(deltaTimeInSeconds, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}
