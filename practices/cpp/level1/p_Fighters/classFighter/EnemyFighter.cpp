#include "EnemyFighter.h"
EnemyFighter::EnemyFighter(int x, int y) : Fighter(x, y)
{
  fighterOwner = FIGHTER_ENEMY;
  HP = FIGHTER_HP_MAX;
  //to create fighter appearance
  fighterGraphics.setRotation(FIGHTER_ENEMY_ROTATION);
}
Shell *EnemyFighter::createShell(int x, int y)
{
  auto newShell = new Shell;
  newShell->setPosition(getVertex().position.x, getVertex().position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_ENEMY_Y);
  newShell->setDeltaVector(sf::Vector2f(x, y));
  return newShell;
}
void EnemyFighter::move(int deltaX, int deltaY)
{
  int targetX = getVertex().position.x + deltaX;
  int targetY = getVertex().position.y + deltaY;
  fighterGraphics.move(deltaX, deltaY);
}
