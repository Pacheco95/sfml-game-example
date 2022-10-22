#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>
#include "Settings.h"

#define getSettings loadSettings

constexpr char SETTINGS_FILE_PATH_ENV_NAME[] = "SETTINGS_FILE_PATH";

void configureLogger();

Settings &loadSettings();

b2Vec2 worldToScreen(const b2Vec2 &world);

template<typename T>
b2Vec2 screenToWorld(const sf::Vector2<T> &screen);

std::ostream &operator<<(std::ostream &os, const b2Vec2 &v);

template<typename T>
std::ostream &operator<<(std::ostream &os, const sf::Vector2<T> &v);

sf::Color getRandomColor();

sf::Color hsv(unsigned int hue, float sat, float val);

#include "utils.inl"
