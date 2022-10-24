#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include "Settings.h"

TEST_SUITE_BEGIN("Settings");

constexpr char CONFIG[] = R"(
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

struct Fixture {
    std::string tempConfigFile;
    std::ofstream os;

    Fixture() : tempConfigFile(std::tmpnam(nullptr)), os(tempConfigFile) {
        os << CONFIG << std::endl;
    }

    ~Fixture() {
        os.close();
        std::remove(tempConfigFile.c_str());
    }
};


std::string &strip(std::string &str) {
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    return str;
}

TEST_CASE_FIXTURE(Fixture, "Loading") {

    SUBCASE("it should load default settings without making copies") {
        auto &settings = Settings::load();
        CHECK((&settings == &Settings::defaults));
    }

    SUBCASE("it should load settings from file") {
        auto settings = Settings::load(tempConfigFile);
        CHECK((settings.m_reservedGameObjects == 123));
    }

}

TEST_CASE_FIXTURE(Fixture, "Serializing") {

    SUBCASE("it should serialize configuration") {
        auto serialized = Settings::load(tempConfigFile).serialize();
        auto expected = std::string(CONFIG);
        CHECK((strip(serialized) == strip(expected)));
    }

}

TEST_SUITE_END();
