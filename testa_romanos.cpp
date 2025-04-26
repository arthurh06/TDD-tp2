#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Verificacao de números romanos") {
    ConversorRomano conv;
    REQUIRE(conv.converter("I") == 1);
    REQUIRE(conv.converter("V") == 5);
    REQUIRE(conv.converter("XX") == 20);
    REQUIRE(conv.converter("IV") == 4);
    REQUIRE(conv.converter("x") == 10);
    REQUIRE(conv.converter("A") == -1);
    REQUIRE(conv.converter("IIII") == -1);
    REQUIRE(conv.converter("VX") == -1);
    REQUIRE(conv.converter("MMMD") == -1);




}