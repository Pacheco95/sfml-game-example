#include "Game.h"

Game::Game() : m_window() {};

void Game::start() {
    configureLogger();

    static const auto tick = [this](float deltaTimeInSeconds) {
        this->tick(deltaTimeInSeconds);
    };

    m_window.open(tick);
}
