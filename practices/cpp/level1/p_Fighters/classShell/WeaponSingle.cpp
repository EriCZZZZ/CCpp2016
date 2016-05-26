#include "WeaponSingle.h"
#include <vector>
// void WeaponSingle::fire(sf::Vertex fighterLocation, sf::Vertex shellSpeedDirection, int owner)
std::vector<Shell *> WeaponSingle::fire(sf::Vertex fighterLocation, sf::Vector2f shellSpeedDirection, int owner)
{
  std::vector<Shell *> shellContainer;
  auto shell = new Shell;
  shell->setPosition(fighterLocation.position.x, fighterLocation.position.y);
  shell->setSpeedByVector(shellSpeedDirection);
  shell->setOwner(owner);

  shellContainer.push_back(shell);
  return shellContainer;
}
