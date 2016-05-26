#ifndef WEAPON_SINGLE_H
#define WEAPON_SINGLE_H
#include "Weapon.h"
class WeaponSingle : public Weapon
{
public:
  std::vector<Shell *> fire(sf::Vertex fighterLocation, sf::Vector2f shellSpeedDirection, int owner);
private:
  int model = WEAPON_MODEL_NUMBER_SINGLE;
};
#endif