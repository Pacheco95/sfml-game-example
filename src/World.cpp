#include "World.h"
#include "utils.h"

World::World() : m_b2World(b2Vec2_zero) {
    const auto &settings = getSettings();
    m_b2World.SetGravity(b2Vec2(0.f, settings.m_gravity));
    m_gameObjects.reserve(settings.m_reservedGameObjects);
}

std::vector<GameObject *> &World::getGameObjects() {
    return m_gameObjects;
}

void World::updatePhysics(float deltaTimeInSeconds) {
    const auto &settings = getSettings();
    auto velocityIterations = static_cast<int>(settings.m_velocityIterations);
    auto positionIterations = static_cast<int>(settings.m_positionIterations);
    m_b2World.Step(deltaTimeInSeconds, velocityIterations, positionIterations);
}

b2Body *World::CreateBody(b2BodyDef &bodyDef) {
    return m_b2World.CreateBody(&bodyDef);
}

void World::addGameObject(GameObject *gameObject) {
    m_gameObjects.push_back(gameObject);
}
