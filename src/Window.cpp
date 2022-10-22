#include "Window.h"
#include "utils.h"

Window::Window() {
    auto title = "Bouncing Ball";
    const auto settings = getSettings();
    const auto &videoMode = Settings::getVideoMode();
    const auto &contextSettings = settings.getContextSettings();
    m_Window.create(videoMode, title, sf::Style::Default, contextSettings);
    m_Window.setFramerateLimit(settings.m_frameRateLimit);
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
