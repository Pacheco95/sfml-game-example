#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

class Window {
public:
    void open(const std::function<void(float)> &gameLoopCallback);

    Window();

private:
    sf::RenderWindow m_Window;
};