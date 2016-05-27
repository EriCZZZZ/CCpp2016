#ifndef FIGHTER_H
#define FIGHTER_H

#include "../head/GameConfig.h"
#include "../classGraphics/FighterGraphics.h"
#include "../classShell/Shell.h"
#include "../classShell/Weapon.h"
#include "../classShell/WeaponSingle.h"
#include "../classShell/WeaponSpread.h"
#include <vector>

class Fighter
{
protected:
  bool fighterOwner;
  unsigned HP;
  FighterGraphics fighterGraphics;
private:
  void setPosition(int indexX, int indexY);
public:
  Fighter(int x, int y);
  virtual std::vector<Shell *> fire() = 0;
  virtual void move(int deltaX, int deltaY) = 0;
  virtual bool checkWeaponStatus() = 0;
  virtual void refreshShell() = 0;
  virtual void changeWeapon(int weaponIndex) = 0;
  sf::Vertex getPositionByVertex();
  FighterGraphics *toDraw();
  void reviseHP(int deltaHP);
  unsigned getHP(void);
  bool isFighterDie();
};
#endif
