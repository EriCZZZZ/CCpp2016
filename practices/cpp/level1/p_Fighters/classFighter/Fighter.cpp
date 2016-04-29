#include "Fighter.h"
void Fighter::setPoint(int index, sf::Vertex targetVertex)
{
  if(index < 0 || index - 1 >= FIGHTER_COORDINATE_NUMBER)
  {
    return;
  }
  else
  {
    fighterGraphics.setPoint(index, targetVertex);
    return;
  }
}
void Fighter::setPostion(int indexX, int indexY)
{
  fighterGraphics.setPostion(indexX, indexY);
}
sf::Vertex Fighter::getVertex()
{
  return fighterGraphics.getPosition();
}
FighterGraphics *toDraw()
{
  return &FighterGraphics;
}
void Fighter::reviseHP(int deltaHP)
{
  if(HP >= deltaHP)
  {
    HP -= deltaHP;
  }
  else
  {
    HP = 0;
  }
}
