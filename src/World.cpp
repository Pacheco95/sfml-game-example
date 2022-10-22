#include "World.h"
#include "utils.h"

World::World() : m_b2World(b2Vec2(0.f, GRAVITY_VERTICAL_FORCE)) {
    m_gameObjects.reserve(RESERVED_GAME_OBJECTS);
}

std::vector<GameObject *> &World::getGameObjects() {
    return m_gameObjects;
}

void World::updatePhysics(float deltaTimeInSeconds) {
    m_b2World.Step(deltaTimeInSeconds, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}

b2Body *World::CreateBody(b2BodyDef &bodyDef) {
    return m_b2World.CreateBody(&bodyDef);
}

void World::addGameObject(GameObject *gameObject) {
    m_gameObjects.push_back(gameObject);
}
