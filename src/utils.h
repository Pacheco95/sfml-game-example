#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>

constexpr auto WINDOW_WIDTH = 600u;
constexpr auto WINDOW_HEIGHT = 600u;
constexpr auto X_OFFSET = WINDOW_WIDTH * 0.5f;
constexpr auto Y_OFFSET = WINDOW_HEIGHT * 0.5f;
constexpr auto SCALING_FACTOR = 100.f;
constexpr auto FRAME_RATE_LIMIT = 60u;
constexpr auto GRAVITY_VERTICAL_FORCE = -10.f;
constexpr auto VELOCITY_ITERATIONS = 8u;
constexpr auto POSITION_ITERATIONS = 3u;

void configureLogger();

b2Vec2 world2screen(const b2Vec2 &world);

std::ostream &operator<<(std::ostream &os, const b2Vec2 &v);

std::ostream &operator<<(std::ostream &os, const sf::Vector2f &v);


