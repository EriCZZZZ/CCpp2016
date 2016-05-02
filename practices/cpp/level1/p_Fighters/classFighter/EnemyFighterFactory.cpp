#include "EnemyFighterFactory.h"

Fighter *EnemyFighterFactory::createFighter(int indexX, int indexY)
{
  return new EnemyFighter(indexX, indexY);
}
