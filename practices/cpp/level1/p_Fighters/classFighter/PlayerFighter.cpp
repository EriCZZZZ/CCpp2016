#include "PlayerFighter.h"
PlayerFighter::PlayerFighter(int x, int y) : Fighter(x, y)
{
  fighterOwner = FIGHTER_PLAYER;
  HP = FIGHTER_HP_MAX;
  //to create fighter outlook
}
Shell *PlayerFighter::createShell()
{
  auto newShell = new Shell;
  newShell->setPosition(getVertex().position.x + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_X, getVertex().position.y);
  newShell->setDeltaVector(sf::Vector2f(0, -1));
  return newShell;
}
void PlayerFighter::move(int deltaX, int deltaY)
{
  int targetX = getVertex().position.x + deltaX;
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
}
