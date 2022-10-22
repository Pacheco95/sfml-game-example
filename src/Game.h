#pragma once

#include <plog/Log.h>
#include "utils.h"
#include "World.h"
#include "Window.h"

class Game {
public:
    Game();

    void start();

private:
    World m_world;
    Window m_window;
};
