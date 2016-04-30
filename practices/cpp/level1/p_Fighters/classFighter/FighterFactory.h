#ifndef FIGHTER_FACTORY_H
#define FIGHTER_FACTORY_H

#include "Fighter.h"

class FighterFactory
{
public:
  virtual Fighter *createFighter(int indexX, int indexY) = 0;
};
#endif
