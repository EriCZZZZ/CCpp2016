#include "WeaponSingle.h"
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
  if(isShellReady == WEAPON_FIRE_RATE_SINGLE)
  {
    isShellReady = 0;
    auto shell = new Shell;
    if(owner == FIGHTER_OWNER_PLAYER)
    {
      shell->setPosition(fighterLocation.position.x, fighterLocation.position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y);
    }
    else
    {
      shell->setPosition(fighterLocation.position.x, fighterLocation.position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_ENEMY_Y);
    }
    shell->setSpeedByVector(shellSpeedDirection);
    shell->setOwner(owner);

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
