#include "Game.h"

Game::Game() : m_window() {};

void Game::start() {
    configureLogger();

    static const auto handleGameLoopIteration = [this](float deltaTimeInSeconds) {
        m_world.updatePhysics(deltaTimeInSeconds);
        m_window.renderObjects(m_world.getGameObjects());
    };

    static const auto handleUserEvent = [this](const sf::Event &event) {
        if (event.type == sf::Event::Closed)
            m_window.close();

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            m_window.close();
    };

    m_window.open(handleGameLoopIteration, handleUserEvent);
}
