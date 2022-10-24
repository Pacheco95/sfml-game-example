#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include "Settings.h"

TEST_SUITE_BEGIN("Settings");

const char CONFIG[] = R"(
{
  "m_antialiasingLevel": 3,
  "m_frameRateLimit": 60,
  "m_scalingFactor": 100,
  "m_gravity": -10,
  "m_velocityIterations": 8,
  "m_positionIterations": 3,
  "m_reservedGameObjects": 123
}
)";

TEST_CASE("Loading") {
    const std::string tempConfigFile = std::tmpnam(nullptr);
    std::ofstream os(tempConfigFile);
    os << CONFIG << std::endl;

    SUBCASE("it should load default settings without making copies") {
        auto &settings = Settings::load();
        CHECK((&settings == &Settings::defaults));
    }

    SUBCASE("it should load settings from file") {
        auto settings = Settings::load(tempConfigFile);
        CHECK((settings.m_reservedGameObjects == 123));
    }

    os.close();
    std::remove(tempConfigFile.c_str());
}

TEST_SUITE_END();
