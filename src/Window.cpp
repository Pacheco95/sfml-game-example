#include "Window.h"
#include "utils.h"

Window::Window() {
    auto title = "Bouncing Ball";
    auto videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_Window.create(videoMode, title);
    m_Window.setFramerateLimit(FRAME_RATE_LIMIT);
}

void Window::open(const std::function<void(float)> &gameLoopCallback) {
    sf::Clock clock;

    while (m_Window.isOpen()) {
        sf::Event event{};

        while (m_Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_Window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                m_Window.close();
        }

        sf::Time deltaTime = clock.restart();
        gameLoopCallback(deltaTime.asSeconds());

        m_Window.clear();
        m_Window.display();
    }
}
