#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>

constexpr auto SCALING_FACTOR = 100;
constexpr auto WINDOW_WIDTH = 600;
constexpr auto WINDOW_HEIGHT = 600;
constexpr auto X_OFFSET = WINDOW_WIDTH * 0.5f;
constexpr auto Y_OFFSET = WINDOW_HEIGHT * 0.5f;

b2Vec2 world2screen(const b2Vec2 &world);

std::ostream &operator<<(std::ostream &os, const b2Vec2 &v);

std::ostream &operator<<(std::ostream &os, const sf::Vector2f &v);

