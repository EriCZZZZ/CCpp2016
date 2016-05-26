#include "EnemyFighter.h"
EnemyFighter::EnemyFighter(int x, int y) : Fighter(x, y)
{
  weapon = new WeaponSingle;
  fighterOwner = FIGHTER_ENEMY;
  HP = FIGHTER_HP_MAX;
  //to create fighter appearance
  fighterGraphics.setRotation(FIGHTER_ENEMY_ROTATION);
}
std::vector<Shell *> EnemyFighter::fire()
{
  // auto newShell = new Shell;
  // newShell->setPosition(getPositionByVertex().position.x, getPositionByVertex().position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_ENEMY_Y);
  // newShell->setSpeedByVector(sf::Vector2f(x, y));
  // newShell->setOwner(fighterOwner);
  // return newShell;
  return weapon->fire(getPositionByVertex(), sf::Vector2f(SHELL_SPEED_ENEMY_X, SHELL_SPEED_ENEMY_Y), fighterOwner);
}
void EnemyFighter::move(int deltaX, int deltaY)
{
  int targetX = getPositionByVertex().position.x + deltaX;
  int targetY = getPositionByVertex().position.y + deltaY;
  fighterGraphics.move(deltaX, deltaY);
}
