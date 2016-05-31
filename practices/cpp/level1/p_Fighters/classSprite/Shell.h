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
  void setOwner(bool owner);
  bool getOwner();
  void setPosition(int indexX, int indexY);
  void setSpeedByVector(sf::Vector2f vector);
  void move();
  // void collisionOperate(Operation *targetOperation);
  sf::Vertex getPositionByVertex();
  ShellGraphics *toDraw();
};
#endif
