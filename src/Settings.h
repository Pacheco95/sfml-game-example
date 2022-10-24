#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "daw/json/daw_json_link.h"

struct Settings {
    [[nodiscard]] const sf::ContextSettings &getContextSettings() const;

    static sf::VideoMode &getVideoMode();

    static const b2Vec2 &getScreenOffset();

    static Settings &load();

    static Settings load(const std::string &path);

    static Settings defaults;

    bool operator==(const Settings &other) const;

    [[nodiscard]] std::string serialize() const;

    uint m_antialiasingLevel;
    uint m_frameRateLimit;
    float m_scalingFactor;
    float m_gravity;
    uint m_velocityIterations;
    uint m_positionIterations;
    uint m_reservedGameObjects;
};

namespace daw::json {
    template<>
    struct json_data_contract<Settings> {
        using type = json_member_list<
                json_number<"m_antialiasingLevel", uint>,
                json_number<"m_frameRateLimit", uint>,
                json_number<"m_scalingFactor", float>,
                json_number<"m_gravity", float>,
                json_number<"m_velocityIterations", uint>,
                json_number<"m_positionIterations", uint>,
                json_number<"m_reservedGameObjects", uint>
        >;

        static inline auto to_json_data(Settings const &value) {
            return std::forward_as_tuple(
                    value.m_antialiasingLevel,
                    value.m_frameRateLimit,
                    value.m_scalingFactor,
                    value.m_gravity,
                    value.m_velocityIterations,
                    value.m_positionIterations,
                    value.m_reservedGameObjects
            );
        }
    };
}

