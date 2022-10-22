#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class GameObject : public sf::Shape {
public:
    explicit GameObject(b2Fixture *fixture);

    ~GameObject() override = default;

    size_t getPointCount() const override;

    sf::Vector2f getPoint(std::size_t index) const override;

    void updatePhysics();

private:
    b2PolygonShape *m_b2shape;
    b2Body *m_body;
    b2Fixture *m_fixture;
    std::unique_ptr<sf::ConvexShape> m_sfmlShape;
};
