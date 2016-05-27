#ifndef SHELL_FACTORY_H
#define SHELL_FACTORY_H
#include "Shell.h"
class ShellFactory
{
public:
  Shell *createShell(sf::Vector2f shellPosition, sf::Vector2f shellSpeedDirection, int owner);
};
#endif
