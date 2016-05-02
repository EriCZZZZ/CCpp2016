#include "Shell.h"
void Shell::setPosition(int indexX, int indexY)
{
  shell.setPosition(indexX, indexY);
}
void Shell::setDeltaVector(sf::Vector2f vector)
{
  deltaVector = vector;
}
void Shell::move()
{
  shell.move(deltaVector.x, deltaVector.y);
}
sf::Vertex Shell::getVertex()
{
  return shell.getPosition();
}
ShellGraphics *Shell::toDraw()
{
  return &shell;
}
