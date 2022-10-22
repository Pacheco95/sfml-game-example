#include "Settings.h"

template<typename T>
b2Vec2 screenToWorld(const sf::Vector2<T> &screen) {
    const auto &settings = Settings::load();

    const auto &offset = settings.getScreenOffset();
    const auto &factor = settings.m_scalingFactor;

    auto x = (screen.x - offset.x) / factor;
    auto y = -(screen.y - offset.y) / factor;

    return {x, y};
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const sf::Vector2<T> &v) {
    return os << "[" << v.x << ", " << v.y << "]" << std::endl;
}

template<typename R, typename G, typename B>
sf::Color rgb(R r, G g, B b) {
    return {static_cast<sf::Uint8>(r), static_cast<sf::Uint8>(g), static_cast<sf::Uint8>(b)};
}

