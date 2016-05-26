#include "PlayerFighter.h"
PlayerFighter::PlayerFighter(int x, int y) : Fighter(x, y)
{
  weapon = new WeaponSingle;
  fighterOwner = FIGHTER_PLAYER;
  HP = FIGHTER_HP_MAX;
  //to create fighter outlook
}
std::vector<Shell *> PlayerFighter::fire()
{
  // auto newShell = new Shell;
  // newShell->setPosition(getPositionByVertex().position.x, getPositionByVertex().position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y);
  // newShell->setSpeedByVector(sf::Vector2f(x, y));
  // newShell->setOwner(fighterOwner);
  // return newShell;
  return weapon->fire(getPositionByVertex(), sf::Vector2f(SHELL_SPEED_PLAYER_X, SHELL_SPEED_PLAYER_Y), fighterOwner);
}
void PlayerFighter::move(int deltaX, int deltaY)
{
  fighterGraphics.move(deltaX, deltaY);
}
