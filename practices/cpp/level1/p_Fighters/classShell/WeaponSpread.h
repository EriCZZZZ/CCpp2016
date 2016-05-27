#ifndef WEAPON_SPREAD_H
#define WEAPON_SPREAD_H
#include "Weapon.h"
#define SPREAD_SHELL_NUMBER 3
#define SPREAD_SHELL_SPEED_X_2 -1
#define SPREAD_SHELL_SPEED_X_3 1

class WeaponSpread : public Weapon
{
public:
  WeaponSpread();
  std::vector<Shell *> fire(sf::Vertex fighterLocation, sf::Vector2f shellSpeedDirection, int owner);
  void refreshShell();
  bool checkWeaponStatus();
private:
  int model = WEAPON_MODEL_NUMBER_SPREAD;
  int isShellReady = WEAPON_SHELL_IS_READY;
};
#endif
