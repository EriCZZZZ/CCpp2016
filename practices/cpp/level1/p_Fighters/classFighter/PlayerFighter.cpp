#include "PlayerFighter.h"
PlayerFighter::PlayerFighter(int x, int y) : Fighter(x, y)
{
  weapon = new WeaponSingle;
  fighterOwner = FIGHTER_PLAYER;
  HP = FIGHTER_HP_MAX_PLAYER;
  initializeWeapon();
  //to create fighter outlook
}
PlayerFighter::~PlayerFighter()
{
  for(auto it = weaponContainer.begin(); it != weaponContainer.end(); it++)
  {
    delete (*it);
  }
}
void PlayerFighter::initializeWeapon()
{
  Weapon *weaponSingle = new WeaponSingle;
  Weapon *weaponSpread = new WeaponSpread;
  weaponContainer.push_back(weaponSingle);
  weaponContainer.push_back(weaponSpread);
  weaponIndex = WEAPON_MODEL_NUMBER_SINGLE;
}
std::vector<Shell *> PlayerFighter::fire()
{
  return weaponContainer[weaponIndex]->fire(getPositionByVertex(), sf::Vector2f(SHELL_SPEED_PLAYER_X, SHELL_SPEED_PLAYER_Y), fighterOwner);
}
void PlayerFighter::move(int deltaX, int deltaY)
{
  fighterGraphics.move(deltaX, deltaY);
}
bool PlayerFighter::checkWeaponStatus()
{
  return weapon->checkWeaponStatus();
}
void PlayerFighter::refreshShell()
{
  weaponContainer[weaponIndex]->refreshShell();
}
void PlayerFighter::changeWeapon(int weaponIndex)
{
  PlayerFighter::weaponIndex = weaponIndex;
}
