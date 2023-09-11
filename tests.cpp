#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "catch_amalgamated.hpp"
#include "someclass.hpp"

TEST_CASE("Testing someclass") {
  someclass obj;

  SECTION("Testing getMember1()") {
    REQUIRE(obj.getMember1() ==
            42); // We expect member1 to be initialized to 42
  }
}
