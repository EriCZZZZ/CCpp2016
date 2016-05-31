#include "WeaponSpreadSpriteGraphics.h"
WeaponSpreadSpriteGraphics::WeaponSpreadSpriteGraphics()
{
  weaponTexture.setSize(sf::Vector2f(10, 10));
  weaponTexture.setFillColor(sf::Color::Blue);
  weaponTexture.setOrigin(sf::Vector2f(5, 5));
}
void WeaponSpreadSpriteGraphics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &shellTexture;
  target.draw(weaponTexture, states);
}
