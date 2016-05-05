#include "EnemyFighter.h"
EnemyFighter::EnemyFighter(int x, int y) : Fighter(x, y)
{
  fighterOwner = FIGHTER_ENEMY;
  HP = FIGHTER_HP_MAX;
  //to create fighter outlook
  fighterGraphics.setRotation(180);
}
Shell *EnemyFighter::createShell()
{
  auto newShell = new Shell;
  newShell->setPosition(getVertex().position.x, getVertex().position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_ENEMY_Y);
  newShell->setDeltaVector(sf::Vector2f(0, 3));
  return newShell;
}
void EnemyFighter::move(int deltaX, int deltaY)
{
  int targetX = getVertex().position.x + deltaX;
  int targetY = getVertex().position.y + deltaY;
  if(targetX < 0)
  {
    fighterGraphics.move(-getVertex().position.x, 0);
  }
  else if(targetX > 1000)
  {
    fighterGraphics.move(1000 - getVertex().position.x, 0);
  }
  else
  {
    fighterGraphics.move(deltaX, 0);
  }
  if(targetY < 0)
  {
    fighterGraphics.move(0, -getVertex().position.y);
  }
  else if(targetX > 700)
  {
    fighterGraphics.move(0, 700 - getVertex().position.y);
  }
  else
  {
    fighterGraphics.move(0, deltaY);
  }
}
