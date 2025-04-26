#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Números romanos válidos") {
    ConversorRomano conv;
    REQUIRE(conv.converter("I") == 1);
    REQUIRE(conv.converter("V") == 5);
    REQUIRE(conv.converter("XX") == 20);

}