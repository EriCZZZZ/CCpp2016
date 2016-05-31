#ifndef SPRITE_WEAPON_SPREAD_H
#define SPRITE_WEAPON_SPREAD_H

#include "Sprite.h"
#include "../classGraphics/WeaponSpreadSpriteGraphics.h"

class SpriteWeaponSpread : public Sprite
{
private:
  WeaponSpreadSpriteGraphics weaponSprite;
  int spriteClass;
  sf::Vector2f speedVector;
public:
  void setOwner(int owner);
}
#endif
