#include "WeaponSingle.h"
#include <vector>
// void WeaponSingle::fire(sf::Vertex fighterLocation, sf::Vertex shellSpeedDirection, int owner)
std::vector<Shell *> WeaponSingle::fire(sf::Vertex fighterLocation, sf::Vector2f shellSpeedDirection, int owner)
{
  std::vector<Shell *> shellContainer;
  auto shell = new Shell;
  if(owner == FIGHTER_OWNER_PLAYER)
    shell->setPosition(fighterLocation.position.x, fighterLocation.position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_PLAYER_Y);
  else
    shell->setPosition(fighterLocation.position.x, fighterLocation.position.y + FIGHTER_CREATE_SHELL_CORRECTED_VALUE_ENEMY_Y);
  shell->setSpeedByVector(shellSpeedDirection);
  shell->setOwner(owner);

  shellContainer.push_back(shell);
  return shellContainer;
}
