#ifndef ENEMY_FIGHTER_H
#define ENEMY_FIGHTER_H

#include "Fighter.h"

class EnemyFighter : public Fighter
{
private:
  bool fighterOwner = FIGHTER_OWNER_ENEMY;
  Weapon *weapon;
public:
  EnemyFighter(int x, int y);
  std::vector<Shell *> fire();
  void move(int deltaX, int deltaY);
  bool checkWeaponStatus();
  void refreshShell();
};
#endif
