#include "SpriteWeaponSpread.h"
void SpriteWeaponSpread::setOwner(int owner)
{
  spriteClass = owner;
}
int SpriteWeaponSpread::getSpriteClass()
{
  return spriteClass;
}
void SpriteWeaponSpread::setPosition(int indexX, int indexY)
{
  weaponSprite.setPosition(indexX, indexY);
}
void SpriteWeaponSpread::setSpeedByVector(sf::Vector2f vector)
{
  speedVector = vector;
}
void SpriteWeaponSpread::move()
{
  weaponSprite.move(speedVector.x, speedVector.y);
}
sf::Vertex SpriteWeaponSpread::getPositionByVertex()
{
  return weaponSprite.getPosition();
}
WeaponSpreadSpriteGraphics *SpriteWeaponSpread::toDraw()
{
  return &weaponSprite;
}
