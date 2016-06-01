#ifndef SPRITE_WEAPON_SPREAD_H
#define SPRITE_WEAPON_SPREAD_H

#include "Sprite.h"
#include "../classGraphics/WeaponSpreadSpriteGraphics.h"

class SpriteWeaponSpread : public Sprite
{
private:
  WeaponSpreadSpriteGraphics weaponSprite;
  int spriteClass = SPRITE_WEAPON_SPREAD;
  sf::Vector2f speedVector = sf::Vector2f(0, 3);
public:
  void setOwner(int owner);
  int getSpriteClass();
  void setPosition(int indexX, int indexY);
  void setSpeedByVector(sf::Vector2f vector);
  void move();
  sf::Vertex getPositionByVertex();
  WeaponSpreadSpriteGraphics *toDraw();
};
#endif
