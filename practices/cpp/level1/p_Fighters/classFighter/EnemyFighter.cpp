#include "EnemyFighter.h"
EnemyFighter::EnemyFighter(int x, int y) : Fighter(x, y)
{
  fighterOwner = FIGHTER_ENEMY;
  HP = FIGHTER_HP_MAX;
  //to create fighter outlook
  fighterGraphics.setRotation(FIGHTER_ENEMY_ROTATION);
}
Shell *EnemyFighter::createShell()
{
  auto newShell = new Shell;
  newShell->setPosition(getVertex().position.x, getVertex().position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_ENEMY_Y);
  newShell->setDeltaVector(sf::Vector2f(SHELL_SPEED_ENEMY_X, SHELL_SPEED_ENEMY_Y));
  return newShell;
}
void EnemyFighter::move(int deltaX, int deltaY)
{
  int targetX = getVertex().position.x + deltaX;
  int targetY = getVertex().position.y + deltaY;
  fighterGraphics.move(deltaX, deltaY);
}
