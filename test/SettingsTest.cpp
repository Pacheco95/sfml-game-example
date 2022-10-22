#include <catch2/catch_test_macros.hpp>

#include "../src/Settings.h"

TEST_CASE("Should load settings", "[factorial]") {
    std::string env("SETTINGS_FILE_PATH=XXX");
    putenv(env.data());

    Settings settings = Settings::load();

    auto serialized = settings.serialize();

    auto expected = std::string("");

    expected.erase(remove_if(expected.begin(), expected.end(), isspace), expected.end());

    REQUIRE(serialized == expected);
}