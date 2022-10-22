#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

typedef const std::function<void(float)> GameLoopCallback;
typedef const std::function<void(const sf::Event &)> EventHandlerCallback;

class Window {
public:
    void openAndBlockUntilClosed(GameLoopCallback &gameLoopCallback, EventHandlerCallback &eventHandlerCallback);

    Window();

    sf::RenderWindow &asSFMLWindow();

private:
    sf::RenderWindow m_Window;
};