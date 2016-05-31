#include "EnemyFighter.h"
EnemyFighter::EnemyFighter(int x, int y) : Fighter(x, y)
{
  weapon = new WeaponSingle;
  fighterOwner = FIGHTER_OWNER_ENEMY;
  HP = FIGHTER_HP_MAX_ENEMY;
  //to create fighter appearance
  fighterGraphics.setRotation(FIGHTER_ENEMY_ROTATION);
}
std::vector<Shell *> EnemyFighter::fire()
{
  return weapon->fire(getPositionByVertex(), sf::Vector2f(SHELL_SPEED_ENEMY_X, SHELL_SPEED_ENEMY_Y), fighterOwner);
}
void EnemyFighter::move(int deltaX, int deltaY)
{
  fighterGraphics.move(deltaX, deltaY);
}
bool EnemyFighter::checkWeaponStatus()
{
  return weapon->checkWeaponStatus();
}
void EnemyFighter::refreshShell()
{
  weapon->refreshShell();
}
void EnemyFighter::changeWeapon(int weaponIndex)
{
  ;
}
