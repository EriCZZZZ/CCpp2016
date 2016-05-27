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
    isShellReady = 0;
    auto shell = new Shell;

  }
}
