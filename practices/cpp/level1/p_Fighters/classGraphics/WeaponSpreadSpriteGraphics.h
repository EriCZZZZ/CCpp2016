#ifndef WEAPON_SPREAD_SPRITE_GRAPHICS_H
#define WEAPON_SPREAD_SPRITE_GRAPHICS_H
#include "ElementGraphics.h"
#include "../head/GameConfig.h"

class WeaponSpreadSpriteGraphics : public ElementGraphics
{
private:
  sf::Texture weaponTexture;
  sf::RectangleShape weaponSprite;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
  WeaponSpreadSpriteGraphics();
};
#endif
