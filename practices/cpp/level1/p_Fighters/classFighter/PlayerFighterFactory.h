#ifndef PLAYER_FIGHTER_FACTORY_H
#define PLAYER_FIGHTER_FACTORY_H

#include "FighterFactory.h"
#include "PlayerFighter.h"

class PlayerFighterFactory
{
public:
  Fighter *createFighter(int indexX, int indexY);
};
#endif
