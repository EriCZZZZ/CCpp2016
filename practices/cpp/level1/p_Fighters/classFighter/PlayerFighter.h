#ifndef PLAYER_FIGHTER_H
#define PLAYER_FIGHTER_H

#include "Fighter.h"

class PlayerFighter : public Fighter
{
public:
  PlayerFighter(int x, int y);
  Shell *createShell() override;
  void move(int deltaX, int deltaY);
};
#endif
