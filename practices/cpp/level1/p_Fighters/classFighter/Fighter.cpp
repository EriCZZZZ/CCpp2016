#include "Fighter.h"
Fighter::Fighter(int x, int y)
{
  fighterGraphics.setPosition(x, y);
}
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
void Fighter::setPosition(int indexX, int indexY)
{
  fighterGraphics.setPosition(indexX, indexY);
}
sf::Vertex Fighter::getVertex()
{
  return fighterGraphics.getPosition();
}
FighterGraphics *Fighter::toDraw()
{
  return &fighterGraphics;
}
bool Fighter::reviseHP(int deltaHP)
{
  if(HP >= deltaHP)
  {
    HP += deltaHP;
  }
  else
  {
    HP = 0;
  }
  if(HP <= 0)
  {
    return COLLISION_FIGHTER_DEAD;
  }
  else
  {
    return COLLISION_FIGHTER_UNDEAD;
  }
}
