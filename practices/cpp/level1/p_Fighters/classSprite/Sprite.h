#ifndef SPRITE_H
#define SPRITE_H
#include "../head/GameConfig.h"
#include "../classGraphics/ElementGraphics.h"
#include <SFML/Graphics.hpp>

class Sprite
{
public:
  virtual void setOwner(int owner) = 0;
  virtual int getSpriteClass() = 0;
  virtual void setPosition(int indexX, int indexY) = 0;
  virtual void setSpeedByVector(sf::Vector2f vector) = 0;
  virtual void move() = 0;
  virtual sf::Vertex getPositionByVertex() = 0;
  virtual ElementGraphics *toDraw() = 0;
};
#endif
