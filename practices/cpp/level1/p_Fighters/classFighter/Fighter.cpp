#include "Fighter.h"
Fighter::Fighter(int x, int y)
{
  fighterGraphics.setPosition(x, y);
}
void Fighter::setPoint(int index, sf::Vertex targetVertex)
{
  if(index < FIGHTER_COORDINATE_INDEX_MIN || index >= FIGHTER_COORDINATE_INDEX_MAX)
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
    HP = FIGHTER_HP_MIN;
  }
  if(HP <= FIGHTER_HP_MIN)
  {
    return COLLISION_FIGHTER_DEAD;
  }
  else
  {
    return COLLISION_FIGHTER_UNDEAD;
  }
}
