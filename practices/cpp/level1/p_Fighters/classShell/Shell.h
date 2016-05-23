#ifndef SHELL_H
#define SHELL_H

#include "../classGraphics/ShellGraphics.h"
#include "../head/GameConfig.h"

class Shell
{
private:
  ShellGraphics shell;
  bool shellOwner;
  sf::Vector2f deltaVector;
public:
  void setPosition(int indexX, int indexY);
  void setSpeedByVector(sf::Vector2f vector);
  void move();
  sf::Vertex getPositionByVertex();
  ShellGraphics *toDraw();
};
#endif
