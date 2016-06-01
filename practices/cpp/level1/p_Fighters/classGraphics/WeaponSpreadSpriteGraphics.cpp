#include "WeaponSpreadSpriteGraphics.h"
WeaponSpreadSpriteGraphics::WeaponSpreadSpriteGraphics()
{
  weaponSprite.setSize(sf::Vector2f(10, 10));
  weaponSprite.setFillColor(sf::Color::Blue);
  weaponSprite.setOrigin(sf::Vector2f(5, 5));
}
void WeaponSpreadSpriteGraphics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &weaponTexture;
  target.draw(weaponSprite, states);
}
