#include "ShellFactory.h"
Shell *ShellFactory::createShell(sf::Vector2f shellPosition, sf::Vector2f shellSpeedDirection, int owner)
{
  Shell *newShell = new Shell;
  newShell->setPosition(shellPosition.x, shellPosition.y);
  newShell->setSpeedByVector(shellSpeedDirection);
  newShell->setOwner(owner);

  return newShell;
}
