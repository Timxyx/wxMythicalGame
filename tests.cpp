#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "catch_amalgamated.hpp"
// #include "someclass.hpp"
#include "unit.hpp"
#include <iostream>

TEST_CASE("Testing units") {

  SECTION("Testing if units are initialized correctly") {
    // REQUIRE(obj.getMember1() ==
    //         42); // We expect member1 to be initialized to 42
    Elvish_Archer *archer = new Elvish_Archer("Archer");
    Dwarvish_Fighter *fighter = new Dwarvish_Fighter("Fighter");
    Drake_Burner *burner = new Drake_Burner("Burner");
    // std::cout << archer->max_health() << std::endl;

    REQUIRE(archer->max_health() == 29);
    REQUIRE(fighter->max_health() == 60);
    REQUIRE(burner->max_health() == 42);
  }
}

TEST_CASE("Testing weapons") {

  SECTION("Testing if the weapons are initialized correctly") {

    Weapon sword("sword", 10, 1, Weapontype::Blade, false);
    Weapon bow("bow", 5, 1, Weapontype::Pierce, true);
    Weapon claws("Claws", 7, 2, Weapontype::Blade, false);

    REQUIRE(sword.damage() == 10);
    REQUIRE(bow.is_ranged() == true);
    REQUIRE(claws.strikes() == 2);
  }
}
