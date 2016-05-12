#ifndef PLAYER_FIGHTER_H
#define PLAYER_FIGHTER_H

#include "Fighter.h"
#include "../head/GameConfig.h"

class PlayerFighter : public Fighter
{
public:
  PlayerFighter(int x, int y);
  Shell *createShell(int x = SHELL_SPEED_PLAYER_X, int y = SHELL_SPEED_PLAYER_X) override;
  void move(int deltaX, int deltaY);
};
#endif
