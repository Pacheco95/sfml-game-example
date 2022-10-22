#include "Game.h"

Game::Game() : m_window() {};

void Game::start() {
    configureLogger();

    static const auto handleGameLoopIteration = [this](float deltaTimeInSeconds) {
        m_world.updatePhysics(deltaTimeInSeconds);

        m_window.asSFMLWindow().clear();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            auto screenPosition = sf::Mouse::getPosition(m_window.asSFMLWindow());

            auto worldPosition = screenToWorld(screenPosition);

            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            bodyDef.position = worldPosition;
            b2Body *body = m_world.CreateBody(bodyDef);

            b2PolygonShape b2shape;
            b2shape.SetAsBox(0.1f, 0.1f);

            b2FixtureDef fixtureDef;
            fixtureDef.shape = &b2shape;
            fixtureDef.density = 0.01f;
            fixtureDef.friction = 0.0f;
            fixtureDef.restitution = 1.0f;
            auto fixture = body->CreateFixture(&fixtureDef);

            auto square = new GameObject(fixture);
            square->setFillColor(sf::Color::Red);

            m_world.addGameObject(square);
        }

        for (const auto &gameObject: m_world.getGameObjects()) {
            gameObject->updatePhysics();
            m_window.asSFMLWindow().draw(*gameObject);
        }

        m_window.asSFMLWindow().display();
    };

    static const auto handleUserEvent = [this](const sf::Event &event) {
        if (event.type == sf::Event::Closed)
            m_window.asSFMLWindow().close();

        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    m_window.asSFMLWindow().close();
                    break;

                default:
                    break;
            }
        }
    };

    m_window.openAndBlockUntilClosed(handleGameLoopIteration, handleUserEvent);

    for (const auto &gameObject: m_world.getGameObjects()) {
        delete gameObject;
    }

    LOGD << " GameObjects instanciados: " << m_world.getGameObjects().size();
}
