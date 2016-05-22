#include "Fighter.h"
Fighter::Fighter(int x, int y)
{
  fighterGraphics.setPosition(x, y);
}
void Fighter::setPosition(int indexX, int indexY)
{
  fighterGraphics.setPosition(indexX, indexY);
}
sf::Vertex Fighter::getPositionByVertex()
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
