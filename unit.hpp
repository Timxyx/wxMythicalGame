#ifndef UNIT_H
#define UNIT_H
#include "weapon.hpp"
#include <string>
#include <vector>

class Unit {
public:
  Unit(std::string nme, std::string typenme, uint32_t m_health,
       uint32_t current_health, uint32_t mv, std::vector<Weapon> *wp)
      : name_(nme), type_name_(typenme), max_health_(m_health),
        health_(current_health), moves_(mv), weapons_(wp) {}

  std::string name() { return name_; }
  std::string type_name() { return type_name_; }
  uint32_t max_health() { return max_health_; }
  uint32_t health() { return health_; }
  uint32_t moves() { return moves_; }
  std::vector<Weapon> *weapons() { return weapons_; }

private:
  std::string name_;
  std::string type_name_;
  uint32_t max_health_;
  uint32_t health_;
  uint32_t moves_;
  std::vector<Weapon> *weapons_;
};

class Elvish_Archer : public Unit {
public:
  Elvish_Archer(std::string nme);
};

class Dwarvish_Fighter : public Unit {
public:
  Dwarvish_Fighter(std::string nme);
};

class Drake_Burner : public Unit {
public:
  Drake_Burner(std::string nme);
};

#endif
