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
  return weapon->fire(getPositionByVertex(), sf::Vector2f(SHELL_SPEED_PLAYER_X, SHELL_SPEED_PLAYER_Y), fighterOwner);
}
void PlayerFighter::move(int deltaX, int deltaY)
{
  fighterGraphics.move(deltaX, deltaY);
}
