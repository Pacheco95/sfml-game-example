#include <plog/Log.h>
#include "Window.h"
#include "utils.h"

Window::Window() {
    auto title = "Bouncing Ball";

    sf::ContextSettings contextSettings(0, 0, ANTIALIASING_LEVEL);
    sf::VideoMode videoMode = sf::VideoMode::getFullscreenModes().front();
    m_Window.create(videoMode, title, sf::Style::Default, contextSettings);
    m_Window.setFramerateLimit(FRAME_RATE_LIMIT);
}

void Window::openAndBlockUntilClosed(GameLoopCallback &gameLoopCallback, EventHandlerCallback &eventHandlerCallback) {
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

sf::RenderWindow &Window::asSFMLWindow() {
    return m_Window;
}
