#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "utils.h"

size_t GameObject::getPointCount() const {
    return m_sfmlShape->getPointCount();
}

sf::Vector2f GameObject::getPoint(std::size_t index) const {
    return m_sfmlShape->getPoint(index);
}

GameObject::GameObject(b2Fixture *fixture) : m_fixture(fixture), m_body(fixture->GetBody()) {
    (void) m_fixture;
    m_b2shape = dynamic_cast<b2PolygonShape *>(fixture->GetShape());
    m_sfmlShape = std::make_unique<sf::ConvexShape>(m_b2shape->m_count);
}

void GameObject::updatePhysics() {
    for (auto i = 0; i < m_b2shape->m_count; i++) {
        auto localPoint = m_b2shape->m_vertices[i];
        auto worldPoint = m_body->GetWorldPoint(localPoint);
        auto screenPoint = world2screen(worldPoint);
        m_sfmlShape->setPoint(i, sf::Vector2f(screenPoint.x, screenPoint.y));
    }

    update();
}
