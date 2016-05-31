#include "WeaponSingle.h"
#include "ShellFactory.h"
#ifdef DEBUG
#include <iostream>
#endif
WeaponSingle::WeaponSingle()
{
  isShellReady = WEAPON_FIRE_RATE_SINGLE;
}
void WeaponSingle::refreshShell()
{
  if(isShellReady < WEAPON_FIRE_RATE_SINGLE)
  {
    isShellReady++;
  }
}
std::vector<Shell *> WeaponSingle::fire(sf::Vertex fighterLocation, sf::Vector2f shellSpeedDirection, int owner)
{
  std::vector<Shell *> shellContainer;
  ShellFactory *shellFactory = new ShellFactory;
  if(isShellReady == WEAPON_FIRE_RATE_SINGLE)
  {
    Shell *shell;
    isShellReady = WEAPON_RESET_SHELL_STATUS;
    if(owner == FIGHTER_OWNER_PLAYER)
    {
      shell = shellFactory->createShell(sf::Vector2f(fighterLocation.position.x, fighterLocation.position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y), shellSpeedDirection, owner);
    }
    else
    {
      shell = shellFactory->createShell(sf::Vector2f(fighterLocation.position.x, fighterLocation.position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_ENEMY_Y), shellSpeedDirection, owner);
    }
    shellContainer.push_back(shell);
  }
  return shellContainer;
}
bool WeaponSingle::checkWeaponStatus()
{
  if(isShellReady == WEAPON_FIRE_RATE_SINGLE)
  {
    return WEAPON_SHELL_IS_READY;
  }
  else
  {
    return WEAPON_SHELL_NOT_READY;
  }
}
