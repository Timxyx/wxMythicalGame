#include "unit.hpp"
#include "weapon.hpp"

Weapon sword("sword", 10, 1, Weapontype::Blade, false);
Weapon bow("bow", 5, 1, Weapontype::Pierce, true);
Weapon claws("Claws", 7, 2, Weapontype::Blade, false);
Weapon fireBreath("Fire Breath", 6, 4, Weapontype::Arcane, true);
Weapon axe("Axe", 8, 2, Weapontype::Blade, false);
Weapon hammer("Hammer", 5, 2, Weapontype::Impact, false);

std::vector<Weapon> archer_weapons = {
    sword,
    bow,
};

std::vector<Weapon> drake_weapons = {
    claws,
    fireBreath,
};

std::vector<Weapon> fighter_weapons = {
    axe,
    hammer,
};

Elvish_Archer::Elvish_Archer(std::string nme)
    : Unit(nme, "Elvish Archer", 29, 29, 6, &archer_weapons) {}

Drake_Burner::Drake_Burner(std::string nme)
    : Unit(nme, "Drake Burner", 42, 42, 5, &drake_weapons) {}

Dwarvish_Fighter::Dwarvish_Fighter(std::string nme)
    : Unit(nme, "Dwarvish Fighter", 60, 60, 4, &fighter_weapons) {}
