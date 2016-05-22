#ifndef ENEMY_FIGHTER_H
#define ENEMY_FIGHTER_H

#include "Fighter.h"

class EnemyFighter : public Fighter
{
public:
  EnemyFighter(int x, int y);
  Shell *fire(int x, int y);
  void move(int deltaX, int deltaY);
};
#endif
