#include "WeaponSpread.h"
WeaponSpread::WeaponSpread()
{
  isShellReady = WEAPON_FIRE_RATE_SPREAD;
}
void WeaponSpread::refreshShell()
{
  if(isShellReady < WEAPON_FIRE_RATE_SPREAD)
  {
      isShellReady++;
  }
}
std::vector<Shell *> WeaponSpread::fire(sf::Vertex fighterLocation, sf::Vector2f shellSpeedDirection, int owner)
{
  std::vector<Shell *> shellContainer;
  if(isShellReady == WEAPON_FIRE_RATE_SPREAD)
  {
    auto shellFactory = new ShellFactory;
    isShellReady = WEAPON_RESET_SHELL_STATUS;
    auto shell1 = shellFactory->createShell(sf::Vector2f(fighterLocation.position.x, fighterLocation.position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y), shellSpeedDirection, owner);
    auto shell2 = shellFactory->createShell(sf::Vector2f(fighterLocation.position.x, fighterLocation.position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y), sf::Vector2f(SPREAD_SHELL_SPEED_X_2, shellSpeedDirection.y), owner);
    auto shell3 = shellFactory->createShell(sf::Vector2f(fighterLocation.position.x, fighterLocation.position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y), sf::Vector2f(SPREAD_SHELL_SPEED_X_3, shellSpeedDirection.y), owner);
    shellContainer.push_back(shell1);
    shellContainer.push_back(shell2);
    shellContainer.push_back(shell3);
    delete shellFactory;
  }
  return shellContainer;
}
bool WeaponSpread::checkWeaponStatus()
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
