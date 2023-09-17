#ifndef WEAPON_H
#define WEAPON_H
#include <string>

enum class Weapontype { Arcane, Blade, Cold, Impact, Pierce };

class Weapon {
public:
  Weapon(std::string nme, uint32_t damage, uint32_t strikes, Weapontype type,
         bool ranged)
      : name_(nme), damage_(damage), strikes_(strikes), type_(type),
        is_ranged_(ranged) {}

  std::string name() { return name_; }
  uint32_t damage() { return damage_; }
  uint32_t strikes() { return strikes_; }
  Weapontype type() { return type_; }
  bool is_ranged() { return is_ranged_; }

private:
  std::string name_;
  uint32_t damage_;
  uint32_t strikes_;
  Weapontype type_;
  bool is_ranged_;
};

class Axe : public Weapon {
public:
  Axe();
};

#endif
