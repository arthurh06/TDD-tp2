#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Numerais romanos válidos") {
    ConversorRomano conv;
    REQUIRE(conv.converter("I") == 1);
    REQUIRE(conv.converter("V") == 5);
    REQUIRE(conv.converter("XX") == 20);
    REQUIRE(conv.converter("IV") == 4);
    REQUIRE(conv.converter("X") == 10);
    REQUIRE(conv.converter("XXX") == 30);
    REQUIRE(conv.converter("XXV") == 25);
    REQUIRE(conv.converter("XIV") == 14);
    REQUIRE(conv.converter("II") == 2);
    REQUIRE(conv.converter("III") == 3);
}

TEST_CASE("Numerais romanos inválidos") {
    ConversorRomano conv;
    REQUIRE(conv.converter("A") == -1);
    REQUIRE(conv.converter("IIII") == -1);
    REQUIRE(conv.converter("VX") == -1);
    REQUIRE(conv.converter("MMMD") == -1);
}