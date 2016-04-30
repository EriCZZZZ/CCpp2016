#include "PlayerFighterFactory.h"

Fighter *PlayerFighterFactory::createFighter(int indexX, int indexY)
{
  return new PlayerFighter(indexX, indexY);
}
