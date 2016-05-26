#ifndef WEAPON_H
#define WEAPON_H
#include "Shell.h"
#include "../head/GameConfig.h"
#include <vector>
class Weapon
{
public:
  virtual std::vector<Shell *> fire(sf::Vertex fighterLocation, sf::Vector2f shellSpeedDirection, int owner) = 0;
};
#endif
