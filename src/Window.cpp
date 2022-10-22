#include "Window.h"
#include "utils.h"

Window::Window() {
    auto title = "Bouncing Ball";
    auto videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_Window.create(videoMode, title);
    m_Window.setFramerateLimit(FRAME_RATE_LIMIT);
}

void Window::open(GameLoopCallback &gameLoopCallback, EventHandlerCallback &eventHandlerCallback) {
    sf::Clock clock;

    while (m_Window.isOpen()) {
        sf::Event event{};

        while (m_Window.pollEvent(event)) {
            eventHandlerCallback(event);
        }

        sf::Time deltaTime = clock.restart();
        gameLoopCallback(deltaTime.asSeconds());
    }
}

void Window::renderObjects(const std::vector<GameObject *> &gameObjects) {
    m_Window.clear();
    m_Window.display();
}

void Window::close() {
    m_Window.close();
}
