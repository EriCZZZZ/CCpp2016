#ifndef ENEMY_FIGHTER_FACTORY_H
#define ENEMY_FIGHTER_FACTORY_H

#include "FighterFactory.h"
#include "EnemyFighter.h"

class EnemyFighterFactory : public FighterFactory
{
public:
  Fighter *createFighter(int indexX, int indexY);
};
#endif
