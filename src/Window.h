#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

typedef const std::function<void(float)> GameLoopCallback;
typedef const std::function<void(const sf::Event &)> EventHandlerCallback;

class Window {
public:
    void open(GameLoopCallback &gameLoopCallback, EventHandlerCallback &eventHandlerCallback);

    Window();

    void renderObjects(const std::vector<GameObject *> &gameObjects);

    void close();

private:
    sf::RenderWindow m_Window;
};