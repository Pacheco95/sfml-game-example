#include <fstream>
#include "Settings.h"
#include "utils.h"
#include <cstdlib>
#include <plog/Log.h>

Settings Settings::defaults = {
        .m_antialiasingLevel = 3,
        .m_frameRateLimit = 60,
        .m_scalingFactor = 100,
        .m_gravity = -10.f,
        .m_velocityIterations = 8,
        .m_positionIterations = 3,
        .m_reservedGameObjects = 10000
};

Settings &Settings::load() {
    static bool cached = false;
    auto &settings = Settings::defaults;

    if (cached)
        return settings;

    cached = true;

    if (auto path = std::getenv(SETTINGS_FILE_PATH_ENV_NAME)) {
        try {
            settings = load(path);
            LOGD << "Settings loaded from " << path;
        } catch (daw::json::v3_1_0::json_exception &exception) {
            LOGE << "Failed to load settings from" << path << ". Using defaults: " << exception.what();
        }
    } else {
        LOGD << "Settings file not provided or not found. Using defaults.";
    }

    return settings;
}

Settings Settings::load(const std::string &path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();

    auto fileContent = buffer.str();
    auto settings = daw::json::from_json<Settings>(fileContent);

    return settings;
}

std::string Settings::serialize() const {
    using namespace daw::json::options;
    auto flags = output_flags<SerializationFormat::Pretty>;
    auto serialized = daw::json::to_json(*this, flags);
    return serialized;
}

const b2Vec2 &Settings::getScreenOffset() {
    static const auto &videoMode = Settings::getVideoMode();
    static const auto &xOffset = static_cast<float>(videoMode.width) / 2.f;
    static const auto &yOffset = static_cast<float>(videoMode.height) / 2.f;
    static const auto offset = b2Vec2(xOffset, yOffset);
    return offset;
}

sf::VideoMode &Settings::getVideoMode() {
    static sf::VideoMode videoMode = sf::VideoMode::getFullscreenModes().front();
    return videoMode;
}

const sf::ContextSettings &Settings::getContextSettings() const {
    static const sf::ContextSettings contextSettings(0, 0, this->m_antialiasingLevel);
    return contextSettings;
}
