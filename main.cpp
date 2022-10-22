#include "src/Game.h"

int main() {
    configureLogger();
    loadSettings();

    Game game;
    game.start();

    return 0;
}