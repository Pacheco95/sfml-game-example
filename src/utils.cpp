#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

#include "utils.h"

void configureLogger() {
    static plog::ColorConsoleAppender<plog::TxtFormatter> appender;
    plog::init(plog::debug, &appender);
}

b2Vec2 world2screen(const b2Vec2 &world) {
    return {world.x * SCALING_FACTOR + X_OFFSET, -world.y * SCALING_FACTOR + Y_OFFSET};
}

std::ostream &operator<<(std::ostream &os, const b2Vec2 &v) {
    return os << "[" << v.x << ", " << v.y << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const sf::Vector2f &v) {
    return os << "[" << v.x << ", " << v.y << "]" << std::endl;
}
