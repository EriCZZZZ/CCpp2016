#ifndef SHELL_H
#define SHELL_H

#include "Sprite.h"
#include "../classGraphics/ShellGraphics.h"

class Shell : public Sprite
{
private:
  ShellGraphics shell;
  int shellOwner;
  sf::Vector2f speedVector;
public:
  void setOwner(int owner);
  int getSpriteClass();
  void setPosition(int indexX, int indexY);
  void setSpeedByVector(sf::Vector2f vector);
  void move();
  sf::Vertex getPositionByVertex();
  ShellGraphics *toDraw();
};
#endif
