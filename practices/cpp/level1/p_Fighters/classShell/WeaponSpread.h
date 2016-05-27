#ifndef WEAPON_SPREAD_H
#define WEAPON_SPREAD_H
#include "Weapon.h"
#define SPREAD_SHELL_NUMBER 3

class WeaponSpread : public Weapon
{
public:
  WeaponSpread();
  std::vector<Shell *> fire(sf::Vertex fighterLocation, sf::Vector2f shellSpeedDirection, int owner);
  void refreshShell();
  bool checkWeaponStatus();
private:
  int model = WEAPON_MODEL_NUMBER_SPREAD;
  int isShellReady;
};
#endif
