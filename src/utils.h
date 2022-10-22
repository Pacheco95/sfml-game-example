#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>

constexpr auto WINDOW_WIDTH = 800u;
constexpr auto WINDOW_HEIGHT = 800u;
constexpr auto X_OFFSET = WINDOW_WIDTH * 0.5f;
constexpr auto Y_OFFSET = WINDOW_HEIGHT * 0.5f;
constexpr auto SCALING_FACTOR = 100.f;
constexpr auto FRAME_RATE_LIMIT = 0u;
constexpr auto GRAVITY_VERTICAL_FORCE = -10.f;
constexpr auto VELOCITY_ITERATIONS = 8u;
constexpr auto POSITION_ITERATIONS = 3u;
constexpr auto RESERVED_GAME_OBJECTS = 1000u;

void configureLogger();

b2Vec2 worldToScreen(const b2Vec2 &world);

template<typename T>
b2Vec2 screenToWorld(const sf::Vector2<T> &screen);

std::ostream &operator<<(std::ostream &os, const b2Vec2 &v);

std::ostream &operator<<(std::ostream &os, const sf::Vector2f &v);

template<typename T>
b2Vec2 screenToWorld(const sf::Vector2<T> &screen) {
    auto x = (screen.x - X_OFFSET) / SCALING_FACTOR;
    auto y = -(screen.y - Y_OFFSET) / SCALING_FACTOR;
    return {x, y};
}