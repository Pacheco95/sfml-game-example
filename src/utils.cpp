#include <random>

#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

#include "utils.h"

void configureLogger() {
    static plog::ColorConsoleAppender<plog::TxtFormatter> appender;
    plog::init(plog::debug, &appender);
}

b2Vec2 worldToScreen(const b2Vec2 &world) {
    return {world.x * SCALING_FACTOR + X_OFFSET, -world.y * SCALING_FACTOR + Y_OFFSET};
}

std::ostream &operator<<(std::ostream &os, const b2Vec2 &v) {
    return os << "[" << v.x << ", " << v.y << "]" << std::endl;
}

sf::Color getRandomColor() {
    static std::random_device dev;
    static std::mt19937 intRng(dev());
    static std::uniform_int_distribution<std::mt19937::result_type> dist(0, 359);
    auto hue = dist(intRng);
    return hsv(hue, 1, 1);
}

sf::Color hsv(unsigned int hue, float sat, float val) {
    hue %= 360;

    sat = b2Clamp(sat, 0.f, 1.f);
    val = b2Clamp(val, 0.f, 1.f);

    int h = (int) hue / 60;
    float f = float(hue) / 60 - (float) h;
    float p = val * (1.f - sat);
    float q = val * (1.f - sat * f);
    float t = val * (1.f - sat * (1 - f));

    using sf::Uint8;

    switch (h) {
        default:
        case 0:
        case 6:
            return rgb(val * 255, t * 255, p * 255);
        case 1:
            return rgb(q * 255, val * 255, p * 255);
        case 2:
            return rgb(p * 255, val * 255, t * 255);
        case 3:
            return rgb(p * 255, q * 255, val * 255);
        case 4:
            return rgb(t * 255, p * 255, val * 255);
        case 5:
            return rgb(val * 255, p * 255, q * 255);
    }
}
