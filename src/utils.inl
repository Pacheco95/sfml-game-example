template<typename T>
b2Vec2 screenToWorld(const sf::Vector2<T> &screen) {
    auto x = (screen.x - X_OFFSET) / SCALING_FACTOR;
    auto y = -(screen.y - Y_OFFSET) / SCALING_FACTOR;
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

