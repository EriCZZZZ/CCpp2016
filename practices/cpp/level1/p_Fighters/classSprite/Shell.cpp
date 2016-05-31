#include "Shell.h"
void Shell::setOwner(int owner)
{
  shellOwner = owner;
}
int Shell::getSpriteClass()
{
  return shellOwner;
}
void Shell::setPosition(int indexX, int indexY)
{
  shell.setPosition(indexX, indexY);
}
void Shell::setSpeedByVector(sf::Vector2f vector)
{
  speedVector = vector;
}
void Shell::move()
{
  shell.move(deltaVector.x, deltaVector.y);
}
sf::Vertex Shell::getPositionByVertex()
{
  return shell.getPosition();
}
ShellGraphics *Shell::toDraw()
{
  return &shell;
}
