#include "PlayerFighter.h"
PlayerFighter::PlayerFighter(int x, int y) : Fighter(x, y)
{
  fighterOwner = FIGHTER_PLAYER;
  HP = FIGHTER_HP_MAX;
  //to create fighter outlook
}
Shell *PlayerFighter::fire(int x, int y)
{
  auto newShell = new Shell;
  newShell->setPosition(getPositionByVertex().position.x, getPositionByVertex().position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y);
  newShell->setSpeedByVector(sf::Vector2f(x, y));
  newShell->setOwner(fighterOwner);
  return newShell;
}
void PlayerFighter::move(int deltaX, int deltaY)
{
  fighterGraphics.move(deltaX, deltaY);
}
