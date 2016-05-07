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
  newShell->setPosition(getVertex().position.x, getVertex().position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y);
  newShell->setDeltaVector(sf::Vector2f(SHELL_SPEED_PLAYER_X, SHELL_SPEED_PLAYER_Y));
  return newShell;
}
void PlayerFighter::move(int deltaX, int deltaY)
{
  fighterGraphics.move(deltaX, deltaY);
}
