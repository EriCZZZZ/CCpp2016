#include "Fighter.h"
Fighter::Fighter(int x, int y)
{
  fighterGraphics.setPosition(x, y);
}
void Fighter::designAppearanceByPoint(int index, sf::Vertex targetVertex)
{
  if(index < FIGHTER_COORDINATE_INDEX_MIN || index >= FIGHTER_COORDINATE_INDEX_MAX)
  {
    return;
  }
  else
  {
    fighterGraphics.designAppearanceByPoint(index, targetVertex);
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
void Fighter::reviseHP(int deltaHP)
{
  HP += deltaHP;
  if(HP <= FIGHTER_HP_MIN)
  {
    HP = FIGHTER_HP_MIN;
  }
}
bool Fighter::isFighterDie()
{
  if(HP <= FIGHTER_HP_MIN)
  {
    return COLLISION_FIGHTER_DEAD;
  }
  else
  {
    return COLLISION_FIGHTER_UNDEAD;
  }
}
