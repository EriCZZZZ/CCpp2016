#ifndef PLAYER_FIGHTER_H
#define PLAYER_FIGHTER_H

#include "Fighter.h"
#include "../head/GameConfig.h"

class PlayerFighter : public Fighter
{
private:
  bool fighterOwner = FIGHTER_OWNER_PLAYER;
  std::vector<Weapon *> weaponContainer;
  Weapon *weapon;
  int weaponIndex;
  void initializeWeapon();
public:
  PlayerFighter(int x, int y);
  ~PlayerFighter();
  std::vector<Shell *> fire() override;
  void move(int deltaX, int deltaY);
  bool checkWeaponStatus();
  void refreshShell();
  void changeWeapon(int weaponIndex);
};
#endif
