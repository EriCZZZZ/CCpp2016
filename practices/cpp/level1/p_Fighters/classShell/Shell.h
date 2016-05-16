#ifndef SHELL_H
#define SHELL_H

#include "../classGraphics/ShellGraphics.h"
#include "../head/GameConfig.h"

class Shell
{
private:
  ShellGraphics shell;
  sf::Vector2f deltaVector;
public:
  void setPosition(int indexX, int indexY);
  void setVByVector(sf::Vector2f vector);
  void move();
  sf::Vertex getVertex();
  ShellGraphics *toDraw();
};
#endif
